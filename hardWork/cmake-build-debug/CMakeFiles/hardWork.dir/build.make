# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kamil/CLionProjects/hardWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kamil/CLionProjects/hardWork/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hardWork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hardWork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hardWork.dir/flags.make

CMakeFiles/hardWork.dir/main.cpp.o: CMakeFiles/hardWork.dir/flags.make
CMakeFiles/hardWork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kamil/CLionProjects/hardWork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hardWork.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hardWork.dir/main.cpp.o -c /Users/kamil/CLionProjects/hardWork/main.cpp

CMakeFiles/hardWork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardWork.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kamil/CLionProjects/hardWork/main.cpp > CMakeFiles/hardWork.dir/main.cpp.i

CMakeFiles/hardWork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardWork.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kamil/CLionProjects/hardWork/main.cpp -o CMakeFiles/hardWork.dir/main.cpp.s

# Object files for target hardWork
hardWork_OBJECTS = \
"CMakeFiles/hardWork.dir/main.cpp.o"

# External object files for target hardWork
hardWork_EXTERNAL_OBJECTS =

hardWork: CMakeFiles/hardWork.dir/main.cpp.o
hardWork: CMakeFiles/hardWork.dir/build.make
hardWork: CMakeFiles/hardWork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kamil/CLionProjects/hardWork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hardWork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hardWork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hardWork.dir/build: hardWork

.PHONY : CMakeFiles/hardWork.dir/build

CMakeFiles/hardWork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hardWork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hardWork.dir/clean

CMakeFiles/hardWork.dir/depend:
	cd /Users/kamil/CLionProjects/hardWork/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kamil/CLionProjects/hardWork /Users/kamil/CLionProjects/hardWork /Users/kamil/CLionProjects/hardWork/cmake-build-debug /Users/kamil/CLionProjects/hardWork/cmake-build-debug /Users/kamil/CLionProjects/hardWork/cmake-build-debug/CMakeFiles/hardWork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hardWork.dir/depend

