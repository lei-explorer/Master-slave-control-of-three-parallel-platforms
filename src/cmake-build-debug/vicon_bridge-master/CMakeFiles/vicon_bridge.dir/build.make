# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/lzw/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lzw/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lzw/ding/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzw/ding/src/cmake-build-debug

# Include any dependencies generated for this target.
include vicon_bridge-master/CMakeFiles/vicon_bridge.dir/depend.make

# Include the progress variables for this target.
include vicon_bridge-master/CMakeFiles/vicon_bridge.dir/progress.make

# Include the compile flags for this target's objects.
include vicon_bridge-master/CMakeFiles/vicon_bridge.dir/flags.make

vicon_bridge-master/CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.o: vicon_bridge-master/CMakeFiles/vicon_bridge.dir/flags.make
vicon_bridge-master/CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.o: ../vicon_bridge-master/src/vicon_bridge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzw/ding/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vicon_bridge-master/CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.o"
	cd /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.o -c /home/lzw/ding/src/vicon_bridge-master/src/vicon_bridge.cpp

vicon_bridge-master/CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.i"
	cd /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzw/ding/src/vicon_bridge-master/src/vicon_bridge.cpp > CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.i

vicon_bridge-master/CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.s"
	cd /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzw/ding/src/vicon_bridge-master/src/vicon_bridge.cpp -o CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.s

# Object files for target vicon_bridge
vicon_bridge_OBJECTS = \
"CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.o"

# External object files for target vicon_bridge
vicon_bridge_EXTERNAL_OBJECTS =

devel/lib/vicon_bridge/vicon_bridge: vicon_bridge-master/CMakeFiles/vicon_bridge.dir/src/vicon_bridge.cpp.o
devel/lib/vicon_bridge/vicon_bridge: vicon_bridge-master/CMakeFiles/vicon_bridge.dir/build.make
devel/lib/vicon_bridge/vicon_bridge: devel/lib/libmsvc_bridge.so
devel/lib/vicon_bridge/vicon_bridge: ../vicon_bridge-master/vicon_sdk/Vicon_SDK_1.3_Linux/64-bit/libViconDataStreamSDK_CPP.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libdynamic_reconfigure_config_init_mutex.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libtf.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libtf2_ros.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libactionlib.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libmessage_filters.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libtf2.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libroscpp.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/librosconsole.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libxmlrpcpp.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libroscpp_serialization.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/librostime.so
devel/lib/vicon_bridge/vicon_bridge: /opt/ros/kinetic/lib/libcpp_common.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/vicon_bridge/vicon_bridge: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
devel/lib/vicon_bridge/vicon_bridge: vicon_bridge-master/CMakeFiles/vicon_bridge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzw/ding/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../devel/lib/vicon_bridge/vicon_bridge"
	cd /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vicon_bridge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vicon_bridge-master/CMakeFiles/vicon_bridge.dir/build: devel/lib/vicon_bridge/vicon_bridge

.PHONY : vicon_bridge-master/CMakeFiles/vicon_bridge.dir/build

vicon_bridge-master/CMakeFiles/vicon_bridge.dir/clean:
	cd /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master && $(CMAKE_COMMAND) -P CMakeFiles/vicon_bridge.dir/cmake_clean.cmake
.PHONY : vicon_bridge-master/CMakeFiles/vicon_bridge.dir/clean

vicon_bridge-master/CMakeFiles/vicon_bridge.dir/depend:
	cd /home/lzw/ding/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzw/ding/src /home/lzw/ding/src/vicon_bridge-master /home/lzw/ding/src/cmake-build-debug /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master /home/lzw/ding/src/cmake-build-debug/vicon_bridge-master/CMakeFiles/vicon_bridge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vicon_bridge-master/CMakeFiles/vicon_bridge.dir/depend

