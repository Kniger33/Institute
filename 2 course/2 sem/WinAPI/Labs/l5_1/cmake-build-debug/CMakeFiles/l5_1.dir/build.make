# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\vscho\CLionProjects\l5_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\vscho\CLionProjects\l5_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/l5_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/l5_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/l5_1.dir/flags.make

CMakeFiles/l5_1.dir/main.cpp.obj: CMakeFiles/l5_1.dir/flags.make
CMakeFiles/l5_1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vscho\CLionProjects\l5_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/l5_1.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\l5_1.dir\main.cpp.obj -c C:\Users\vscho\CLionProjects\l5_1\main.cpp

CMakeFiles/l5_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l5_1.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vscho\CLionProjects\l5_1\main.cpp > CMakeFiles\l5_1.dir\main.cpp.i

CMakeFiles/l5_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l5_1.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vscho\CLionProjects\l5_1\main.cpp -o CMakeFiles\l5_1.dir\main.cpp.s

# Object files for target l5_1
l5_1_OBJECTS = \
"CMakeFiles/l5_1.dir/main.cpp.obj"

# External object files for target l5_1
l5_1_EXTERNAL_OBJECTS =

l5_1.exe: CMakeFiles/l5_1.dir/main.cpp.obj
l5_1.exe: CMakeFiles/l5_1.dir/build.make
l5_1.exe: CMakeFiles/l5_1.dir/linklibs.rsp
l5_1.exe: CMakeFiles/l5_1.dir/objects1.rsp
l5_1.exe: CMakeFiles/l5_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\vscho\CLionProjects\l5_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable l5_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\l5_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/l5_1.dir/build: l5_1.exe

.PHONY : CMakeFiles/l5_1.dir/build

CMakeFiles/l5_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\l5_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/l5_1.dir/clean

CMakeFiles/l5_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\vscho\CLionProjects\l5_1 C:\Users\vscho\CLionProjects\l5_1 C:\Users\vscho\CLionProjects\l5_1\cmake-build-debug C:\Users\vscho\CLionProjects\l5_1\cmake-build-debug C:\Users\vscho\CLionProjects\l5_1\cmake-build-debug\CMakeFiles\l5_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/l5_1.dir/depend
