# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake

# Include any dependencies generated for this target.
include CMakeFiles/controls_test_suite.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/controls_test_suite.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/controls_test_suite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/controls_test_suite.dir/flags.make

CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o: CMakeFiles/controls_test_suite.dir/flags.make
CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o: /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c
CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o: CMakeFiles/controls_test_suite.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o -MF CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o.d -o CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o -c /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c

CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c > CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.i

CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c -o CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.s

# Object files for target controls_test_suite
controls_test_suite_OBJECTS = \
"CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o"

# External object files for target controls_test_suite
controls_test_suite_EXTERNAL_OBJECTS =

controls_test_suite: CMakeFiles/controls_test_suite.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/controls_test_suite/controls_test_suite.c.o
controls_test_suite: CMakeFiles/controls_test_suite.dir/build.make
controls_test_suite: /usr/local/lib/libraylib.so
controls_test_suite: CMakeFiles/controls_test_suite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable controls_test_suite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/controls_test_suite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/controls_test_suite.dir/build: controls_test_suite
.PHONY : CMakeFiles/controls_test_suite.dir/build

CMakeFiles/controls_test_suite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/controls_test_suite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/controls_test_suite.dir/clean

CMakeFiles/controls_test_suite.dir/depend:
	cd /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake/CMakeFiles/controls_test_suite.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/controls_test_suite.dir/depend

