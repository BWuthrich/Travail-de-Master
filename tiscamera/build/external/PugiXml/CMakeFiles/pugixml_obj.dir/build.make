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
include external/PugiXml/CMakeFiles/pugixml_obj.dir/depend.make

# Include the progress variables for this target.
include external/PugiXml/CMakeFiles/pugixml_obj.dir/progress.make

# Include the compile flags for this target's objects.
include external/PugiXml/CMakeFiles/pugixml_obj.dir/flags.make

external/PugiXml/CMakeFiles/pugixml_obj.dir/pugixml.cpp.o: external/PugiXml/CMakeFiles/pugixml_obj.dir/flags.make
external/PugiXml/CMakeFiles/pugixml_obj.dir/pugixml.cpp.o: ../external/PugiXml/pugixml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/dev_ws/tiscamera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/PugiXml/CMakeFiles/pugixml_obj.dir/pugixml.cpp.o"
	cd /app/dev_ws/tiscamera/build/external/PugiXml && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pugixml_obj.dir/pugixml.cpp.o -c /app/dev_ws/tiscamera/external/PugiXml/pugixml.cpp

external/PugiXml/CMakeFiles/pugixml_obj.dir/pugixml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pugixml_obj.dir/pugixml.cpp.i"
	cd /app/dev_ws/tiscamera/build/external/PugiXml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/dev_ws/tiscamera/external/PugiXml/pugixml.cpp > CMakeFiles/pugixml_obj.dir/pugixml.cpp.i

external/PugiXml/CMakeFiles/pugixml_obj.dir/pugixml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pugixml_obj.dir/pugixml.cpp.s"
	cd /app/dev_ws/tiscamera/build/external/PugiXml && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/dev_ws/tiscamera/external/PugiXml/pugixml.cpp -o CMakeFiles/pugixml_obj.dir/pugixml.cpp.s

pugixml_obj: external/PugiXml/CMakeFiles/pugixml_obj.dir/pugixml.cpp.o
pugixml_obj: external/PugiXml/CMakeFiles/pugixml_obj.dir/build.make

.PHONY : pugixml_obj

# Rule to build all files generated by this target.
external/PugiXml/CMakeFiles/pugixml_obj.dir/build: pugixml_obj

.PHONY : external/PugiXml/CMakeFiles/pugixml_obj.dir/build

external/PugiXml/CMakeFiles/pugixml_obj.dir/clean:
	cd /app/dev_ws/tiscamera/build/external/PugiXml && $(CMAKE_COMMAND) -P CMakeFiles/pugixml_obj.dir/cmake_clean.cmake
.PHONY : external/PugiXml/CMakeFiles/pugixml_obj.dir/clean

external/PugiXml/CMakeFiles/pugixml_obj.dir/depend:
	cd /app/dev_ws/tiscamera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/dev_ws/tiscamera /app/dev_ws/tiscamera/external/PugiXml /app/dev_ws/tiscamera/build /app/dev_ws/tiscamera/build/external/PugiXml /app/dev_ws/tiscamera/build/external/PugiXml/CMakeFiles/pugixml_obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/PugiXml/CMakeFiles/pugixml_obj.dir/depend

