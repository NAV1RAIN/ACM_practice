# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\ACM\2019ACM\poj2251

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\ACM\2019ACM\poj2251\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/poj2251.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/poj2251.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/poj2251.dir/flags.make

CMakeFiles/poj2251.dir/main.cpp.obj: CMakeFiles/poj2251.dir/flags.make
CMakeFiles/poj2251.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\ACM\2019ACM\poj2251\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/poj2251.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\poj2251.dir\main.cpp.obj -c F:\ACM\2019ACM\poj2251\main.cpp

CMakeFiles/poj2251.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/poj2251.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\ACM\2019ACM\poj2251\main.cpp > CMakeFiles\poj2251.dir\main.cpp.i

CMakeFiles/poj2251.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/poj2251.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\ACM\2019ACM\poj2251\main.cpp -o CMakeFiles\poj2251.dir\main.cpp.s

# Object files for target poj2251
poj2251_OBJECTS = \
"CMakeFiles/poj2251.dir/main.cpp.obj"

# External object files for target poj2251
poj2251_EXTERNAL_OBJECTS =

poj2251.exe: CMakeFiles/poj2251.dir/main.cpp.obj
poj2251.exe: CMakeFiles/poj2251.dir/build.make
poj2251.exe: CMakeFiles/poj2251.dir/linklibs.rsp
poj2251.exe: CMakeFiles/poj2251.dir/objects1.rsp
poj2251.exe: CMakeFiles/poj2251.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\ACM\2019ACM\poj2251\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable poj2251.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\poj2251.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/poj2251.dir/build: poj2251.exe

.PHONY : CMakeFiles/poj2251.dir/build

CMakeFiles/poj2251.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\poj2251.dir\cmake_clean.cmake
.PHONY : CMakeFiles/poj2251.dir/clean

CMakeFiles/poj2251.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\ACM\2019ACM\poj2251 F:\ACM\2019ACM\poj2251 F:\ACM\2019ACM\poj2251\cmake-build-debug F:\ACM\2019ACM\poj2251\cmake-build-debug F:\ACM\2019ACM\poj2251\cmake-build-debug\CMakeFiles\poj2251.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/poj2251.dir/depend

