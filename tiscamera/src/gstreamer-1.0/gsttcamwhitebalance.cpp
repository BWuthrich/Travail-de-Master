/*
 * Copyright 2013 The Imaging Source Europe GmbH
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

/**
 * SECTION:element-gsttiswhitebalance
 *
 * The tiswhitebalance element analyzes the color temperatures of the incomming buffers and applies a whitebalancing.
 *
 * <refsect2>
 * <title>Example launch line</title>
 * |[
 * gst-launch -v fakesrc ! tiswhitebalance ! bayer ! fakesink
 * ]|
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
#include <gst/video/video.h>

#include <gst/base/gstbasetransform.h>
#include "gsttcamwhitebalance.h"
#include "tcamgstbase.h"
#include "tcamprop.h"
#include <stdlib.h>
#include <cstring>

#include "tcam.h"
#include "tcamprop_impl_helper.h"   // #TODO use this to implement a better tcamprop interface
#include <glib-object.h>

GST_DEBUG_CATEGORY_STATIC (gst_tcamwhitebalance_debug_category);
#define GST_CAT_DEFAULT gst_tcamwhitebalance_debug_category

enum
{
    PROP_0,
    PROP_GAIN_RED,
    PROP_GAIN_GREEN,
    PROP_GAIN_BLUE,
    PROP_AUTO_ENABLED,
    PROP_WHITEBALANCE_ENABLED,
    PROP_CAMERA_WB,
};


/* prototypes */

static void gst_tcamwhitebalance_set_property (GObject* object,
                                               guint property_id,
                                               const GValue* value,
                                               GParamSpec* pspec);
static void gst_tcamwhitebalance_get_property (GObject* object,
                                               guint property_id,
                                               GValue* value,
                                               GParamSpec* pspec);
static void gst_tcamwhitebalance_finalize (GObject* object);

static GstFlowReturn gst_tcamwhitebalance_transform_ip (GstBaseTransform* trans, GstBuffer* buf);
static GSList* gst_tcamwhitebalance_get_property_names (TcamProp* self);
static gboolean gst_tcamwhitebalance_set_caps (GstBaseTransform * trans,
    GstCaps * incaps, GstCaps * outcaps);
static gchar* gst_tcamwhitebalance_get_property_type (TcamProp* self,
                                                      const gchar* name);

static gboolean gst_tcamwhitebalance_get_tcam_property (TcamProp* self,
                                                        const gchar* name,
                                                        GValue* value,
                                                        GValue* min,
                                                        GValue* max,
                                                        GValue* def,
                                                        GValue* step,
                                                        GValue* type,
                                                        GValue* flags,
                                                        GValue* category,
                                                        GValue* group);

static gboolean gst_tcamwhitebalance_set_tcam_property (TcamProp* self,
                                                        const gchar* name,
                                                        const GValue* value);

static GSList* gst_tcamwhitebalance_get_tcam_menu_entries (TcamProp* self,
                                                           const gchar* name);

static GSList* gst_tcamwhitebalance_get_device_serials (TcamProp* self);

static gboolean gst_tcamwhitebalance_get_device_info (TcamProp* self,
                                                      const char* serial,
                                                      char** name,
                                                      char** identifier,
                                                      char** connection_type);

static void gst_tcamwhitebalance_prop_init (TcamPropInterface* iface)
{
    iface->get_tcam_property_names = gst_tcamwhitebalance_get_property_names;
    iface->get_tcam_property_type = gst_tcamwhitebalance_get_property_type;
    iface->get_tcam_property = gst_tcamwhitebalance_get_tcam_property;
    iface->get_tcam_menu_entries = gst_tcamwhitebalance_get_tcam_menu_entries;
    iface->set_tcam_property = gst_tcamwhitebalance_set_tcam_property;
    iface->get_tcam_device_serials = gst_tcamwhitebalance_get_device_serials;
    iface->get_tcam_device_info = gst_tcamwhitebalance_get_device_info;
}



G_DEFINE_TYPE_WITH_CODE (GstTcamWhitebalance, gst_tcamwhitebalance, GST_TYPE_BASE_TRANSFORM,
                         G_IMPLEMENT_INTERFACE (TCAM_TYPE_PROP,
                                                gst_tcamwhitebalance_prop_init))


static const char* tcamwhitebalance_property_id_to_string (guint id)
{
    switch (id)
    {
        case PROP_GAIN_RED:
            return "whitebalance-red";
        case PROP_GAIN_GREEN:
            return "whitebalance-green";
        case PROP_GAIN_BLUE:
            return "whitebalance-blue";
        case PROP_AUTO_ENABLED:
            return "whitebalance-auto";
        case PROP_WHITEBALANCE_ENABLED:
            return "camera-whitebalance";
        case PROP_CAMERA_WB:
            return "whitebalance-module-enabled";
        default:
            return "";
    }
}


