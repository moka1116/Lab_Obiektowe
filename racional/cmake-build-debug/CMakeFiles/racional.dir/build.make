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
CMAKE_SOURCE_DIR = /Users/kamil/CLionProjects/racional

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kamil/CLionProjects/racional/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/racional.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/racional.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/racional.dir/flags.make

CMakeFiles/racional.dir/main.cpp.o: CMakeFiles/racional.dir/flags.make
CMakeFiles/racional.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kamil/CLionProjects/racional/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/racional.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/racional.dir/main.cpp.o -c /Users/kamil/CLionProjects/racional/main.cpp

CMakeFiles/racional.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/racional.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kamil/CLionProjects/racional/main.cpp > CMakeFiles/racional.dir/main.cpp.i

CMakeFiles/racional.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/racional.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kamil/CLionProjects/racional/main.cpp -o CMakeFiles/racional.dir/main.cpp.s

# Object files for target racional
racional_OBJECTS = \
"CMakeFiles/racional.dir/main.cpp.o"

# External object files for target racional
racional_EXTERNAL_OBJECTS =

racional: CMakeFiles/racional.dir/main.cpp.o
racional: CMakeFiles/racional.dir/build.make
racional: CMakeFiles/racional.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kamil/CLionProjects/racional/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable racional"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/racional.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/racional.dir/build: racional

.PHONY : CMakeFiles/racional.dir/build

CMakeFiles/racional.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/racional.dir/cmake_clean.cmake
.PHONY : CMakeFiles/racional.dir/clean

CMakeFiles/racional.dir/depend:
	cd /Users/kamil/CLionProjects/racional/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kamil/CLionProjects/racional /Users/kamil/CLionProjects/racional /Users/kamil/CLionProjects/racional/cmake-build-debug /Users/kamil/CLionProjects/racional/cmake-build-debug /Users/kamil/CLionProjects/racional/cmake-build-debug/CMakeFiles/racional.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/racional.dir/depend

