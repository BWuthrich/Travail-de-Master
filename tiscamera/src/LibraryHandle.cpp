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
#include "LibraryHandle.h"

#include <dlfcn.h>

#include <string>

#include "internal.h"


std::shared_ptr<LibraryHandle> tcam::LibraryHandle::open (const std::string& name,
                                                          const std::string& path)
{
    // std::shared_ptr<LibraryHandle> lib = std::make_shared<LibraryHandle>(name, path);
    std::shared_ptr<LibraryHandle> lib = std::shared_ptr<LibraryHandle>(new LibraryHandle(name, path));

    if (!lib->handle_)
    {
        return nullptr;
    }
    return lib;
}


tcam::LibraryHandle::LibraryHandle (const std::string& name,
                                    const std::string& path)
{
    handle_ = open_library(name, path);
}


tcam::LibraryHandle::~LibraryHandle ()
{
    if (handle_ != nullptr)
    {
        dlclose(handle_);
    }
}


void* tcam::LibraryHandle::open_library (const std::string& name,
                                         const std::string& path)
{
    std::string library_name;
    if (!path.empty())
    {
        library_name = path + "/" + name;
    }
    else
    {
        library_name = name;
    }
    dlerror();
    void* library_handle = dlopen(library_name.c_str(), RTLD_LAZY);

    if (!library_handle)
    {
        tcam_info("Could not load library %s", library_name.c_str());
        tcam_info("    Reason: %s", dlerror());
    }

    return library_handle;
}