static guint tcamwhitebalance_string_to_property_id (const char* name)
{
    if (strcmp(name, "whitebalance-red") == 0)
    {
        return PROP_GAIN_RED;
    }
    else if (strcmp(name, "whitebalance-green") == 0)
    {
        return PROP_GAIN_GREEN;
    }
    else if (strcmp(name, "whitebalance-blue") == 0)
    {
        return PROP_GAIN_BLUE;
    }
    else if (strcmp(name, "whitebalance-auto") == 0)
    {
        return PROP_AUTO_ENABLED;
    }
    else if (strcmp(name, "camera-whitebalance") == 0)
    {
        return PROP_CAMERA_WB;
    }
    else if (strcmp(name, "whitebalance-module-enabled") == 0)
    {
        return PROP_WHITEBALANCE_ENABLED;
    }
    else
    {
        return PROP_0;
    }
}



static GSList* gst_tcamwhitebalance_get_property_names (TcamProp* self __attribute__((unused)))
{
    GSList* names = nullptr;

    names = g_slist_append(names,
        g_strdup(tcamwhitebalance_property_id_to_string(PROP_GAIN_RED)));
    names = g_slist_append(names,
        g_strdup(tcamwhitebalance_property_id_to_string(PROP_GAIN_GREEN)));
    names = g_slist_append(names,
        g_strdup(tcamwhitebalance_property_id_to_string(PROP_GAIN_BLUE)));
    names = g_slist_append(names,
        g_strdup(tcamwhitebalance_property_id_to_string(PROP_AUTO_ENABLED)));
    names = g_slist_append(names,
        g_strdup(tcamwhitebalance_property_id_to_string(PROP_CAMERA_WB)));
    names = g_slist_append(names,
        g_strdup(tcamwhitebalance_property_id_to_string(PROP_WHITEBALANCE_ENABLED)));

    return names;
}


static gchar* gst_tcamwhitebalance_get_property_type (TcamProp* self __attribute__((unused)),
                                                      const gchar* name)
{
    if (strcmp(name, "whitebalance-red") == 0)
    {
        return strdup("integer");
    }
    else if (strcmp(name, "whitebalance-green") == 0)
    {
        return strdup("integer");
    }
    else if (strcmp(name, "whitebalance-blue") == 0)
    {
        return strdup("integer");
    }
    else if (strcmp(name, "whitebalance-auto") == 0)
    {
        return strdup("boolean");
    }
    else if (strcmp(name, "camera-whitebalance") == 0)
    {
        return strdup("boolean");
    }
    else if (strcmp(name, "whitebalance-module-enabled") == 0)
    {
        return strdup("boolean");
    }
    else
    {
        return nullptr;
    }
}


