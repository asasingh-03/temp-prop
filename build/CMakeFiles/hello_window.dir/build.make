# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/asa/Desktop/AR/Project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/asa/Desktop/AR/Project1/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_window.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_window.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_window.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_window.dir/flags.make

CMakeFiles/hello_window.dir/src/main.cpp.o: CMakeFiles/hello_window.dir/flags.make
CMakeFiles/hello_window.dir/src/main.cpp.o: /Users/asa/Desktop/AR/Project1/src/main.cpp
CMakeFiles/hello_window.dir/src/main.cpp.o: CMakeFiles/hello_window.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/asa/Desktop/AR/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_window.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_window.dir/src/main.cpp.o -MF CMakeFiles/hello_window.dir/src/main.cpp.o.d -o CMakeFiles/hello_window.dir/src/main.cpp.o -c /Users/asa/Desktop/AR/Project1/src/main.cpp

CMakeFiles/hello_window.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hello_window.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asa/Desktop/AR/Project1/src/main.cpp > CMakeFiles/hello_window.dir/src/main.cpp.i

CMakeFiles/hello_window.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hello_window.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asa/Desktop/AR/Project1/src/main.cpp -o CMakeFiles/hello_window.dir/src/main.cpp.s

CMakeFiles/hello_window.dir/src/glad.c.o: CMakeFiles/hello_window.dir/flags.make
CMakeFiles/hello_window.dir/src/glad.c.o: /Users/asa/Desktop/AR/Project1/src/glad.c
CMakeFiles/hello_window.dir/src/glad.c.o: CMakeFiles/hello_window.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/asa/Desktop/AR/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hello_window.dir/src/glad.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hello_window.dir/src/glad.c.o -MF CMakeFiles/hello_window.dir/src/glad.c.o.d -o CMakeFiles/hello_window.dir/src/glad.c.o -c /Users/asa/Desktop/AR/Project1/src/glad.c

CMakeFiles/hello_window.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hello_window.dir/src/glad.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/asa/Desktop/AR/Project1/src/glad.c > CMakeFiles/hello_window.dir/src/glad.c.i

CMakeFiles/hello_window.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hello_window.dir/src/glad.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/asa/Desktop/AR/Project1/src/glad.c -o CMakeFiles/hello_window.dir/src/glad.c.s

CMakeFiles/hello_window.dir/src/camera.cpp.o: CMakeFiles/hello_window.dir/flags.make
CMakeFiles/hello_window.dir/src/camera.cpp.o: /Users/asa/Desktop/AR/Project1/src/camera.cpp
CMakeFiles/hello_window.dir/src/camera.cpp.o: CMakeFiles/hello_window.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/asa/Desktop/AR/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hello_window.dir/src/camera.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_window.dir/src/camera.cpp.o -MF CMakeFiles/hello_window.dir/src/camera.cpp.o.d -o CMakeFiles/hello_window.dir/src/camera.cpp.o -c /Users/asa/Desktop/AR/Project1/src/camera.cpp

CMakeFiles/hello_window.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hello_window.dir/src/camera.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asa/Desktop/AR/Project1/src/camera.cpp > CMakeFiles/hello_window.dir/src/camera.cpp.i

CMakeFiles/hello_window.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hello_window.dir/src/camera.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asa/Desktop/AR/Project1/src/camera.cpp -o CMakeFiles/hello_window.dir/src/camera.cpp.s

CMakeFiles/hello_window.dir/src/shaders.cpp.o: CMakeFiles/hello_window.dir/flags.make
CMakeFiles/hello_window.dir/src/shaders.cpp.o: /Users/asa/Desktop/AR/Project1/src/shaders.cpp
CMakeFiles/hello_window.dir/src/shaders.cpp.o: CMakeFiles/hello_window.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/asa/Desktop/AR/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hello_window.dir/src/shaders.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_window.dir/src/shaders.cpp.o -MF CMakeFiles/hello_window.dir/src/shaders.cpp.o.d -o CMakeFiles/hello_window.dir/src/shaders.cpp.o -c /Users/asa/Desktop/AR/Project1/src/shaders.cpp

CMakeFiles/hello_window.dir/src/shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hello_window.dir/src/shaders.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/asa/Desktop/AR/Project1/src/shaders.cpp > CMakeFiles/hello_window.dir/src/shaders.cpp.i

CMakeFiles/hello_window.dir/src/shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hello_window.dir/src/shaders.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/asa/Desktop/AR/Project1/src/shaders.cpp -o CMakeFiles/hello_window.dir/src/shaders.cpp.s

# Object files for target hello_window
hello_window_OBJECTS = \
"CMakeFiles/hello_window.dir/src/main.cpp.o" \
"CMakeFiles/hello_window.dir/src/glad.c.o" \
"CMakeFiles/hello_window.dir/src/camera.cpp.o" \
"CMakeFiles/hello_window.dir/src/shaders.cpp.o"

# External object files for target hello_window
hello_window_EXTERNAL_OBJECTS =

hello_window: CMakeFiles/hello_window.dir/src/main.cpp.o
hello_window: CMakeFiles/hello_window.dir/src/glad.c.o
hello_window: CMakeFiles/hello_window.dir/src/camera.cpp.o
hello_window: CMakeFiles/hello_window.dir/src/shaders.cpp.o
hello_window: CMakeFiles/hello_window.dir/build.make
hello_window: /opt/homebrew/lib/libglfw.3.4.dylib
hello_window: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.1.sdk/System/Library/Frameworks/OpenGL.framework
hello_window: CMakeFiles/hello_window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/asa/Desktop/AR/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable hello_window"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_window.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_window.dir/build: hello_window
.PHONY : CMakeFiles/hello_window.dir/build

CMakeFiles/hello_window.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_window.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_window.dir/clean

CMakeFiles/hello_window.dir/depend:
	cd /Users/asa/Desktop/AR/Project1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/asa/Desktop/AR/Project1 /Users/asa/Desktop/AR/Project1 /Users/asa/Desktop/AR/Project1/build /Users/asa/Desktop/AR/Project1/build /Users/asa/Desktop/AR/Project1/build/CMakeFiles/hello_window.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hello_window.dir/depend
