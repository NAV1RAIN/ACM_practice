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
CMAKE_SOURCE_DIR = "F:\ACM\2019ACM\Constructing Roads"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\ACM\2019ACM\Constructing Roads\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Constructing_Roads.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Constructing_Roads.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Constructing_Roads.dir/flags.make

CMakeFiles/Constructing_Roads.dir/main.cpp.obj: CMakeFiles/Constructing_Roads.dir/flags.make
CMakeFiles/Constructing_Roads.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\ACM\2019ACM\Constructing Roads\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Constructing_Roads.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Constructing_Roads.dir\main.cpp.obj -c "F:\ACM\2019ACM\Constructing Roads\main.cpp"

CMakeFiles/Constructing_Roads.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Constructing_Roads.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\ACM\2019ACM\Constructing Roads\main.cpp" > CMakeFiles\Constructing_Roads.dir\main.cpp.i

CMakeFiles/Constructing_Roads.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Constructing_Roads.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\ACM\2019ACM\Constructing Roads\main.cpp" -o CMakeFiles\Constructing_Roads.dir\main.cpp.s

# Object files for target Constructing_Roads
Constructing_Roads_OBJECTS = \
"CMakeFiles/Constructing_Roads.dir/main.cpp.obj"

# External object files for target Constructing_Roads
Constructing_Roads_EXTERNAL_OBJECTS =

Constructing_Roads.exe: CMakeFiles/Constructing_Roads.dir/main.cpp.obj
Constructing_Roads.exe: CMakeFiles/Constructing_Roads.dir/build.make
Constructing_Roads.exe: CMakeFiles/Constructing_Roads.dir/linklibs.rsp
Constructing_Roads.exe: CMakeFiles/Constructing_Roads.dir/objects1.rsp
Constructing_Roads.exe: CMakeFiles/Constructing_Roads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\ACM\2019ACM\Constructing Roads\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Constructing_Roads.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Constructing_Roads.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Constructing_Roads.dir/build: Constructing_Roads.exe

.PHONY : CMakeFiles/Constructing_Roads.dir/build

CMakeFiles/Constructing_Roads.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Constructing_Roads.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Constructing_Roads.dir/clean

CMakeFiles/Constructing_Roads.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\ACM\2019ACM\Constructing Roads" "F:\ACM\2019ACM\Constructing Roads" "F:\ACM\2019ACM\Constructing Roads\cmake-build-debug" "F:\ACM\2019ACM\Constructing Roads\cmake-build-debug" "F:\ACM\2019ACM\Constructing Roads\cmake-build-debug\CMakeFiles\Constructing_Roads.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Constructing_Roads.dir/depend

