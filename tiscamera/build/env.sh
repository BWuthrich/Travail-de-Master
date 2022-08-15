#!/usr/bin/env sh

# This script sets environment variables and aliases to
# allow the user testing of a tiscamera build without the need
# of installation

BASE="/app/dev_ws/tiscamera/build"
SOURCE_DIR="/app/dev_ws/tiscamera"


if [ -z "$BASE" ]
then
    echo "Unable to find root dir of project."
    echo "Please set it manually."
    exit 1
fi

if [ -z "${PKG_CONFIG_PATH}" ]; then
    export PKG_CONFIG_PATH="${BASE}/data/"
else
    export PKG_CONFIG_PATH="${BASE}/data/:${PKG_CONFIG_PATH}"
fi

if [ -z "${C_INCLUDE_PATH}" ]; then
    export C_INCLUDE_PATH="${SOURCE_DIR}/src/gobject:${SOURCE_DIR}/src/gstreamer-1.0"
else
    export C_INCLUDE_PATH="${C_INCLUDE_PATH}:${SOURCE_DIR}/src/gobject:${SOURCE_DIR}/src/gstreamer-1.0"
fi

if [ -z "${GST_PLUGIN_PATH_1_0}" ]; then
    export GST_PLUGIN_PATH_1_0="${BASE}/src/gstreamer-1.0/"
else
    export GST_PLUGIN_PATH_1_0="${BASE}/src/gstreamer-1.0/:${GST_PLUGIN_PATH_1_0}"
fi

if [ -z "${LD_RUN_PATH}" ]; then

    export LD_RUN_PATH="${BASE}/src:${BASE}/src/gobject:${BASE}/src/gstreamer-1.0"
else
    export LD_RUN_PATH="${BASE}/src:${BASE}/src/gobject:${BASE}/src/gstreamer-1.0:${LD_LIBRARY_PATH}"
fi

if [ -z "${GI_TYPELIB_PATH}" ]; then
    export GI_TYPELIB_PATH="${BASE}/src/gobject/"
else
    export GI_TYPELIB_PATH="${BASE}/src/gobject/:${GI_TYPELIB_PATH}"
fi

if [ -z "${LD_LIBRARY_PATH}" ]; then
    export LD_LIBRARY_PATH="${BASE}/src/v4l2:${BASE}/src/aravis:${BASE}/src/libusb:${BASE}/src/gobject:${BASE}/src/gstreamer-1.0"
else
    export LD_LIBRARY_PATH="${BASE}/src/v4l2:${BASE}/src/aravis:${BASE}/src/libusb:${BASE}/src/gobject:${BASE}/src/gstreamer-1.0:${LD_LIBRARY_PATH}"
fi


if [ -z "${LIBRARY_PATH}" ]; then
    export LIBRARY_PATH="${BASE}/src/v4l2:${BASE}/src/aravis:${BASE}/src/libusb:${BASE}/src/gobject:${BASE}/src/gstreamer-1.0"
else
    export LIBRARY_PATH="${BASE}/src/v4l2:${BASE}/src/aravis:${BASE}/src/libusb::${BASE}/src/gobject:${BASE}/src/gstreamer-1.0:${LD_RUN_PATH}"
fi

#
# aliases for tools
#

if [ -x "${BASE}/tools/gige-daemon/gige-daemon" ]; then
    alias gige-daemon="${BASE}/tools/gige-daemon/gige-daemon"
fi

if [ -x "${BASE}/tools/camera-ip-conf/camera-ip-conf" ]; then
    alias camera-ip-conf="${BASE}/tools/camera-ip-conf/camera-ip-conf"
fi

if [ -x "${BASE}/tools/firmware-update/firmware-update" ]; then
    alias firmware-update="${BASE}/tools/firmware-update/firmware-update"
fi

if [ -x "${BASE}/tools/tcam-gigetool/tcam-gigetool" ]; then
    alias tcam-gigetool="${BASE}/tools/tcam-gigetool/tcam-gigetool"
fi

if [ -x "${BASE}/tools/tcam-uvc-extension-loader/tcam-uvc-extension-loader" ]; then
    alias tcam-uvc-extension-loader="${BASE}/tools/tcam-uvc-extension-loader/tcam-uvc-extension-loader"
fi

if [ -x "${BASE}/tools/dfk37udev/dfk37udev" ]; then
    alias dfk37udev="${BASE}/tools/dfk37udev/dfk37udev"
fi

if [ -x "${BASE}/tools/tcam-ctrl/tcam-ctrl" ]; then
    alias tcam-ctrl="${BASE}/tools/tcam-ctrl/tcam-ctrl"
fi

if [ -x "${SOURCE_DIR}/tools/tcam-capture/tcam-capture" ]; then
    alias tcam-capture="${SOURCE_DIR}/tools/tcam-capture/tcam-capture"
fi
