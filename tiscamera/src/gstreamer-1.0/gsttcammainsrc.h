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

#ifndef TCAM_GSTTCAMMAINSRC_H
#define TCAM_GSTTCAMMAINSRC_H

#include <gst/gst.h>
#include <gst/base/gstpushsrc.h>

#include <girepository.h>

#include <mutex>
#include <condition_variable>
#include <string>
#include <atomic>
#include "tcam.h"

using namespace tcam;

#ifdef __cplusplus
extern "C"
{
#endif


G_BEGIN_DECLS


#define GST_TYPE_TCAM_MAINSRC           (gst_tcam_mainsrc_get_type())
#define GST_TCAM_MAINSRC(obj)           (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_TCAM_MAINSRC, GstTcamMainSrc))
#define GST_TCAM_MAINSRC_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_TCAM_MAINSRC, GstTcamMainSrc))
#define GST_IS_TCAM_MAINSRC(obj)        (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_TCAM_MAINSRC))
#define GST_IS_TCAM_MAINSRC_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_TCAM_MAINSRC))

typedef struct _GstTcamMainSrc GstTcamMainSrc;
typedef struct _GstTcamMainSrcClass GstTcamMainSrcClass;

struct device_state;

struct _GstTcamMainSrc
{
    GstPushSrc element;

    std::string device_serial;
    TCAM_DEVICE_TYPE device_type;

    struct device_state* device;

    int fps_numerator;
    int fps_denominator;
    int n_buffers;
    int imagesink_buffers;

    std::atomic<bool> is_running;
    gboolean drop_incomplete_frames;
};


struct _GstTcamMainSrcClass
{
    GstPushSrcClass parent_class;
};

GType gst_tcam_mainsrc_get_type (void);

G_END_DECLS


#ifdef __cplusplus
}
#endif


#endif /* TCAM_GSTTCAMMAINSRC_H */