static gboolean gst_tcamwhitebalance_get_tcam_property (TcamProp* prop,
                                                        const gchar* name,
                                                        GValue* value,
                                                        GValue* min,
                                                        GValue* max,
                                                        GValue* def,
                                                        GValue* step,
                                                        GValue* type,
                                                        GValue* flags,
                                                        GValue* category,
                                                        GValue* group)
{
    GstTcamWhitebalance* self = GST_TCAMWHITEBALANCE(prop);

    if (strcmp(name, "whitebalance-red") == 0)
    {
        if (value)
        {
            g_value_init(value, G_TYPE_INT);
            g_value_set_int(value, self->red);
        }
        if (min)
        {
            g_value_init(min, G_TYPE_INT);
            g_value_set_int(min, 0);
        }
        if (max)
        {
            g_value_init(max, G_TYPE_INT);
            g_value_set_int(max, 255);
        }
        if (def)
        {
            g_value_init(def, G_TYPE_INT);
            g_value_set_int(def, 64);
        }
        if (step)
        {
            g_value_init(step, G_TYPE_INT);
            g_value_set_int(step, 1);
        }
        if (flags)
        {
            g_value_init(flags, G_TYPE_INT);
            g_value_set_int(flags, 0);
        }
        if (type)
        {
            g_value_init(type, G_TYPE_STRING);
            g_value_set_string(type,gst_tcamwhitebalance_get_property_type(prop, name));
        }
        if (category)
        {
            g_value_init(category, G_TYPE_STRING);
            g_value_set_string(category, "Color");
        }
        if (group)
        {
            g_value_init(group, G_TYPE_STRING);
            g_value_set_string(group, "Whitebalance");
        }

        return TRUE;
    }
    else if (strcmp(name, "whitebalance-green") == 0)
    {
        if (value)
        {
            g_value_init(value, G_TYPE_INT);
            g_value_set_int(value, self->green);
        }
        if (min)
        {
            g_value_init(min, G_TYPE_INT);
            g_value_set_int(min, 0);
        }
        if (max)
        {
            g_value_init(max, G_TYPE_INT);
            g_value_set_int(max, 255);
        }
        if (def)
        {
            g_value_init(def, G_TYPE_INT);
            g_value_set_int(def, 64);
        }
        if (step)
        {
            g_value_init(step, G_TYPE_INT);
            g_value_set_int(step, 1);
        }
        if (flags)
        {
            g_value_init(flags, G_TYPE_INT);
            g_value_set_int(flags, 0);
        }
        if (type)
        {
            g_value_init(type, G_TYPE_STRING);
            g_value_set_string(type,gst_tcamwhitebalance_get_property_type(prop, name));
        }
        if (category)
        {
            g_value_init(category, G_TYPE_STRING);
            g_value_set_string(category, "Color");
        }
        if (group)
        {
            g_value_init(group, G_TYPE_STRING);
            g_value_set_string(group, "Whitebalance");
        }
        return TRUE;
    }
    else if (strcmp(name, "whitebalance-blue") == 0)
    {
        if (value)
        {
            g_value_init(value, G_TYPE_INT);
            g_value_set_int(value, self->blue);
        }
        if (min)
        {
            g_value_init(min, G_TYPE_INT);
            g_value_set_int(min, 0);
        }
        if (max)
        {
            g_value_init(max, G_TYPE_INT);
            g_value_set_int(max, 255);
        }
        if (def)
        {
            g_value_init(def, G_TYPE_INT);
            g_value_set_int(def, 64);
        }
        if (step)
        {
            g_value_init(step, G_TYPE_INT);
            g_value_set_int(step, 1);
        }
        if (flags)
        {
            g_value_init(flags, G_TYPE_INT);
            g_value_set_int(flags, 0);
        }
        if (type)
        {
            g_value_init(type, G_TYPE_STRING);
            g_value_set_string(type,gst_tcamwhitebalance_get_property_type(prop, name));
        }
        if (category)
        {
            g_value_init(category, G_TYPE_STRING);
            g_value_set_string(category, "Color");
        }
        if (group)
        {
            g_value_init(group, G_TYPE_STRING);
            g_value_set_string(group, "Whitebalance");
        }
        return TRUE;
    }
    else if (strcmp(name, "whitebalance-auto") == 0)
    {
        if (value)
        {
            g_value_init(value, G_TYPE_BOOLEAN);
            g_value_set_boolean(value, self->auto_wb);
        }
        if (min)
        {
            g_value_init(min, G_TYPE_BOOLEAN);
            g_value_set_boolean(min, FALSE);
        }
        if (max)
        {
            g_value_init(max, G_TYPE_BOOLEAN);
            g_value_set_boolean(max, TRUE);
        }
        if (def)
        {
            g_value_init(def, G_TYPE_BOOLEAN);
            g_value_set_boolean(def, TRUE);
        }
        if (step)
        {
            g_value_init(step, G_TYPE_INT);
            g_value_set_int(step, 1);
        }
        if (flags)
        {
            g_value_init(flags, G_TYPE_INT);
            g_value_set_int(flags, 0);
        }
        if (type)
        {
            g_value_init(type, G_TYPE_STRING);
            g_value_set_string(type,gst_tcamwhitebalance_get_property_type(prop, name));
        }
        if (category)
        {
            g_value_init(category, G_TYPE_STRING);
            g_value_set_string(category, "Color");
        }
        if (group)
        {
            g_value_init(group, G_TYPE_STRING);
            g_value_set_string(group, "Whitebalance");
        }
        return TRUE;
    }
    else if (strcmp(name, "camera-whitebalance") == 0)
    {
        if (value)
        {
            g_value_init(value, G_TYPE_BOOLEAN);
            g_value_set_boolean(value, self->force_hardware_wb);
        }
        if (min)
        {
            g_value_init(min, G_TYPE_BOOLEAN);
            g_value_set_boolean(min, FALSE);
        }
        if (max)
        {
            g_value_init(max, G_TYPE_BOOLEAN);
            g_value_set_boolean(max, TRUE);
        }
        if (def)
        {
            g_value_init(def, G_TYPE_BOOLEAN);
            g_value_set_boolean(def, FALSE);
        }
        if (step)
        {
            g_value_init(step, G_TYPE_INT);
            g_value_set_int(step, 1);
        }
        if (flags)
        {
            g_value_init(flags, G_TYPE_INT);
            g_value_set_int(flags, 0);
        }
        if (type)
        {
            g_value_init(type, G_TYPE_STRING);
            g_value_set_string(type,gst_tcamwhitebalance_get_property_type(prop, name));
        }
        if (category)
        {
            g_value_init(category, G_TYPE_STRING);
            g_value_set_string(category, "Color");
        }
        if (group)
        {
            g_value_init(group, G_TYPE_STRING);
            g_value_set_string(group, "Whitebalance");
        }        return TRUE;
    }
    else if (strcmp(name, "whitebalance-module-enabled") == 0)
    {
        if (value)
        {
            g_value_init(value, G_TYPE_BOOLEAN);
            g_value_set_boolean(value, self->auto_enabled);
        }
        if (min)
        {
            g_value_init(min, G_TYPE_BOOLEAN);
            g_value_set_boolean(min, FALSE);
        }
        if (max)
        {
            g_value_init(max, G_TYPE_BOOLEAN);
            g_value_set_boolean(max, TRUE);
        }
        if (def)
        {
            g_value_init(def, G_TYPE_BOOLEAN);
            g_value_set_boolean(def, TRUE);
        }
        if (step)
        {
            g_value_init(step, G_TYPE_INT);
            g_value_set_int(step, 1);
        }
        if (flags)
        {
            g_value_init(flags, G_TYPE_INT);
            g_value_set_int(flags, 0);
        }
        if (type)
        {
            g_value_init(type, G_TYPE_STRING);
            g_value_set_string(type,gst_tcamwhitebalance_get_property_type(prop, name));
        }
        if (category)
        {
            g_value_init(category, G_TYPE_STRING);
            g_value_set_string(category, "Color");
        }
        if (group)
        {
            g_value_init(group, G_TYPE_STRING);
            g_value_set_string(group, "Whitebalance");
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


static gboolean gst_tcamwhitebalance_set_tcam_property (TcamProp* self,
                                                        const gchar* name,
                                                        const GValue* value)
{

    guint id = tcamwhitebalance_string_to_property_id(name);

    if (id == PROP_0)
    {
        return FALSE;
    }

    gst_tcamwhitebalance_set_property(G_OBJECT(self), id, value, NULL);

    return TRUE;
}


static GSList* gst_tcamwhitebalance_get_tcam_menu_entries (TcamProp* self __attribute__((unused)),
                                                           const gchar* name __attribute__((unused)))
{
    return nullptr;
}


static GSList* gst_tcamwhitebalance_get_device_serials (TcamProp* self __attribute__((unused)))
{
    return nullptr;
}


static gboolean gst_tcamwhitebalance_get_device_info (TcamProp* self __attribute__((unused)),
                                                      const char* serial __attribute__((unused)),
                                                      char** name __attribute__((unused)),
                                                      char** identifier __attribute__((unused)),
                                                      char** connection_type __attribute__((unused)))
{
    return FALSE;
}

/* actual gstreamer element */


/* pad templates */

static GstStaticPadTemplate gst_tcamwhitebalance_sink_template =
    GST_STATIC_PAD_TEMPLATE ("sink",
                             GST_PAD_SINK,
                             GST_PAD_ALWAYS,
                             GST_STATIC_CAPS ("video/x-bayer,format=(string){bggr,grbg,gbrg,rggb},framerate=(fraction)[0/1,MAX],width=[1,MAX],height=[1,MAX]")
        );

static GstStaticPadTemplate gst_tcamwhitebalance_src_template =
    GST_STATIC_PAD_TEMPLATE ("src",
                             GST_PAD_SRC,
                             GST_PAD_ALWAYS,
                             GST_STATIC_CAPS ("video/x-bayer,format=(string){bggr,grbg,gbrg,rggb},framerate=(fraction)[0/1,MAX],width=[1,MAX],height=[1,MAX]")
        );


/* class initialization */

static void gst_tcamwhitebalance_class_init (GstTcamWhitebalanceClass* klass)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
    GstBaseTransformClass *base_transform_class = GST_BASE_TRANSFORM_CLASS(klass);

    gst_element_class_add_pad_template(GST_ELEMENT_CLASS(klass),
                                       gst_static_pad_template_get(&gst_tcamwhitebalance_src_template));
    gst_element_class_add_pad_template(GST_ELEMENT_CLASS(klass),
                                       gst_static_pad_template_get(&gst_tcamwhitebalance_sink_template));

    gst_element_class_set_static_metadata(GST_ELEMENT_CLASS(klass),
                                         "The Imaging Source White Balance Element",
                                         "Generic",
                                         "Adjusts white balancing of video data buffers",
                                         "The Imaging Source Europe GmbH <support@theimagingsource.com>");

    gobject_class->set_property = gst_tcamwhitebalance_set_property;
    gobject_class->get_property = gst_tcamwhitebalance_get_property;
    gobject_class->finalize = gst_tcamwhitebalance_finalize;
    base_transform_class->transform_ip = GST_DEBUG_FUNCPTR(gst_tcamwhitebalance_transform_ip);
    base_transform_class->set_caps = GST_DEBUG_FUNCPTR (gst_tcamwhitebalance_set_caps);


    GST_DEBUG_CATEGORY_INIT(gst_tcamwhitebalance_debug_category, "tcamwhitebalance", 0, "tcam whitebalance");

    g_object_class_install_property(gobject_class,
                                    PROP_GAIN_RED,
                                    g_param_spec_int("red",
                                                     "Red",
                                                     "Value for red",
                                                     0, 255, 0,
                                                     static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT)));
    g_object_class_install_property(gobject_class,
                                    PROP_GAIN_GREEN,
                                    g_param_spec_int("green",
                                                     "Green",
                                                     "Value for red",
                                                     0, 255, 0,
                                                     static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT)));
    g_object_class_install_property(gobject_class,
                                    PROP_GAIN_BLUE,
                                    g_param_spec_int("blue",
                                                     "Blue",
                                                     "Value for blue",
                                                     0, 255, 0,
                                                     static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT)));
    g_object_class_install_property(gobject_class,
                                    PROP_AUTO_ENABLED,
                                    g_param_spec_boolean("auto",
                                                         "Auto Value Adjustment",
                                                         "Automatically adjust white balance values",
                                                         TRUE,
                                                         static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT)));
    g_object_class_install_property(gobject_class,
                                    PROP_CAMERA_WB,
                                    g_param_spec_boolean("camera-whitebalance",
                                                         "Device whitebalance settings",
                                                         "Adjust whitebalance values in the camera",
                                                         FALSE,
                                                         static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT)));
    g_object_class_install_property(gobject_class,
                                    PROP_WHITEBALANCE_ENABLED,
                                    g_param_spec_boolean("module-enabled",
                                                         "Enable/Disable White Balance Module",
                                                         "Disable entire module",
                                                         TRUE,
                                                         static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT)));
}


