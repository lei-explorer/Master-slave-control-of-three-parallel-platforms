# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/lzw/ding/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzw/ding/build

# Include any dependencies generated for this target.
include vicon_bridge/CMakeFiles/msvc_bridge.dir/depend.make

# Include the progress variables for this target.
include vicon_bridge/CMakeFiles/msvc_bridge.dir/progress.make

# Include the compile flags for this target's objects.
include vicon_bridge/CMakeFiles/msvc_bridge.dir/flags.make

vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o: vicon_bridge/CMakeFiles/msvc_bridge.dir/flags.make
vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o: /home/lzw/ding/src/vicon_bridge/src/msvc_bridge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzw/ding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o"
	cd /home/lzw/ding/build/vicon_bridge && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o -c /home/lzw/ding/src/vicon_bridge/src/msvc_bridge.cpp

vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.i"
	cd /home/lzw/ding/build/vicon_bridge && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzw/ding/src/vicon_bridge/src/msvc_bridge.cpp > CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.i

vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.s"
	cd /home/lzw/ding/build/vicon_bridge && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzw/ding/src/vicon_bridge/src/msvc_bridge.cpp -o CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.s

vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.requires:

.PHONY : vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.requires

vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.provides: vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.requires
	$(MAKE) -f vicon_bridge/CMakeFiles/msvc_bridge.dir/build.make vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.provides.build
.PHONY : vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.provides

vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.provides.build: vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o


# Object files for target msvc_bridge
msvc_bridge_OBJECTS = \
"CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o"

# External object files for target msvc_bridge
msvc_bridge_EXTERNAL_OBJECTS =

/home/lzw/ding/devel/lib/libmsvc_bridge.so: vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o
/home/lzw/ding/devel/lib/libmsvc_bridge.so: vicon_bridge/CMakeFiles/msvc_bridge.dir/build.make
/home/lzw/ding/devel/lib/libmsvc_bridge.so: vicon_bridge/CMakeFiles/msvc_bridge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzw/ding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/lzw/ding/devel/lib/libmsvc_bridge.so"
	cd /home/lzw/ding/build/vicon_bridge && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msvc_bridge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vicon_bridge/CMakeFiles/msvc_bridge.dir/build: /home/lzw/ding/devel/lib/libmsvc_bridge.so

.PHONY : vicon_bridge/CMakeFiles/msvc_bridge.dir/build

vicon_bridge/CMakeFiles/msvc_bridge.dir/requires: vicon_bridge/CMakeFiles/msvc_bridge.dir/src/msvc_bridge.cpp.o.requires

.PHONY : vicon_bridge/CMakeFiles/msvc_bridge.dir/requires

vicon_bridge/CMakeFiles/msvc_bridge.dir/clean:
	cd /home/lzw/ding/build/vicon_bridge && $(CMAKE_COMMAND) -P CMakeFiles/msvc_bridge.dir/cmake_clean.cmake
.PHONY : vicon_bridge/CMakeFiles/msvc_bridge.dir/clean

vicon_bridge/CMakeFiles/msvc_bridge.dir/depend:
	cd /home/lzw/ding/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzw/ding/src /home/lzw/ding/src/vicon_bridge /home/lzw/ding/build /home/lzw/ding/build/vicon_bridge /home/lzw/ding/build/vicon_bridge/CMakeFiles/msvc_bridge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vicon_bridge/CMakeFiles/msvc_bridge.dir/depend

