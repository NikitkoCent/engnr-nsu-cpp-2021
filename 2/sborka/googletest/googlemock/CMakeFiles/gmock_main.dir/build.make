# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/artemsmakov/engnr-nsu-cpp-2021/2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka

# Include any dependencies generated for this target.
include googletest/googlemock/CMakeFiles/gmock_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include googletest/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.make

# Include the progress variables for this target.
include googletest/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make

googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: googletest/googlemock/CMakeFiles/gmock_main.dir/flags.make
googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: ../googletest/googlemock/src/gmock_main.cc
googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: googletest/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -MF CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.d -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /Users/artemsmakov/engnr-nsu-cpp-2021/2/googletest/googlemock/src/gmock_main.cc

googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/artemsmakov/engnr-nsu-cpp-2021/2/googletest/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/artemsmakov/engnr-nsu-cpp-2021/2/googletest/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.a: googletest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_main.a: googletest/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.a: googletest/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgmock_main.a"
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.a
.PHONY : googletest/googlemock/CMakeFiles/gmock_main.dir/build

googletest/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : googletest/googlemock/CMakeFiles/gmock_main.dir/clean

googletest/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/artemsmakov/engnr-nsu-cpp-2021/2 /Users/artemsmakov/engnr-nsu-cpp-2021/2/googletest/googlemock /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock /Users/artemsmakov/engnr-nsu-cpp-2021/2/sborka/googletest/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/googlemock/CMakeFiles/gmock_main.dir/depend

