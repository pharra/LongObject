# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "D:\Program Files (x86)\apps\CLion\ch-0\172.3968.17\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\apps\CLion\ch-0\172.3968.17\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\WF\CLionProjects\factorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\WF\CLionProjects\factorial\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/factorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/factorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/factorial.dir/flags.make

CMakeFiles/factorial.dir/main.cpp.obj: CMakeFiles/factorial.dir/flags.make
CMakeFiles/factorial.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WF\CLionProjects\factorial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/factorial.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\factorial.dir\main.cpp.obj -c C:\Users\WF\CLionProjects\factorial\main.cpp

CMakeFiles/factorial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/factorial.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WF\CLionProjects\factorial\main.cpp > CMakeFiles\factorial.dir\main.cpp.i

CMakeFiles/factorial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/factorial.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WF\CLionProjects\factorial\main.cpp -o CMakeFiles\factorial.dir\main.cpp.s

CMakeFiles/factorial.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/factorial.dir/main.cpp.obj.requires

CMakeFiles/factorial.dir/main.cpp.obj.provides: CMakeFiles/factorial.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\factorial.dir\build.make CMakeFiles/factorial.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/factorial.dir/main.cpp.obj.provides

CMakeFiles/factorial.dir/main.cpp.obj.provides.build: CMakeFiles/factorial.dir/main.cpp.obj


CMakeFiles/factorial.dir/LongObject.cpp.obj: CMakeFiles/factorial.dir/flags.make
CMakeFiles/factorial.dir/LongObject.cpp.obj: ../LongObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WF\CLionProjects\factorial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/factorial.dir/LongObject.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\factorial.dir\LongObject.cpp.obj -c C:\Users\WF\CLionProjects\factorial\LongObject.cpp

CMakeFiles/factorial.dir/LongObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/factorial.dir/LongObject.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WF\CLionProjects\factorial\LongObject.cpp > CMakeFiles\factorial.dir\LongObject.cpp.i

CMakeFiles/factorial.dir/LongObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/factorial.dir/LongObject.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WF\CLionProjects\factorial\LongObject.cpp -o CMakeFiles\factorial.dir\LongObject.cpp.s

CMakeFiles/factorial.dir/LongObject.cpp.obj.requires:

.PHONY : CMakeFiles/factorial.dir/LongObject.cpp.obj.requires

CMakeFiles/factorial.dir/LongObject.cpp.obj.provides: CMakeFiles/factorial.dir/LongObject.cpp.obj.requires
	$(MAKE) -f CMakeFiles\factorial.dir\build.make CMakeFiles/factorial.dir/LongObject.cpp.obj.provides.build
.PHONY : CMakeFiles/factorial.dir/LongObject.cpp.obj.provides

CMakeFiles/factorial.dir/LongObject.cpp.obj.provides.build: CMakeFiles/factorial.dir/LongObject.cpp.obj


CMakeFiles/factorial.dir/IntBlockManager.cpp.obj: CMakeFiles/factorial.dir/flags.make
CMakeFiles/factorial.dir/IntBlockManager.cpp.obj: ../IntBlockManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WF\CLionProjects\factorial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/factorial.dir/IntBlockManager.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\factorial.dir\IntBlockManager.cpp.obj -c C:\Users\WF\CLionProjects\factorial\IntBlockManager.cpp

CMakeFiles/factorial.dir/IntBlockManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/factorial.dir/IntBlockManager.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WF\CLionProjects\factorial\IntBlockManager.cpp > CMakeFiles\factorial.dir\IntBlockManager.cpp.i

CMakeFiles/factorial.dir/IntBlockManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/factorial.dir/IntBlockManager.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WF\CLionProjects\factorial\IntBlockManager.cpp -o CMakeFiles\factorial.dir\IntBlockManager.cpp.s

CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.requires:

.PHONY : CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.requires

CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.provides: CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.requires
	$(MAKE) -f CMakeFiles\factorial.dir\build.make CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.provides.build
.PHONY : CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.provides

CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.provides.build: CMakeFiles/factorial.dir/IntBlockManager.cpp.obj


# Object files for target factorial
factorial_OBJECTS = \
"CMakeFiles/factorial.dir/main.cpp.obj" \
"CMakeFiles/factorial.dir/LongObject.cpp.obj" \
"CMakeFiles/factorial.dir/IntBlockManager.cpp.obj"

# External object files for target factorial
factorial_EXTERNAL_OBJECTS =

factorial.exe: CMakeFiles/factorial.dir/main.cpp.obj
factorial.exe: CMakeFiles/factorial.dir/LongObject.cpp.obj
factorial.exe: CMakeFiles/factorial.dir/IntBlockManager.cpp.obj
factorial.exe: CMakeFiles/factorial.dir/build.make
factorial.exe: CMakeFiles/factorial.dir/linklibs.rsp
factorial.exe: CMakeFiles/factorial.dir/objects1.rsp
factorial.exe: CMakeFiles/factorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\WF\CLionProjects\factorial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable factorial.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\factorial.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/factorial.dir/build: factorial.exe

.PHONY : CMakeFiles/factorial.dir/build

CMakeFiles/factorial.dir/requires: CMakeFiles/factorial.dir/main.cpp.obj.requires
CMakeFiles/factorial.dir/requires: CMakeFiles/factorial.dir/LongObject.cpp.obj.requires
CMakeFiles/factorial.dir/requires: CMakeFiles/factorial.dir/IntBlockManager.cpp.obj.requires

.PHONY : CMakeFiles/factorial.dir/requires

CMakeFiles/factorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\factorial.dir\cmake_clean.cmake
.PHONY : CMakeFiles/factorial.dir/clean

CMakeFiles/factorial.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\WF\CLionProjects\factorial C:\Users\WF\CLionProjects\factorial C:\Users\WF\CLionProjects\factorial\cmake-build-debug C:\Users\WF\CLionProjects\factorial\cmake-build-debug C:\Users\WF\CLionProjects\factorial\cmake-build-debug\CMakeFiles\factorial.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/factorial.dir/depend
