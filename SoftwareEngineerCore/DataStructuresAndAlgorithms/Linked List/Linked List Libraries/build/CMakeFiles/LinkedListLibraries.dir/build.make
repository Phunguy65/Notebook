# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build"

# Include any dependencies generated for this target.
include CMakeFiles/LinkedListLibraries.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LinkedListLibraries.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkedListLibraries.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkedListLibraries.dir/flags.make

CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o: CMakeFiles/LinkedListLibraries.dir/flags.make
CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o: /home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked\ List/Linked\ List\ Libraries/LinkedListLibraries.cpp
CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o: CMakeFiles/LinkedListLibraries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o -MF CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o.d -o CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o -c "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/LinkedListLibraries.cpp"

CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/LinkedListLibraries.cpp" > CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.i

CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/LinkedListLibraries.cpp" -o CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.s

# Object files for target LinkedListLibraries
LinkedListLibraries_OBJECTS = \
"CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o"

# External object files for target LinkedListLibraries
LinkedListLibraries_EXTERNAL_OBJECTS =

libLinkedListLibraries.a: CMakeFiles/LinkedListLibraries.dir/LinkedListLibraries.cpp.o
libLinkedListLibraries.a: CMakeFiles/LinkedListLibraries.dir/build.make
libLinkedListLibraries.a: CMakeFiles/LinkedListLibraries.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLinkedListLibraries.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LinkedListLibraries.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkedListLibraries.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkedListLibraries.dir/build: libLinkedListLibraries.a
.PHONY : CMakeFiles/LinkedListLibraries.dir/build

CMakeFiles/LinkedListLibraries.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkedListLibraries.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkedListLibraries.dir/clean

CMakeFiles/LinkedListLibraries.dir/depend:
	cd "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries" "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries" "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build" "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build" "/home/PNguyen/Workspace/Notebook/SoftwareEngineerCore/DataStructuresAndAlgorithms/Linked List/Linked List Libraries/build/CMakeFiles/LinkedListLibraries.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/LinkedListLibraries.dir/depend

