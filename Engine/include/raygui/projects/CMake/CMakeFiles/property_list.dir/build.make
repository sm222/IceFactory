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
include CMakeFiles/property_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/property_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/property_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/property_list.dir/flags.make

CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o: CMakeFiles/property_list.dir/flags.make
CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o: /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c
CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o: CMakeFiles/property_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o -MF CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o.d -o CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o -c /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c

CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c > CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.i

CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c -o CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.s

# Object files for target property_list
property_list_OBJECTS = \
"CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o"

# External object files for target property_list
property_list_EXTERNAL_OBJECTS =

property_list: CMakeFiles/property_list.dir/home/antoine/Documents/IceFactory/Engine/include/raygui/examples/property_list/property_list.c.o
property_list: CMakeFiles/property_list.dir/build.make
property_list: /usr/local/lib/libraylib.so
property_list: CMakeFiles/property_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable property_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/property_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/property_list.dir/build: property_list
.PHONY : CMakeFiles/property_list.dir/build

CMakeFiles/property_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/property_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/property_list.dir/clean

CMakeFiles/property_list.dir/depend:
	cd /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake /home/antoine/Documents/IceFactory/Engine/include/raygui/projects/CMake/CMakeFiles/property_list.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/property_list.dir/depend

