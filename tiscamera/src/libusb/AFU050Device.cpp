/*
 * Copyright 2017 The Imaging Source Europe GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "AFU050Device.h"

#include "UsbHandler.h"
#include "UsbSession.h"

#include "logging.h"
#include "standard_properties.h"
#include "format.h"
#include "afu050_definitions.h"

#include <algorithm>
#include <cstring>

#include <fstream>
#include <unistd.h>

using namespace tcam;


tcam::AFU050Device::AFU050Device (const DeviceInfo& info)
{
    device = info;

    usb_device_ = UsbHandler::get_instance().open_device_(info.get_serial());

    // LibusbDevice tracks open interfaces and closes them automatically
    if (!usb_device_->open_interface(0))
    {
        tcam_error("Failed to open camera interface - %d. \n"
                   "Please check device permissions!", 0);
    }

    if (!usb_device_->open_interface(1))
    {
        tcam_error("Failed to open camera interface - %d. \n"
                   "Please check device permissions!", 1);
    }
    property_handler = std::make_shared<AFU050PropertyHandler>(this);

    create_properties();
    create_formats();
}

tcam::AFU050Device::~AFU050Device ()
{
    stop_stream();
}


void tcam::AFU050Device::lost_device ()
{
    device_is_lost = true;

    if (device_is_lost)
    {
        return;
    }

    stop_stream();

    notify_device_lost();
}


DeviceInfo tcam::AFU050Device::get_device_description () const
{
    return device;
}


void AFU050Device::create_formats ()
{

    // typedef enum
    // {
    // AFU050_FMT_2592X1944 = 1,
    // AFU050_FMT_1920X1080 = 2,
    // AFU050_FMT_1280X960 = 3
    // }afu050_video_format_t;

    struct tcam_video_format_description desc = {};

    desc.fourcc = FOURCC_MJPG;
    memcpy(desc.description, fourcc2description(desc.fourcc), sizeof(desc.description));

    std::vector<struct framerate_mapping> rf;

    auto add_res = [&rf] (int width, int height, double fps)
        {
            struct tcam_resolution_description res = {};
            res.type = TCAM_RESOLUTION_TYPE_FIXED;
            res.min_size.width = width;
            res.min_size.height = height;
            res.max_size.width = width;
            res.max_size.height = height;

            std::vector<double> f;
            f.push_back(fps);

            framerate_mapping r = { res, f };
            rf.push_back(r);
        };

    add_res(2592, 1944, 15.0);
    add_res(1920, 1080, 30.0);
    add_res(1280, 960, 60.0);

    VideoFormatDescription format(nullptr, desc, rf);
    available_videoformats.push_back(format);
}


void AFU050Device::create_properties ()
{
    add_int(TCAM_PROPERTY_EXPOSURE, VC_UNIT_INPUT_TERMINAL, CT_EXPOSURE_TIME_ABSOLUTE_CONTROL);
    add_bool(TCAM_PROPERTY_EXPOSURE_AUTO, VC_UNIT_EXTENSION_UNIT, XU_AUTO_EXPOSURE);

    add_int(TCAM_PROPERTY_GAIN, VC_UNIT_PROCESSING_UNIT, PU_GAIN_CONTROL);
    add_bool(TCAM_PROPERTY_GAIN_AUTO, VC_UNIT_EXTENSION_UNIT, XU_AUTO_GAIN);

    add_bool(TCAM_PROPERTY_FOCUS_ONE_PUSH, VC_UNIT_EXTENSION_UNIT, XU_FOCUS_ONE_PUSH);

    add_int(TCAM_PROPERTY_WB_RED, VC_UNIT_EXTENSION_UNIT, XU_GAIN_R_CONTROL);
    add_int(TCAM_PROPERTY_WB_GREEN, VC_UNIT_EXTENSION_UNIT, XU_GAIN_G_CONTROL);
    add_int(TCAM_PROPERTY_WB_BLUE, VC_UNIT_EXTENSION_UNIT, XU_GAIN_B_CONTROL);
    add_bool(TCAM_PROPERTY_WB_AUTO, VC_UNIT_EXTENSION_UNIT, XU_AUTO_WHITE_BALANCE);

    add_int(TCAM_PROPERTY_SATURATION, VC_UNIT_PROCESSING_UNIT, PU_SATURATION_CONTROL);
    add_int(TCAM_PROPERTY_CONTRAST, VC_UNIT_PROCESSING_UNIT, PU_CONTRAST_CONTROL);
    add_int(TCAM_PROPERTY_SHARPNESS, VC_UNIT_PROCESSING_UNIT, PU_SHARPNESS_CONTROL);

    // add_int(TCAM_PROPERTY_FOCUS_X, VC_UNIT_EXTENSION_UNIT, PU_);
    // add_int(TCAM_PROPERTY_FOCUS_Y, VC_UNIT_EXTENSION_UNIT, PU_);

}


std::vector<std::shared_ptr<Property>> tcam::AFU050Device::getProperties ()
{
    return property_handler->create_property_vector();
}


bool tcam::AFU050Device::set_property (const Property& p)
{
    return property_handler->set_property(p);
}


bool tcam::AFU050Device::get_property (Property& p)
{
    return property_handler->get_property(p);
}


bool tcam::AFU050Device::set_video_format (const VideoFormat& format)
{
    if (is_stream_on)
    {
        tcam_log(TCAM_LOG_ERROR, "Unable to set format. Stream is running.");
        return false;
    }
    // {
    // AFU050_FMT_2592X1944 = 1,
    // AFU050_FMT_1920X1080 = 2,
    // AFU050_FMT_1280X960 = 3
    // }afu050_video_format_t;

    auto get_format_index = [] (const VideoFormat& _format)
        {
            auto s = _format.get_struct();
            if (s.width == 2592 && s.height == 1944 && s.framerate == 15.0)
            {
                return 1;
            }
            else if (s.width == 1920 && s.height == 1080 && s.framerate == 30.0)
            {
                return 2;
            }
            else if (s.width == 1280 && s.height == 960 && s.framerate == 60.0)
            {
                return 3;
            }
            else
            {
                return -1;
            }
        };

    int index = get_format_index(format);

    if (index == -1)
    {
        tcam_log(TCAM_LOG_ERROR, "Format is not supported. %s", format.to_string().c_str());
        return false;
    }
    active_video_format = format;
    if (set_video_format(0, index, 0) > 0)
        return true;
    else
        return false;
}


bool tcam::AFU050Device::validate_video_format (const VideoFormat&) const
{
    return false;
}


VideoFormat tcam::AFU050Device::get_active_video_format () const
{
    // TODO: set when initializing device;
    return active_video_format;
}


std::vector<VideoFormatDescription> tcam::AFU050Device::get_available_video_formats ()
{
    return available_videoformats;
}


bool tcam::AFU050Device::set_framerate (double framerate __attribute__((unused)))
{
    return false;
}


double tcam::AFU050Device::get_framerate ()
{
    return active_video_format.get_framerate();
}


bool tcam::AFU050Device::set_sink (std::shared_ptr<SinkInterface> s)
{
    listener = s;
    return true;
}


bool tcam::AFU050Device::initialize_buffers (std::vector<std::shared_ptr<ImageBuffer>> buffs)
{
    tcam_log(TCAM_LOG_INFO, "Received %d buffer from external allocator.", buffs.size());

    buffers.reserve(buffs.size());

    for (auto& b : buffs)
    {
        buffers.push_back({b, false});
    }
    return true;
}


void tcam::AFU050Device::init_buffers ()
{
    static const int num_buffers = 10;

    buffers.clear();
    buffers.reserve(num_buffers);

    struct tcam_image_buffer b = {};

    b.format = active_video_format.get_struct();

    for (unsigned int i = 0; i < num_buffers; ++i)
    {
        b.pData = (unsigned char*)malloc(JPEGBUF_SIZE);
        b.size = JPEGBUF_SIZE;

        buffers.push_back({std::make_shared<ImageBuffer>(b, true), false});
    }
}


bool tcam::AFU050Device::release_buffers ()
{
    buffers.clear();
    return true;
}


void tcam::AFU050Device::requeue_buffer (std::shared_ptr<ImageBuffer> buf)
{
    for (auto& b : buffers)
    {
        if (b.buffer->get_data() == buf->get_data())
        {
            b.is_queued = true;
        }
    }
}


void tcam::AFU050Device::transfer_callback (struct libusb_transfer* transfer)
{
    if (transfer->status != LIBUSB_TRANSFER_COMPLETED)
    {
        if (transfer->status == LIBUSB_TRANSFER_CANCELLED)
        {
            tcam_debug("FREE");
            libusb_free_transfer(transfer);
        }
        else if (transfer->status == LIBUSB_TRANSFER_NO_DEVICE)
        {
            lost_device();
            libusb_free_transfer(transfer);
            return;
        }
        tcam_error("libusb transfer returned with: %d", transfer->status);
    }

    if (!is_stream_on)
    {
        libusb_free_transfer(transfer);
        return;
    }

    int processed = 0;

    unsigned char* ptr = transfer->buffer;

    std::shared_ptr<tcam::ImageBuffer> buffer = nullptr;
    buffer = buffers.at(current_buffer).buffer;

    while (processed < transfer->actual_length)
    {
        if (!jpegbuf)
        {
            unsigned char* start_of_image =
                (unsigned char*)memmem(ptr + processed,
                                       ( transfer->actual_length - processed),
                                       "\xff\xd8", 2);
            if (start_of_image)
            {
                if (!jpegbuf)
                {
                    jpegbuf = (unsigned char*) malloc(JPEGBUF_SIZE);
                }

                processed = start_of_image - transfer->buffer;
                memcpy(jpegbuf, start_of_image, 2);
                processed += 2;
                jpegsize += 2;
                jpegptr += 2;
            }
        }

        if (jpegbuf)
        {
            unsigned char* end_of_image = (unsigned char*)memmem(ptr + processed,
                                                                 transfer->actual_length - processed,
                                                                 "\xff\xd9", 2);
            int cplen = transfer->actual_length - processed;

            if (end_of_image)
            {
                cplen = (((end_of_image) - ptr) - processed) + 2;
            }

            if ((jpegsize + cplen) > JPEGBUF_SIZE)
            {
                tcam_error("Image is to big. Dropping...");
                //JPEG too big, dropping
                jpegptr = 0;
                jpegsize = 0;
                //free(jpegbuf);
                jpegbuf = 0;
                break;
            }

            memcpy(jpegbuf + jpegptr,
                   ptr + processed,
                   cplen);
            processed += cplen;
            jpegptr += cplen;
            jpegsize += cplen;

            if (end_of_image)
            {

                current_buffer++;
                if (current_buffer >= buffers.size())
                {
                    current_buffer = 0;
                }

                auto b = buffer->getImageBuffer();
                memcpy(b.pData, jpegbuf, jpegsize);
                b.length = jpegsize;
                b.size = jpegsize;
                statistics.frame_count++;
                buffer->set_statistics(statistics);
                buffer->set_image_buffer(b);

                jpegptr = 0;
                jpegsize = 0;

                if (auto sink_ptr = listener.lock())
                {
                    sink_ptr->push_image(buffer);
                }
                else
                {
                    tcam_log(TCAM_LOG_ERROR, "ImageSink expired. Unable to deliver images.");
                }
                free(jpegbuf);
                jpegbuf = 0;
            }
        }
        else
        {
            processed += transfer->actual_length;
        }
    }

    if (is_stream_on)
    {
         //submit the next transfer
        int ret = libusb_submit_transfer(transfer);
        if (ret == LIBUSB_ERROR_NO_DEVICE)
        {
            lost_device();
        }
    }
    else
    {
        libusb_free_transfer(transfer);
    }
}

void LIBUSB_CALL tcam::AFU050Device::libusb_bulk_callback (struct libusb_transfer* trans)
{
    AFU050Device* self = reinterpret_cast<AFU050Device*>(trans->user_data);
    self->transfer_callback(trans);
}


bool tcam::AFU050Device::start_stream ()
{
#define USB_ENDPOINT_IN (LIBUSB_ENDPOINT_IN | 2)


    if (is_stream_on)
    {
        tcam_log(TCAM_LOG_ERROR, "Unable to start stream. Stream is already running.");
        return false;
    }

    tcam_log(TCAM_LOG_INFO, "Starting stream...");
    current_buffer = 0;
    stop_all = false;
    is_stream_on = true;
    jpegbuf = nullptr;
    jpegsize = 0;
    jpegptr = 0;


    for (int cnt = 0; cnt < TRANSFER_COUNT; cnt++)
    {
        uint8_t* buf = (uint8_t*)malloc(LEN_IN_BUFFER);

        struct libusb_transfer* transfer_in = libusb_alloc_transfer(0);
        libusb_fill_bulk_transfer( transfer_in,
                                   usb_device_->get_handle(),
                                   USB_ENDPOINT_IN,
                                   buf,
                                   LEN_IN_BUFFER,
                                   AFU050Device::libusb_bulk_callback,
                                   this,
                                   0);

        //submit the transfer, all following transfers are initiated from the CB
        int ret = libusb_submit_transfer(transfer_in);
        if (ret < 0)
        {
            if (ret == LIBUSB_ERROR_NO_DEVICE)
            {
                lost_device();
            }

            tcam_debug("ret < 0");
            break;
        }

        transfers.push_back(transfer_in);
    }

    return true;
}


bool tcam::AFU050Device::stop_stream ()
{
    stop_all = true;
    is_stream_on = false;

    //sleep(1);
    // if (work_thread.joinable())
    //     work_thread.join();

    release_buffers();
    return true;
}


void AFU050Device::add_int (const TCAM_PROPERTY_ID id, const VC_UNIT unit, const unsigned char prop)
{
    if (id == TCAM_PROPERTY_INVALID || unit == VC_UNIT_HEADER || prop == 0)
    {
        return;
    }

    tcam_debug("adding int %d %d %d", id, unit, prop);

    struct tcam_device_property p = tcam::create_empty_property(id);
    p.value.i.value = get_int_value(unit, prop, GET_CUR);
    p.value.i.default_value = get_int_value(unit, prop, GET_DEF);
    p.value.i.min = get_int_value(unit, prop, GET_MIN);
    p.value.i.max = get_int_value(unit, prop, GET_MAX);
    p.value.i.step = get_int_value(unit, prop, GET_RES);
    std::shared_ptr<Property> property = std::make_shared<PropertyInteger>(this->property_handler, p, Property::INTEGER);
    this->property_handler->properties.push_back({unit, prop, property});
}


void AFU050Device::add_bool (TCAM_PROPERTY_ID id, VC_UNIT unit, unsigned char prop)
{
    if (id == TCAM_PROPERTY_INVALID || unit == VC_UNIT_HEADER || prop == 0)
    {
        return;
    }

    struct tcam_device_property p = tcam::create_empty_property(id);
    p.value.i.value = get_bool_value(unit, prop, GET_CUR);
    p.value.i.default_value = get_bool_value(unit, prop, GET_DEF);
    std::shared_ptr<Property> property = std::make_shared<PropertyBoolean>(this->property_handler, p, Property::INTEGER);
    this->property_handler->properties.push_back({unit, prop, property});
}


bool AFU050Device::update_property (property_description& desc)
{
    if (desc.prop->get_type() == TCAM_PROPERTY_TYPE_INTEGER)
    {
        (std::static_pointer_cast<PropertyInteger>(desc.prop))->set_value(get_int_value(desc.unit, desc.id, GET_CUR));
    }
    else if (desc.prop->get_type() == TCAM_PROPERTY_TYPE_BOOLEAN)
    {
        (std::static_pointer_cast<PropertyBoolean>(desc.prop))->set_value(get_int_value(desc.unit, desc.id, GET_CUR));
    }
    else
    {
        return false;
    }
    return true;
}


bool AFU050Device::set_control (int unit,
                                int ctrl,
                                int len,
                                unsigned char* value)
{
    int ret = libusb_control_transfer(usb_device_->get_handle(),
                                      LIBUSB_ENDPOINT_OUT |
                                      LIBUSB_REQUEST_TYPE_CLASS |
                                      LIBUSB_RECIPIENT_DEVICE,
                                      UVC_SET_CUR,
                                      ctrl << 8,
                                      unit << 8,
                                      value, len, 10000 );

    if (ret == LIBUSB_ERROR_NO_DEVICE)
    {
        lost_device();
    }

    return (ret == len ? true : false);
}


bool AFU050Device::get_control (int unit,
                                int ctrl,
                                int len,
                                unsigned char* value,
                                enum CONTROL_CMD cmd)
{
    int ret = libusb_control_transfer(usb_device_->get_handle(),
                                      LIBUSB_ENDPOINT_IN |
                                      LIBUSB_REQUEST_TYPE_CLASS |
                                      LIBUSB_RECIPIENT_DEVICE,
                                      cmd,
                                      ctrl << 8,
                                      unit << 8,
                                      value, len, 10000);

    if (ret == LIBUSB_ERROR_NO_DEVICE)
    {
        lost_device();
    }

    if (len == ret)
    {
        return true;
    }
    return false;
}


int AFU050Device::set_video_format (uint8_t format_index,
                                    uint8_t frame_index,
                                    uint32_t frame_interval)
{
    int ret;
    uint8_t buf[34];

    memset(buf, 0x0, sizeof(buf));

    buf[2] = format_index;
    buf[3] = frame_index;
    buf[4] = frame_interval & 0xff;
    buf[5] = (frame_interval >> 8) & 0xff;
    buf[6] = (frame_interval >> 16) & 0xff;
    buf[7] = (frame_interval >> 24) & 0xff;

    ret = libusb_control_transfer(usb_device_->get_handle(),
                                  LIBUSB_ENDPOINT_OUT |
                                  LIBUSB_REQUEST_TYPE_CLASS |
                                  LIBUSB_RECIPIENT_INTERFACE,
                                  UVC_SET_CUR,
                                  0x2 << 8, // VS_COMMIT
                                  1,
                                  buf, sizeof(buf), 10000);
// frame_interval = buf[4] | ((uint32_t)buf[5]<<8) | ((uint32_t)buf[6]<<16) | ((uint32_t)buf[7]<<24);

    if (ret == LIBUSB_ERROR_NO_DEVICE)
    {
        lost_device();
    }

    tcam_log(TCAM_LOG_DEBUG, "set_video_format transfer ended with %d", ret);

    return ret;
}


bool AFU050Device::get_bool_value (enum VC_UNIT unit, unsigned char property, enum CONTROL_CMD cmd)
{
    int value = 0;
    bool ret = get_control(unit,
                           property,
                           4,
                           (unsigned char*)&value,
                           cmd);
    if (ret)
        tcam_log(TCAM_LOG_ERROR, "get_control returned with: %d", ret);
    return (value ? 1: 0);
}


bool AFU050Device::set_bool_value (enum VC_UNIT unit, unsigned char property, bool value)
{
    char val = (value ? 1 : 0);
    bool ret = set_control(unit,
                           property,
                           4,
                           (unsigned char*)&val);
    if (!ret)
        tcam_log(TCAM_LOG_ERROR, "set_control returned with: %d", ret);
    return ret;
}


int AFU050Device::get_int_value (const enum VC_UNIT unit, const unsigned char property, const enum CONTROL_CMD cmd)
{
    int value = 0;
    bool ret = get_control(unit,
                           property,
                           4,
                           (unsigned char*)&value,
                           cmd);
    if (!ret)
        tcam_log(TCAM_LOG_ERROR, "get_control returned with: %d", ret);
    return value;
}


bool AFU050Device::set_int_value (enum VC_UNIT unit, unsigned char property, int value)
{
    bool ret = set_control(unit,
                           property,
                           4,
                           (unsigned char*)&value);
    if (!ret)
        tcam_log(TCAM_LOG_ERROR, "set_control returned with: %d", ret);
    return ret;
}
