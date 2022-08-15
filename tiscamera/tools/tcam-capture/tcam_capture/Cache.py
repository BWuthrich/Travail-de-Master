# Copyright 2018 The Imaging Source Europe GmbH
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

from configparser import ConfigParser
import os
import logging

log = logging.getLogger(__file__)


class Cache():
    """
    Application wide settings cache for
    temporary things like current device, etc.
    """

    def __init__(self):
        self.last_serial = None
        self.last_device_type = None
        self.last_format = None

        self.cache_file = None
        self.gc = "General"

    def reset(self):
        """Delete cache contents"""
        try:
            folder = self.get_default_cache_directory()
            for the_file in os.listdir(folder):
                file_path = os.path.join(folder, the_file)
                try:
                    if os.path.isfile(file_path):
                        os.unlink(file_path)
                    # elif os.path.isdir(file_path): shutil.rmtree(file_path)
                except Exception as e:
                    log.error(e)
        except FileNotFoundError:
            # this means there is no cache directory
            pass

    def get_cache_file(self,
                       directory: str=None,
                       filename: str="tcam-capture.cache"):
        """

        """

        if directory is None:
            directory = self.get_default_cache_directory()

        return os.path.join(directory, filename)

    def load(self):

        config = ConfigParser()
        dataset = config.read(self.get_cache_file())

        if len(dataset) == 0:
            log.info("No cache file to read")
            return

        gen = config[self.gc]

        self.last_serial = gen.get("last_serial", self.last_serial)
        self.last_device_type = gen.get("last_device_type", self.last_device_type)
        self.last_format = gen.get("last_format", self.last_format)

    def save(self):
        config = ConfigParser()

        config.add_section(self.gc)
        if self.last_serial:
            config[self.gc]["last_serial"] = self.last_serial
        if self.last_device_type:
            config[self.gc]["last_device_type"] = self.last_device_type
        if self.last_format:
            if type(self.last_format) == str:
                config[self.gc]["last_format"] = self.last_format
            else:
                log.error("last_format type cannot be parsed: {}".format(type(self.last_format)))

        os.makedirs(os.path.dirname(self.get_cache_file()), exist_ok=True)

        with open(self.get_cache_file(), 'w') as configfile:
            config.write(configfile)

    def save_device_state(self, device_state: str):
        """"""
        if not device_state:
            log.warning("Device state is None. No cache written.")
            return

        filename = self.get_device_state_filename()

        with open(filename, "w") as f:
            log.debug("Writing property state to {}".format(filename))
            f.write(device_state)

    def load_device_state(self):
        """
        return: str containing the comlpete json description
        """

        filename = self.get_device_state_filename()
        if os.path.isfile(filename):
            with open(filename, "r") as f:

                # f.write(device_cache)
                cache = f.read()
                return cache
        return None

    def get_device_state_filename(self):
        """
        Method returns the absolute filename for the device property cache
        """

        return os.path.join(self.get_default_cache_directory(),
                            "properties-{}-{}-state.json".format(self.last_serial, self.last_device_type))

    @staticmethod
    def get_default_cache_directory():
        return os.path.join(os.getenv("XDG_CACHE_DIR",
                                      os.path.expanduser("~/.cache")),
                            "tcam-capture")
