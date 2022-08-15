# Copyright 2017 The Imaging Source Europe GmbH
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


import logging
import re
import gi

gi.require_version("Gst", "1.0")

from gi.repository import Gst


log = logging.getLogger(__name__)


class ResDesc:
    """"""
    def __init__(self,
                 resolution: str,
                 fps: list):
        self.resolution = resolution
        self.fps = fps


class FmtDesc:
    """"""

    def __init__(self,
                 name: str = "",
                 fmt: str = ""):
        self.name = name
        self.fmt = fmt
        self.res_list = []

    def get_name(self):
        if self.name == "image/jpeg":
            return "jpeg"
        else:
            return self.fmt

    def get_resolution_list(self):

        res_list = []

        for entry in self.res_list:
            res_list.append(entry.resolution)

        return res_list

    def get_fps_list(self, resolution: str):

        for entry in self.res_list:
            if entry.resolution == resolution:
                return entry.fps

    def generate_caps_string(self, resolution: str, fps: str):
        if self.name == "image/jpeg":
            return "{},width={},height={},framerate={}".format(self.name,
                                                               resolution.split('x')[0],
                                                               resolution.split('x')[1],
                                                               fps)
        else:
            return "{},format={},width={},height={},framerate={}".format(self.name,
                                                                         self.fmt,
                                                                         resolution.split('x')[0],
                                                                         resolution.split('x')[1],
                                                                         fps)


class CapsDesc:
    """
    Generic Gstreamer caps description
    """

    def __init__(self, caps: Gst.Caps):
        self.caps = caps
        self.format_list = []
        self.have_dutils = False
        self._check_for_dutils()
        self._extract()

    def _check_for_dutils(self):
        """
        Dutils are important as it is currently the only element,
        that can debayer non 8-bit bayer images
        """
        elementfactory = Gst.ElementFactory.find("tcamdutils")
        if elementfactory:
            self.have_dutils = True
        else:
            self.have_dutils = False

    def _extract(self):
        """
        Extract the given GstCaps into an intenral representation
        """
        def get_framerates(fmt):
            try:
                rates = fmt.get_value("framerate")
            except TypeError:
                # Workaround for missing GstValueList support in GI
                substr = fmt.to_string()[fmt.to_string().find("framerate="):]
                # try for frame rate lists
                field, values, remain = re.split("{|}", substr, maxsplit=3)
                rates = [x.strip() for x in values.split(",")]

            if type(rates) is Gst.FractionRange:
                def create_steps_for_range(minval, maxval):
                    """
                    python version of utils.cpp:create_steps_for_range
                    """

                    ret = []

                    ret.append("{}/1".format(str(int(minval))))

                    # ensure steps are always
                    # so that step/1 can be added
                    step = int(minval)

                    while step < maxval:

                        if step < 20:
                            step += 1
                        elif step < 100:
                            step += 10
                        elif step < 1000:
                            step += 50
                        else:
                            step += 100

                        if step < maxval:
                            ret.append("{}/1".format(str(step)))

                    if ret[-1] != maxval:
                        ret.append("{}/1".format(str(int(maxval))))

                    return ret

                minval = rates.start.num / rates.start.denom
                maxval = rates.stop.num / rates.stop.denom

                # log.info("type {} - {}".format(type(minval), vars(minval)))
                rates = create_steps_for_range(minval, maxval)

            return rates

        format_dict = {}

        for j in range(self.caps.get_size()):
            fmt = self.caps.get_structure(j)
            try:
                format_name = fmt.get_name()

                if "ANY" in format_name:
                    continue

                if format_name == "image/jpeg":
                    format_string = "jpeg"
                else:
                    try:
                        format_string = fmt.get_value("format")
                    except TypeError as e:
                        # log.info("Could not interpret format info for: {}".format(fmt.to_string()))
                        # log.info("This is expected when dealing with lists.")
                        # log.info(e)

                        continue

                    # ignore additional formats that are generated by the bin
                    # we only want the src formats

                if ("BGRx" in format_string and "GRAY" in format_string):
                    format_string = "GRAY8"
                elif ("BGRx" in format_string):
                    continue
                elif (format_string is None or
                      format_string == "None"):
                    continue

                # this exists because non 8-bit bayer
                # has unly been supported through dutils
                # with tcamby1xtransform this has changed
                # now a rewrite of this function is probably a good idea
                if (format_name == "video/x-bayer" and
                        format_string not in ("rggb", "bggr", "gbrg", "grbg",
                                              "rggb10m", "bggr10m", "gbrg10m", "grbg10m",
                                              "rggb12m", "bggr12m", "gbrg12m", "grbg12m") and not
                        self.have_dutils):
                    continue

                if format_string not in format_dict:
                    format_dict[format_string] = FmtDesc(format_name, format_string)

                width = fmt.get_value("width")
                height = fmt.get_value("height")

                if type(width) == Gst.IntRange:
                    # do not handle ranges
                    # maybe in future releases
                    continue

                f_str = "{} - {}x{}".format(format_string,
                                            width,
                                            height)
                resolution_string = "{}x{}".format(width, height)

                if "None" in f_str:
                    continue
                if "range" in format_string:
                    continue

            except TypeError as e:
                log.warning("Could not interpret structure. Omitting. {}".format(fmt.to_string()))
                continue

            rates = get_framerates(fmt)
            if (rates is None or
                    type(rates) is Gst.Fraction):
                log.error("Received framerates can not be interpreted. Skipping.")
                log.debug("Format causing error is: '{}'. Rates is '{}'".format(fmt, type(rates)))
                continue

            # FractionRange is not an error but gets ignored
            # as tcam-capture does not allow the selection of
            # 'unusual' framerates
            if type(rates) is Gst.FractionRange:
                continue

            r = []
            for rate in rates:
                r.append(str(rate))

            format_dict[format_string].res_list.append(ResDesc(resolution_string, r))

        for key, value in format_dict.items():
            self.format_list.append(value)

    def get_fmt_list(self):

        fmt_list = []

        for entry in self.format_list:
            fmt_list.append(entry.get_name())

        return fmt_list

    def get_resolution_list(self, fmt: str):

        for entry in self.format_list:
            if entry.get_name() == fmt:
                return entry.get_resolution_list()

    def get_fps_list(self, fmt: str, resolution: str):
        for entry in self.format_list:
            if entry.get_name() == fmt:
                return entry.get_fps_list(resolution)

    def generate_caps_string(self, fmt: str, resolution: str, fps: str):
        """generates a string that contains valid caps"""

        for entry in self.format_list:
            if entry.get_name() == fmt:
                return entry.generate_caps_string(resolution, fps)
        return None

    def contains(self, caps_str: str):
        """
        Convert the given caps string to Gst.Caps and
        look if this collection contains them.
        Returns True is caps_str is in collection
        """
        if not caps_str:
            return False
        intersect = self.caps.intersect(Gst.Caps.from_string(caps_str))

        if not intersect:
            return False
        if intersect.is_empty():
            return False

        return True
