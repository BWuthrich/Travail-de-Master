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

#ifndef GENERAL_H
#define GENERAL_H

#include <string>

#include <gst/gst.h>

inline std::string extract_directory (const std::string& path)
{
    return path.substr( 0, path.find_last_of( '/' ) +1 );
}

inline std::string extract_filename (const std::string& path)
{
    return path.substr( path.find_last_of( '/' ) +1 );
}

inline std::string change_extension (const std::string& path, const std::string& ext)
{
    std::string filename = extract_filename( path );
    return extract_directory( path ) +filename.substr( 0, filename.find_last_of( '.' ) ) +ext;
}

bool is_valid_device_serial (GstElement* source, const std::string& serial);

#endif /* GENERAL_H */
