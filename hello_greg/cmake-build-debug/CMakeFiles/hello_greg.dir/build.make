# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Samantha\CLionProjects\hello_greg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Samantha\CLionProjects\hello_greg\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hello_greg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_greg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_greg.dir/flags.make

CMakeFiles/hello_greg.dir/main.cpp.obj: CMakeFiles/hello_greg.dir/flags.make
CMakeFiles/hello_greg.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Samantha\CLionProjects\hello_greg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_greg.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hello_greg.dir\main.cpp.obj -c C:\Users\Samantha\CLionProjects\hello_greg\main.cpp

CMakeFiles/hello_greg.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_greg.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Samantha\CLionProjects\hello_greg\main.cpp > CMakeFiles\hello_greg.dir\main.cpp.i

CMakeFiles/hello_greg.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_greg.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Samantha\CLionProjects\hello_greg\main.cpp -o CMakeFiles\hello_greg.dir\main.cpp.s

CMakeFiles/hello_greg.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/hello_greg.dir/main.cpp.obj.requires

CMakeFiles/hello_greg.dir/main.cpp.obj.provides: CMakeFiles/hello_greg.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\hello_greg.dir\build.make CMakeFiles/hello_greg.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/hello_greg.dir/main.cpp.obj.provides

CMakeFiles/hello_greg.dir/main.cpp.obj.provides.build: CMakeFiles/hello_greg.dir/main.cpp.obj


# Object files for target hello_greg
hello_greg_OBJECTS = \
"CMakeFiles/hello_greg.dir/main.cpp.obj"

# External object files for target hello_greg
hello_greg_EXTERNAL_OBJECTS =

hello_greg.exe: CMakeFiles/hello_greg.dir/main.cpp.obj
hello_greg.exe: CMakeFiles/hello_greg.dir/build.make
hello_greg.exe: CMakeFiles/hello_greg.dir/linklibs.rsp
hello_greg.exe: CMakeFiles/hello_greg.dir/objects1.rsp
hello_greg.exe: CMakeFiles/hello_greg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Samantha\CLionProjects\hello_greg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_greg.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hello_greg.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_greg.dir/build: hello_greg.exe

.PHONY : CMakeFiles/hello_greg.dir/build

CMakeFiles/hello_greg.dir/requires: CMakeFiles/hello_greg.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/hello_greg.dir/requires

CMakeFiles/hello_greg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hello_greg.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hello_greg.dir/clean

CMakeFiles/hello_greg.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Samantha\CLionProjects\hello_greg C:\Users\Samantha\CLionProjects\hello_greg C:\Users\Samantha\CLionProjects\hello_greg\cmake-build-debug C:\Users\Samantha\CLionProjects\hello_greg\cmake-build-debug C:\Users\Samantha\CLionProjects\hello_greg\cmake-build-debug\CMakeFiles\hello_greg.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_greg.dir/depend

