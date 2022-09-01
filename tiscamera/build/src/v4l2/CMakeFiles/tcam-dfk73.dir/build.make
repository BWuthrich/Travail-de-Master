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
include src/v4l2/CMakeFiles/tcam-dfk73.dir/depend.make

# Include the progress variables for this target.
include src/v4l2/CMakeFiles/tcam-dfk73.dir/progress.make

# Include the compile flags for this target's objects.
include src/v4l2/CMakeFiles/tcam-dfk73.dir/flags.make

src/v4l2/CMakeFiles/tcam-dfk73.dir/dfk73.c.o: src/v4l2/CMakeFiles/tcam-dfk73.dir/flags.make
src/v4l2/CMakeFiles/tcam-dfk73.dir/dfk73.c.o: ../src/v4l2/dfk73.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/dev_ws/tiscamera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/v4l2/CMakeFiles/tcam-dfk73.dir/dfk73.c.o"
	cd /app/dev_ws/tiscamera/build/src/v4l2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tcam-dfk73.dir/dfk73.c.o   -c /app/dev_ws/tiscamera/src/v4l2/dfk73.c

src/v4l2/CMakeFiles/tcam-dfk73.dir/dfk73.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tcam-dfk73.dir/dfk73.c.i"
	cd /app/dev_ws/tiscamera/build/src/v4l2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /app/dev_ws/tiscamera/src/v4l2/dfk73.c > CMakeFiles/tcam-dfk73.dir/dfk73.c.i

src/v4l2/CMakeFiles/tcam-dfk73.dir/dfk73.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tcam-dfk73.dir/dfk73.c.s"
	cd /app/dev_ws/tiscamera/build/src/v4l2 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /app/dev_ws/tiscamera/src/v4l2/dfk73.c -o CMakeFiles/tcam-dfk73.dir/dfk73.c.s

# Object files for target tcam-dfk73
tcam__dfk73_OBJECTS = \
"CMakeFiles/tcam-dfk73.dir/dfk73.c.o"

# External object files for target tcam-dfk73
tcam__dfk73_EXTERNAL_OBJECTS =

src/v4l2/libtcam-dfk73.so.0.14.0: src/v4l2/CMakeFiles/tcam-dfk73.dir/dfk73.c.o
src/v4l2/libtcam-dfk73.so.0.14.0: src/v4l2/CMakeFiles/tcam-dfk73.dir/build.make
src/v4l2/libtcam-dfk73.so.0.14.0: /usr/lib/aarch64-linux-gnu/libudev.so
src/v4l2/libtcam-dfk73.so.0.14.0: /usr/lib/aarch64-linux-gnu/libusb-1.0.so
src/v4l2/libtcam-dfk73.so.0.14.0: src/v4l2/CMakeFiles/tcam-dfk73.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/dev_ws/tiscamera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libtcam-dfk73.so"
	cd /app/dev_ws/tiscamera/build/src/v4l2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcam-dfk73.dir/link.txt --verbose=$(VERBOSE)
	cd /app/dev_ws/tiscamera/build/src/v4l2 && $(CMAKE_COMMAND) -E cmake_symlink_library libtcam-dfk73.so.0.14.0 libtcam-dfk73.so.0 libtcam-dfk73.so

src/v4l2/libtcam-dfk73.so.0: src/v4l2/libtcam-dfk73.so.0.14.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/v4l2/libtcam-dfk73.so.0

src/v4l2/libtcam-dfk73.so: src/v4l2/libtcam-dfk73.so.0.14.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/v4l2/libtcam-dfk73.so

# Rule to build all files generated by this target.
src/v4l2/CMakeFiles/tcam-dfk73.dir/build: src/v4l2/libtcam-dfk73.so

.PHONY : src/v4l2/CMakeFiles/tcam-dfk73.dir/build

src/v4l2/CMakeFiles/tcam-dfk73.dir/clean:
	cd /app/dev_ws/tiscamera/build/src/v4l2 && $(CMAKE_COMMAND) -P CMakeFiles/tcam-dfk73.dir/cmake_clean.cmake
.PHONY : src/v4l2/CMakeFiles/tcam-dfk73.dir/clean

src/v4l2/CMakeFiles/tcam-dfk73.dir/depend:
	cd /app/dev_ws/tiscamera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/dev_ws/tiscamera /app/dev_ws/tiscamera/src/v4l2 /app/dev_ws/tiscamera/build /app/dev_ws/tiscamera/build/src/v4l2 /app/dev_ws/tiscamera/build/src/v4l2/CMakeFiles/tcam-dfk73.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/v4l2/CMakeFiles/tcam-dfk73.dir/depend
