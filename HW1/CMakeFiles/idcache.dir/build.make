# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/monkey/inf/slab/HW1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/monkey/inf/slab/HW1

# Include any dependencies generated for this target.
include CMakeFiles/idcache.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/idcache.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/idcache.dir/flags.make

CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.o: CMakeFiles/idcache.dir/flags.make
CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.o: testSys/idealCache/iCache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/monkey/inf/slab/HW1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.o -c /home/monkey/inf/slab/HW1/testSys/idealCache/iCache.cpp

CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/monkey/inf/slab/HW1/testSys/idealCache/iCache.cpp > CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.i

CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/monkey/inf/slab/HW1/testSys/idealCache/iCache.cpp -o CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.s

# Object files for target idcache
idcache_OBJECTS = \
"CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.o"

# External object files for target idcache
idcache_EXTERNAL_OBJECTS =

idcache: CMakeFiles/idcache.dir/testSys/idealCache/iCache.cpp.o
idcache: CMakeFiles/idcache.dir/build.make
idcache: CMakeFiles/idcache.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/monkey/inf/slab/HW1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable idcache"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/idcache.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/idcache.dir/build: idcache

.PHONY : CMakeFiles/idcache.dir/build

CMakeFiles/idcache.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/idcache.dir/cmake_clean.cmake
.PHONY : CMakeFiles/idcache.dir/clean

CMakeFiles/idcache.dir/depend:
	cd /home/monkey/inf/slab/HW1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/monkey/inf/slab/HW1 /home/monkey/inf/slab/HW1 /home/monkey/inf/slab/HW1 /home/monkey/inf/slab/HW1 /home/monkey/inf/slab/HW1/CMakeFiles/idcache.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/idcache.dir/depend

