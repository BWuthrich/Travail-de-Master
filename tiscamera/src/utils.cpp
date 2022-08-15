/*
 * Copyright 2014 The Imaging Source Europe GmbH
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

#include "utils.h"

#include "internal.h"
#include <fstream>
#include <algorithm>
#include <cstring>
#include <sys/ioctl.h>
#include <errno.h>
#include <limits>
#include <cmath>
#include <cstring>
#include <signal.h> // kill

using namespace tcam;

std::string tcam::propertyType2String (TCAM_PROPERTY_TYPE type)
{
    switch (type)
    {
        case TCAM_PROPERTY_TYPE_BOOLEAN: return "boolean";
        case TCAM_PROPERTY_TYPE_INTEGER: return "integer";
        case TCAM_PROPERTY_TYPE_DOUBLE: return "double";
        case TCAM_PROPERTY_TYPE_STRING: return "string";
        case TCAM_PROPERTY_TYPE_ENUMERATION: return "enum";
        case TCAM_PROPERTY_TYPE_BUTTON: return "button";
        case TCAM_PROPERTY_TYPE_UNKNOWN: return "unknown";
        default:
            return "<UNKNOWN ENUM ENTRY>";
    }
}


std::vector<std::string> tcam::split_string (const std::string& to_split, const std::string &delim)
{
    std::vector<std::string> vec;

    size_t beg = 0;
    size_t end = 0;

    while (end != std::string::npos)
    {
        end = to_split.find_first_of(delim, beg);

        std::string s = to_split.substr(beg, end - beg);

        vec.push_back(s);

        beg = end + delim.size();
    }

    return vec;
}


int tcam::tcam_xioctl (int fd, unsigned int request, void *arg)
{
    constexpr int IOCTL_RETRY = 4;

    int ret = 0;
    int tries= IOCTL_RETRY;
    do
    {
        ret = ioctl(fd, request, arg);
        // ret = v4l2_ioctl(fd, request, arg);
    }
    while (ret && tries-- &&
           ((errno == EINTR) || (errno == EAGAIN) || (errno == ETIMEDOUT)));

    if (ret && (tries <= 0))
    {
        tcam_log(TCAM_LOG_ERROR,"ioctl (%i) retried %i times - giving up: %s)\n", request, IOCTL_RETRY, strerror(errno));
    }

    return (ret);

}


std::vector<double> tcam::create_steps_for_range (double min, double max)
{
    std::vector<double> vec;

    if (max <= min)
        return vec;

    vec.push_back(min);

    // we do not want every framerate to have unnecessary decimals
    // e.g. 1.345678 instead of 1.00000
    double current_step = (int)min;

    // 0.0 is not a valid framerate
    if (current_step < 1.0)
        current_step = 1.0;

    while (current_step < max)
    {

        if (current_step < 20.0)
        {
            current_step += 1;
        }
        else if (current_step < 100.0)
        {
            current_step += 10.0;
        }
        else if (current_step < 1000.0)
        {
            current_step += 50.0;
        }
        else
        {
            current_step += 100.0;
        }
        if (current_step < max)
        {
            vec.push_back(current_step);
        }
    }

    if (vec.back() != max)
    {
        vec.push_back(max);
    }
    return vec;
}


uint64_t tcam::get_buffer_length (unsigned int width, unsigned int height, uint32_t fourcc)
{
    if (width == 0 || height == 0 || fourcc == 0)
    {
        return 0;
    }

    if (!img::is_known_fcc(fourcc))
    {
        tcam_log(TCAM_LOG_ERROR, "Unknown fourcc %d", fourcc);
    }

    uint64_t size = width * height * ((double)img::get_bits_per_pixel(fourcc) / 8);

    return size;
}


unsigned int tcam::tcam_get_required_buffer_size (const struct tcam_video_format* format)
{
    if (format == nullptr)
    {
        return 0;
    }

    return get_buffer_length(format->width, format->height, format->fourcc);
}

uint32_t tcam::get_pitch_length (unsigned int width, uint32_t fourcc)
{
    if (width == 0 || fourcc == 0)
    {
        return 0;
    }

    return width * (img::get_bits_per_pixel(fourcc) / 8);
}


bool tcam::is_buffer_complete (const struct tcam_image_buffer* buffer)
{
    auto size = tcam::get_buffer_length(buffer->format.width,
                                        buffer->format.height,
                                        buffer->format.fourcc);

    if (size != buffer->length)
    {
        return false;
    }
    return true;
}


tcam_image_size tcam::calculate_auto_center (const tcam_image_size& sensor, const tcam_image_size& image)
{
    tcam_image_size ret = {};

    if (image.width > sensor.width || image.height > sensor.height)
    {
        return ret;
    }

    ret.width = (sensor.width / 2) - (image.width /2);
    ret.height = (sensor.height / 2) - (image.height / 2);

    return ret;
}


std::shared_ptr<Property> tcam::find_property (std::vector<std::shared_ptr<Property>>& properties,
                                               TCAM_PROPERTY_ID property_id)
{
    for (auto& p : properties)
    {
        if (p->get_ID() == property_id)
        {
            return p;
        }
    }

    return nullptr;
}


std::shared_ptr<Property> tcam::find_property (std::vector<std::shared_ptr<Property>>& properties,
                                               const std::string& property_name)
{

    auto f = [&property_name] (const std::shared_ptr<Property>& p)
        {
            if (p->get_name().compare(property_name) == 0)
                return true;
            return false;
        };

    auto iter = std::find_if(properties.begin(), properties.end(), f);

    if (iter != properties.end())
    {
        return *iter;
    }

    return nullptr;
}


bool tcam::compare_double (double val1, double val2)
{
    return std::fabs(val1 - val2) < std::numeric_limits<double>::epsilon();
}


bool tcam::in_range (const tcam_image_size& minimum,
                     const tcam_image_size& maximum,
                     const tcam_image_size& value)
{
    if (minimum.width > value.width || maximum.width < value.width)
    {
        return false;
    }
    if (minimum.height > value.height || maximum.height < value.height)
    {
        return false;
    }
    return true;
}


TCAM_PROPERTY_ID tcam::generate_unique_property_id ()
{
    static unsigned int id_to_use;
    static unsigned int id_prefix = 0x199f0000;

    TCAM_PROPERTY_ID new_id = id_prefix ^ id_to_use;
    id_to_use++;
    return new_id;
}


unsigned int tcam::get_pid_from_lockfile (const std::string& filename)
{
    std::ifstream f(filename);
    unsigned int ret = 0;
    if (f.is_open())
    {
        std::string line;
        getline(f, line);

        try
        {
            ret = std::stoi(line);
        }
        catch (const std::invalid_argument& e)
        {
            tcam_log(TCAM_LOG_ERROR, "Could not convert line \"%s\" to valid pid.", line.c_str());
        }
        f.close();
    }
    else
    {
        tcam_log(TCAM_LOG_ERROR, "Could not open file \"%s\"", filename.c_str());
    }

    return ret;
}


bool tcam::is_process_running (unsigned int pid)
{
    int ret = kill(pid, 0);

    bool is_running = false;
    if (ret < 0)
    {
        if (errno == EPERM)
        {
            is_running = true;
        }
    }
    else
    {
        is_running = true;
    }
    return is_running;
}


std::map<std::string, int> create_binning_entry_map (int min, int max)
{
    std::map<std::string, int> map;

    for (int i = min; i <= max; i += i)
    {
        map.emplace(std::to_string(i), i);
    }

    return map;
}


std::shared_ptr<Property> tcam::create_binning_property (TCAM_PROPERTY_ID id,
                                                         std::shared_ptr<PropertyImpl> handler,
                                                         int min, int max,
                                                         int value, int default_value)
{

    if (id != TCAM_PROPERTY_BINNING_HORIZONTAL
        && id != TCAM_PROPERTY_BINNING_VERTICAL
        && id != TCAM_PROPERTY_BINNING)
    {
        return nullptr;
    }

    tcam_device_property prop = {};
    prop.id = id;
    if (id == TCAM_PROPERTY_BINNING)
    {
        strncpy(prop.name, "Binning", sizeof(prop.name));
    }
    else if (id == TCAM_PROPERTY_BINNING_HORIZONTAL)
    {
        strncpy(prop.name, "Binning Horizontal", sizeof(prop.name));
    }
    else if (id == TCAM_PROPERTY_BINNING_VERTICAL)
    {
        strncpy(prop.name, "Binning Vertical", sizeof(prop.name));
    }
    prop.type = TCAM_PROPERTY_TYPE_ENUMERATION;

    prop.value.i.value = value;
    prop.value.i.default_value = default_value;

    auto map = create_binning_entry_map(min, max);

    return std::make_shared<PropertyEnumeration>(handler, prop, map, Property::ENUM);
}


double tcam::map_value_ranges (double input_start, double input_end,
                               double output_start, double output_end,
                               double value)
{
    return (value - input_start) * (output_end - output_start) / (input_end - input_start) - output_start;
}


std::string tcam::get_environment_variable (const std::string& name,
                                            const std::string& backup)
{
    char *value = getenv(name.c_str());

    if (!value)
    {
        return backup;
    }

    return value;
}
