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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/paikwiki/codes/42cursus/raycasting-lodev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/raycasting_lodev.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raycasting_lodev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raycasting_lodev.dir/flags.make

CMakeFiles/raycasting_lodev.dir/main.c.o: CMakeFiles/raycasting_lodev.dir/flags.make
CMakeFiles/raycasting_lodev.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/raycasting_lodev.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/raycasting_lodev.dir/main.c.o   -c /Users/paikwiki/codes/42cursus/raycasting-lodev/main.c

CMakeFiles/raycasting_lodev.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raycasting_lodev.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/paikwiki/codes/42cursus/raycasting-lodev/main.c > CMakeFiles/raycasting_lodev.dir/main.c.i

CMakeFiles/raycasting_lodev.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raycasting_lodev.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/paikwiki/codes/42cursus/raycasting-lodev/main.c -o CMakeFiles/raycasting_lodev.dir/main.c.s

# Object files for target raycasting_lodev
raycasting_lodev_OBJECTS = \
"CMakeFiles/raycasting_lodev.dir/main.c.o"

# External object files for target raycasting_lodev
raycasting_lodev_EXTERNAL_OBJECTS =

raycasting_lodev: CMakeFiles/raycasting_lodev.dir/main.c.o
raycasting_lodev: CMakeFiles/raycasting_lodev.dir/build.make
raycasting_lodev: CMakeFiles/raycasting_lodev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable raycasting_lodev"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raycasting_lodev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raycasting_lodev.dir/build: raycasting_lodev

.PHONY : CMakeFiles/raycasting_lodev.dir/build

CMakeFiles/raycasting_lodev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raycasting_lodev.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raycasting_lodev.dir/clean

CMakeFiles/raycasting_lodev.dir/depend:
	cd /Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/paikwiki/codes/42cursus/raycasting-lodev /Users/paikwiki/codes/42cursus/raycasting-lodev /Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug /Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug /Users/paikwiki/codes/42cursus/raycasting-lodev/cmake-build-debug/CMakeFiles/raycasting_lodev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raycasting_lodev.dir/depend

