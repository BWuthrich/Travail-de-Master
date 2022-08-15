# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /app/dev_ws/tiscamera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/dev_ws/tiscamera/build

# Include any dependencies generated for this target.
include src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/depend.make

# Include the progress variables for this target.
include src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/progress.make

# Include the compile flags for this target's objects.
include src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/flags.make

src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.o: src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/flags.make
src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.o: ../src/gstreamer-1.0/gsttcamautoexposure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/dev_ws/tiscamera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.o"
	cd /app/dev_ws/tiscamera/build/src/gstreamer-1.0 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.o -c /app/dev_ws/tiscamera/src/gstreamer-1.0/gsttcamautoexposure.cpp

src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.i"
	cd /app/dev_ws/tiscamera/build/src/gstreamer-1.0 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/dev_ws/tiscamera/src/gstreamer-1.0/gsttcamautoexposure.cpp > CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.i

src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.s"
	cd /app/dev_ws/tiscamera/build/src/gstreamer-1.0 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/dev_ws/tiscamera/src/gstreamer-1.0/gsttcamautoexposure.cpp -o CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.s

# Object files for target gsttcamautoexposure
gsttcamautoexposure_OBJECTS = \
"CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.o"

# External object files for target gsttcamautoexposure
gsttcamautoexposure_EXTERNAL_OBJECTS =

src/gstreamer-1.0/libgsttcamautoexposure.so: src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/gsttcamautoexposure.cpp.o
src/gstreamer-1.0/libgsttcamautoexposure.so: src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/build.make
src/gstreamer-1.0/libgsttcamautoexposure.so: src/gstreamer-1.0/libtcamgstbase.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgobject-2.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgmodule-2.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgthread-2.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libglib-2.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libglib-2.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgstreamer-1.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgstreamer-1.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgstbase-1.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libgstvideo-1.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: src/libtcam.so.0.14.0
src/gstreamer-1.0/libgsttcamautoexposure.so: src/v4l2/libtcam-dfk73.so.0.14.0
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libudev.so
src/gstreamer-1.0/libgsttcamautoexposure.so: /usr/lib/aarch64-linux-gnu/libusb-1.0.so
src/gstreamer-1.0/libgsttcamautoexposure.so: src/gobject/libtcamprop.so.0.1
src/gstreamer-1.0/libgsttcamautoexposure.so: src/algorithms/libtcam-algorithms.so.0.14.0
src/gstreamer-1.0/libgsttcamautoexposure.so: src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/dev_ws/tiscamera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libgsttcamautoexposure.so"
	cd /app/dev_ws/tiscamera/build/src/gstreamer-1.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gsttcamautoexposure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/build: src/gstreamer-1.0/libgsttcamautoexposure.so

.PHONY : src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/build

src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/clean:
	cd /app/dev_ws/tiscamera/build/src/gstreamer-1.0 && $(CMAKE_COMMAND) -P CMakeFiles/gsttcamautoexposure.dir/cmake_clean.cmake
.PHONY : src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/clean

src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/depend:
	cd /app/dev_ws/tiscamera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/dev_ws/tiscamera /app/dev_ws/tiscamera/src/gstreamer-1.0 /app/dev_ws/tiscamera/build /app/dev_ws/tiscamera/build/src/gstreamer-1.0 /app/dev_ws/tiscamera/build/src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/gstreamer-1.0/CMakeFiles/gsttcamautoexposure.dir/depend

