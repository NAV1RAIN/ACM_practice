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
CMAKE_SOURCE_DIR = F:\ACM\2019ACM\cf1156A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\ACM\2019ACM\cf1156A\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cf1156A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cf1156A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cf1156A.dir/flags.make

CMakeFiles/cf1156A.dir/main.cpp.obj: CMakeFiles/cf1156A.dir/flags.make
CMakeFiles/cf1156A.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\ACM\2019ACM\cf1156A\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cf1156A.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cf1156A.dir\main.cpp.obj -c F:\ACM\2019ACM\cf1156A\main.cpp

CMakeFiles/cf1156A.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf1156A.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\ACM\2019ACM\cf1156A\main.cpp > CMakeFiles\cf1156A.dir\main.cpp.i

CMakeFiles/cf1156A.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf1156A.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\ACM\2019ACM\cf1156A\main.cpp -o CMakeFiles\cf1156A.dir\main.cpp.s

# Object files for target cf1156A
cf1156A_OBJECTS = \
"CMakeFiles/cf1156A.dir/main.cpp.obj"

# External object files for target cf1156A
cf1156A_EXTERNAL_OBJECTS =

cf1156A.exe: CMakeFiles/cf1156A.dir/main.cpp.obj
cf1156A.exe: CMakeFiles/cf1156A.dir/build.make
cf1156A.exe: CMakeFiles/cf1156A.dir/linklibs.rsp
cf1156A.exe: CMakeFiles/cf1156A.dir/objects1.rsp
cf1156A.exe: CMakeFiles/cf1156A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\ACM\2019ACM\cf1156A\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cf1156A.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cf1156A.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cf1156A.dir/build: cf1156A.exe

.PHONY : CMakeFiles/cf1156A.dir/build

CMakeFiles/cf1156A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cf1156A.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cf1156A.dir/clean

CMakeFiles/cf1156A.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\ACM\2019ACM\cf1156A F:\ACM\2019ACM\cf1156A F:\ACM\2019ACM\cf1156A\cmake-build-debug F:\ACM\2019ACM\cf1156A\cmake-build-debug F:\ACM\2019ACM\cf1156A\cmake-build-debug\CMakeFiles\cf1156A.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cf1156A.dir/depend