static void init_wb_values (GstTcamWhitebalance* self)
{
    self->rgb = {WB_IDENTITY, WB_IDENTITY, WB_IDENTITY};
    self->red = WB_IDENTITY;
    self->green = WB_IDENTITY;
    self->blue = WB_IDENTITY;
}


static void gst_tcamwhitebalance_init (GstTcamWhitebalance* self)
{
    gst_base_transform_set_in_place(GST_BASE_TRANSFORM(self), TRUE);

    init_wb_values(self);
    self->auto_wb = TRUE;

}


static void gst_tcamwhitebalance_set_property (GObject* object,
                                        guint property_id,
                                        const GValue* value,
                                        GParamSpec* pspec)
{
    GstTcamWhitebalance* tcamwhitebalance = GST_TCAMWHITEBALANCE(object);

    switch (property_id)
    {
        case PROP_GAIN_RED:
            tcamwhitebalance->red = g_value_get_int(value);
            break;
        case PROP_GAIN_GREEN:
            tcamwhitebalance->green = g_value_get_int(value);
            break;
        case PROP_GAIN_BLUE:
            tcamwhitebalance->blue = g_value_get_int(value);
            break;
        case PROP_AUTO_ENABLED:
            tcamwhitebalance->auto_wb = g_value_get_boolean(value);
            break;
        case PROP_WHITEBALANCE_ENABLED:
            tcamwhitebalance->auto_enabled = g_value_get_boolean(value);
            break;
        case PROP_CAMERA_WB:
            tcamwhitebalance->force_hardware_wb = g_value_get_boolean(value);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}


static void gst_tcamwhitebalance_get_property (GObject* object,
                                        guint property_id,
                                        GValue* value,
                                        GParamSpec* pspec)
{
    GstTcamWhitebalance *tcamwhitebalance = GST_TCAMWHITEBALANCE(object);

    switch (property_id)
    {
        case PROP_GAIN_RED:
            g_value_set_int(value, tcamwhitebalance->red);
            break;
        case PROP_GAIN_GREEN:
            g_value_set_int(value, tcamwhitebalance->green);
            break;
        case PROP_GAIN_BLUE:
            g_value_set_int(value, tcamwhitebalance->blue);
            break;
        case PROP_AUTO_ENABLED:
            g_value_set_boolean(value, tcamwhitebalance->auto_wb);
            break;
        case PROP_WHITEBALANCE_ENABLED:
            g_value_set_boolean(value, tcamwhitebalance->auto_enabled);
            break;
        case PROP_CAMERA_WB:
            g_value_set_boolean(value, tcamwhitebalance->force_hardware_wb);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}


static void gst_tcamwhitebalance_finalize (GObject* object)
{
    G_OBJECT_CLASS(gst_tcamwhitebalance_parent_class)->finalize (object);
}


static gboolean gst_tcamwhitebalance_device_set_whiteblance (GstTcamWhitebalance* self)
{
    GST_INFO("Applying white balance to device with values: R:%d G:%d B:%d",
             self->res.color.rgb.R,
             self->res.color.rgb.G,
             self->res.color.rgb.B);

    GValue val_red = G_VALUE_INIT;
    g_value_init(&val_red, G_TYPE_INT);
    g_value_set_int(&val_red, self->res.color.rgb.R);

    if (!tcam_prop_set_tcam_property(TCAM_PROP(self), "Gain Red", &val_red))
    {
        GST_WARNING("Unable to set gain red");
        return FALSE;
    }

    GValue val_green = G_VALUE_INIT;
    g_value_init(&val_green, G_TYPE_INT);
    g_value_set_int(&val_green, self->res.color.rgb.G);

    if (!tcam_prop_set_tcam_property(TCAM_PROP(self), "Gain Green", &val_green))
    {
        GST_WARNING("Unable to set gain green");
        return FALSE;
    }

    GValue val_blue = G_VALUE_INIT;
    g_value_init(&val_blue, G_TYPE_INT);
    g_value_set_int(&val_blue, self->res.color.rgb.B);

    if (!tcam_prop_set_tcam_property(TCAM_PROP(self), "Gain Blue", &val_blue))
    {
        GST_WARNING("Unable to set gain blue");
        return FALSE;
    }

    return TRUE;
}

static uint clip (uint x, uint max)
{
    if ( x > max )
        return max;
    return x;
}



static uint calc_brightness_from_clr_avg (uint r, uint g, uint b)
{
    return (r * r_factor + g * g_factor + b * b_factor) >> 8;
}


static bool is_near_gray (uint r, uint g, uint b)
{
    uint brightness = calc_brightness_from_clr_avg( r, g, b );
    if ( brightness < NEARGRAY_MIN_BRIGHTNESS ) return false;
    if ( brightness > NEARGRAY_MAX_BRIGHTNESS ) return false;

    uint deltaR = abs( (int)r - (int)brightness );
    uint deltaG = abs( (int)g - (int)brightness );
    uint deltaB = abs( (int)b - (int)brightness );

    float devR = deltaR / (float)brightness;
    float devG = deltaG / (float)brightness;
    float devB = deltaB / (float)brightness;

    return ((devR < NEARGRAY_MAX_COLOR_DEVIATION) &&
            (devG < NEARGRAY_MAX_COLOR_DEVIATION) &&
            (devB < NEARGRAY_MAX_COLOR_DEVIATION));
}


static bool wb_auto_step (rgb_tripel* clr, rgb_tripel* wb )
{
    unsigned int avg = ((clr->R + clr->G + clr->B) / 3);
    int dr = (int)avg - clr->R;
    int dg = (int)avg - clr->G;
    int db = (int)avg - clr->B;

    if ((unsigned int)abs(dr) < BREAK_DIFF
        && (unsigned int)abs(dg) < BREAK_DIFF
        && (unsigned int)abs(db) < BREAK_DIFF)
    {
        wb->R = clip( wb->R, WB_MAX );
        wb->G = clip( wb->G, WB_MAX );
        wb->B = clip( wb->B, WB_MAX );

        return true;
    }

    if ((clr->R > avg) && (wb->R > WB_IDENTITY))
    {
        wb->R -= 1;
    }

    if ((clr->G > avg) && (wb->G > WB_IDENTITY))
    {
        wb->G -= 1;
    }

    if ((clr->B > avg) && (wb->B > WB_IDENTITY))
    {
        wb->B -= 1;
    }

    if ((clr->R < avg) && (wb->R < WB_MAX))
    {
        wb->R += 1;
    }

    if ((clr->G < avg) && (wb->G < WB_MAX))
    {
        wb->G += 1;
    }

    if ((clr->B < avg) && (wb->B < WB_MAX))
    {
        wb->B += 1;
    }

    if ((wb->R > WB_IDENTITY) && (wb->G > WB_IDENTITY) && (wb->B > WB_IDENTITY))
    {
        wb->R -= 1;
        wb->G -= 1;
        wb->B -= 1;
    }

    return false;
}


static rgb_tripel simulate_whitebalance (const auto_sample_points* data,
                                  const rgb_tripel* wb,
                                  bool enable_near_gray)
{
    rgb_tripel result = { 0, 0, 0 };
    rgb_tripel result_near_gray = { 0, 0, 0 };
    unsigned int count_near_gray = 0;

    uint i;
    for (i = 0; i < data->cnt; ++i)
    {
        unsigned int r = clip( data->samples[i].r * wb->R / WB_IDENTITY, WB_MAX );
        unsigned int g = clip( data->samples[i].g * wb->G / WB_IDENTITY, WB_MAX );
        unsigned int b = clip( data->samples[i].b * wb->B / WB_IDENTITY, WB_MAX );

        result.R += r;
        result.G += g;
        result.B += b;

        if ( is_near_gray( r, g, b ) )
        {
            result_near_gray.R += r;
            result_near_gray.G += g;
            result_near_gray.B += b;
            count_near_gray += 1;
        }
    }

    float near_gray_amount = count_near_gray / (float)data->cnt;

    if ((near_gray_amount < NEARGRAY_REQUIRED_AMOUNT) || !enable_near_gray)
    {
        result.R /= data->cnt;
        result.G /= data->cnt;
        result.B /= data->cnt;
        return result;
    }
    else
    {
        result_near_gray.R /= count_near_gray;
        result_near_gray.G /= count_near_gray;
        result_near_gray.B /= count_near_gray;
        return result_near_gray;
    }
}


static bool auto_whitebalance (const auto_sample_points* data, rgb_tripel* wb, uint* resulting_brightness)
{
    rgb_tripel old_wb = *wb;
    if (wb->R < WB_IDENTITY)
        wb->R = WB_IDENTITY;
    if (wb->G < WB_IDENTITY)
        wb->G = WB_IDENTITY;
    if (wb->B < WB_IDENTITY)
        wb->B = WB_IDENTITY;
    if (old_wb.R != wb->R || old_wb.G != wb->G || old_wb.B != wb->B)
        return false;

    while ((wb->R > WB_IDENTITY) && (wb->G > WB_IDENTITY) && (wb->B > WB_IDENTITY))
    {
        wb->R -= 1;
        wb->G -= 1;
        wb->B -= 1;
    }

    unsigned int steps = 0;
    while (steps++ < MAX_STEPS)
    {
        rgb_tripel tmp = simulate_whitebalance(data, wb, true);

        // Simulate white balance once more, this time always on the whole image
        rgb_tripel tmp2 = simulate_whitebalance(data, wb, false);
        *resulting_brightness = calc_brightness_from_clr_avg( tmp2.R, tmp2.G, tmp2.B );

        if (wb_auto_step(&tmp, wb))
        {
            return true;
        }
    }
    wb->R = clip( wb->R, WB_MAX );
    wb->G = clip( wb->G, WB_MAX );
    wb->B = clip( wb->B, WB_MAX );

    return false;
}

static void whitebalance_buffer (GstTcamWhitebalance* self, GstBuffer* buf)
{
    rgb_tripel rgb = self->rgb;

    /* we prefer to set our own values */
    if (self->auto_wb == FALSE)
    {
        rgb.R = self->red;
        rgb.G = self->green;
        rgb.B = self->blue;

        self->res.settings.user_values = rgb;
        self->res.settings.auto_whitebalance = false;
    }
    else /* update the permanent values to represent the current adjustments */
    {
        self->res.settings.auto_whitebalance = true;
        auto_sample_points points = {};

        GstMapInfo info;

        gst_buffer_map(buf, &info, GST_MAP_READ);

        unsigned char* data = (unsigned char*)info.data;

        get_sampling_points(data, &points, self->pattern, self->vinfo.width, self->vinfo.height);
        gst_buffer_unmap(buf, &info);

        guint resulting_brightness = 0;
        auto_whitebalance(&points, &rgb, &resulting_brightness);

        self->red = rgb.R;
        self->green = rgb.G;
        self->blue = rgb.B;

        self->rgb = rgb;
    }

    if (self->res.color.has_whitebalance)
    {
        self->res.color.rgb = rgb;
        gst_tcamwhitebalance_device_set_whiteblance(self);
    }
    else
    {
        //apply_wb_by8_c(self, buf, rgb.R, rgb.G, rgb.B);

        self->res.settings.rgb = self->rgb;

        tcam::algorithms::whitebalance::whitebalance_buffer(&self->res.settings, self->res.buffer);

        self->rgb = self->res.settings.rgb;
    }
}


static void update_device_resources ( GstElement* source_element, device_resources* res )
{





    // tcam::Property* prop = dev->get_property(TCAM_PROPERTY_EXPOSURE);

    // if (prop == nullptr)
    // {
    //     GST_ERROR("Exposure could not be found!");
    // }
    // else
    // {
    //     struct tcam_device_property p = prop->get_struct();

    //     res->exposure.min = p.value.i.min;
    //     res->exposure.max = p.value.i.max;
    //     res->exposure.value = p.value.i.value;
    // }

    // prop = dev->get_property(TCAM_PROPERTY_GAIN);

    // if (prop == nullptr)
    // {
    //     GST_ERROR("Gain could not be found!");
    // }
    // else
    // {
    //     struct tcam_device_property p = prop->get_struct();

    //     res->gain.min = p.value.i.min;
    //     res->gain.max = p.value.i.max;
    //     res->gain.value = p.value.i.value;
    // }

    // only indended for int retrieval
    auto get_int_value = [source_element] (const std::string& name)
                         {
                             GValue val = {};
                             gboolean ret = tcam_prop_get_tcam_property(TCAM_PROP(source_element),
                                                                        name.c_str(),
                                                                        &val,
                                                                        nullptr,
                                                                        nullptr,
                                                                        nullptr,
                                                                        nullptr,
                                                                        nullptr,
                                                                        nullptr,
                                                                        nullptr,
                                                                        nullptr);

                             if (!ret)
                             {
                                 GST_WARNING("Could not query property '%s'\n", name.c_str() );
                                 return 0;
                             }
                             int tmp = g_value_get_int(&val);
                             g_value_unset( &val );
                             return tmp;
                         };


    GSList* names = tcam_prop_get_tcam_property_names(TCAM_PROP(source_element));
    for( const auto& name : tcam_helper::gst_consume_GSList_to_vector( names ) )
    {
        if ( name == "Gain Red" )
        {
            res->color.rgb.R = get_int_value(name);
            // hard coded from dfk72
            res->color.default_value = 36;
        }
        else if ( name == "Gain Green")
        {
            res->color.rgb.G = get_int_value(name);
            // hard coded from dfk72
            res->color.default_value = 36;
        }
        else if ( name == "Gain Blue" )
        {
            res->color.rgb.B = get_int_value(name);
            // hard coded from dfk72
            res->color.default_value = 36;
        }
    }
}


static device_resources find_source (GstElement* self)
{
    device_resources res = {};
    res.color.max = 255;

    /* if camera_src is not set we assume that the first default camera src found shall be used */

    auto source_element = tcam_gst_find_camera_src(self);

    if( source_element == nullptr )
    {
        GST_ERROR( "Could not find source element" );
    }
    else
    {
        update_device_resources( source_element, &res );
        gst_object_unref( source_element );
    }

    return res;
}


static gboolean gst_tcamwhitebalance_set_caps (GstBaseTransform* trans,
                                               GstCaps* incaps,
                                               GstCaps* outcaps)
{
    GstTcamWhitebalance* self = GST_TCAMWHITEBALANCE(trans);
    GstStructure* structure = nullptr;

    GST_DEBUG("in caps %" GST_PTR_FORMAT " out caps %" GST_PTR_FORMAT,
              (void*)incaps,
              (void*)outcaps);
    structure = gst_caps_get_structure(incaps, 0);

    if (g_str_equal(gst_structure_get_name(structure), "video/x-bayer"))
    {
        const char* format;
        format = gst_structure_get_string (structure, "format");
        if (g_str_equal(format, "bggr"))
        {
            self->pattern = BG;
        }
        else if (g_str_equal(format, "gbrg"))
        {
            self->pattern = GB;
        }
        else if (g_str_equal(format, "grbg"))
        {
            self->pattern = GR;
        }
        else if (g_str_equal(format, "rggb"))
        {
            self->pattern = RG;
        }
        else
        {
            g_critical("Format '%s' not handled by this element", format);
            g_return_val_if_reached(false);
        }
    }
    gst_video_info_from_caps(&self->vinfo, incaps);
    gst_caps_to_tcam_video_format(incaps , &self->res.buffer.format);
    GST_DEBUG("width: %d, height: %d", self->vinfo.width, self->vinfo.height);
    self->expected_buffer_size = self->vinfo.width * self->vinfo.height;

    return true;
}

static gboolean extract_resolution (GstTcamWhitebalance* self)
{
    self->res = find_source(GST_ELEMENT(self));
    return TRUE;
}

/* Entry point */
static GstFlowReturn gst_tcamwhitebalance_transform_ip (GstBaseTransform* trans, GstBuffer* buf)
{
    GstTcamWhitebalance* self = GST_TCAMWHITEBALANCE (trans);

    if (self->vinfo.width == 0 || self->vinfo.height == 0)
    {
        if (!extract_resolution(self))
        {
            GST_ERROR("Received format is not usable. Aborting");
            return GST_FLOW_ERROR;
        }

        if (self->force_hardware_wb)
        {
            self->res.color.has_whitebalance = TRUE;
        }

		if (self->res.color.has_whitebalance)
		{
			WB_MAX = self->res.color.max;
			WB_IDENTITY = self->res.color.default_value;

			init_wb_values(self);
		}
    }

    /* auto is completely disabled */
    if (!self->auto_enabled)
    {
        return GST_FLOW_OK;
    }

    // validity checks
    GstMapInfo info;

    gst_buffer_map(buf, &info, GST_MAP_READ);

    guint* data = (guint*)info.data;
    guint length = info.size;



    if (data == NULL || length != self->expected_buffer_size)
    {
        GST_ERROR("Buffer is not valid! Ignoring buffer and trying to continue...(%d <> %d) %p",
                  length, self->expected_buffer_size, (void*)data);
        gst_buffer_unmap(buf, &info);
        return GST_FLOW_OK;
    }

    self->res.buffer.pData = (unsigned char*)data;
    self->res.buffer.length = length;

    self->res.settings.whitebalance_is_active = self->auto_wb;
    self->res.settings.pattern = self->pattern;

    whitebalance_buffer(self, buf);

    gst_buffer_unmap(buf, &info);


    return GST_FLOW_OK;
}


static gboolean plugin_init (GstPlugin* plugin)
{
    return gst_element_register (plugin, "tcamwhitebalance", GST_RANK_NONE, GST_TYPE_TCAMWHITEBALANCE);
}

#ifndef VERSION
#define VERSION "0.0.1"
#endif
#ifndef PACKAGE
#define PACKAGE "tcamwhitebalance"
#endif
#ifndef PACKAGE_NAME
#define PACKAGE_NAME tcamwhitebalance
#endif
#ifndef GST_PACKAGE_ORIGIN
#define GST_PACKAGE_ORIGIN "https://github.com/TheImagingSource/tcamcamera"
#endif

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
                   GST_VERSION_MINOR,
                   PACKAGE_NAME,
                   "The Imaging Source white balance plugin",
                   plugin_init,
                   get_version(),
                   "Proprietary",
                   PACKAGE,
                   GST_PACKAGE_ORIGIN)
