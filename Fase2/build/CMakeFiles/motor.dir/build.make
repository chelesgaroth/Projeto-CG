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
CMAKE_SOURCE_DIR = "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build"

# Include any dependencies generated for this target.
include CMakeFiles/motor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motor.dir/flags.make

CMakeFiles/motor.dir/src/Motor/motor.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/src/Motor/motor.cpp.o: ../src/Motor/motor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motor.dir/src/Motor/motor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/src/Motor/motor.cpp.o -c "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/src/Motor/motor.cpp"

CMakeFiles/motor.dir/src/Motor/motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/src/Motor/motor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/src/Motor/motor.cpp" > CMakeFiles/motor.dir/src/Motor/motor.cpp.i

CMakeFiles/motor.dir/src/Motor/motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/src/Motor/motor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/src/Motor/motor.cpp" -o CMakeFiles/motor.dir/src/Motor/motor.cpp.s

# Object files for target motor
motor_OBJECTS = \
"CMakeFiles/motor.dir/src/Motor/motor.cpp.o"

# External object files for target motor
motor_EXTERNAL_OBJECTS =

motor: CMakeFiles/motor.dir/src/Motor/motor.cpp.o
motor: CMakeFiles/motor.dir/build.make
motor: libmotorLib.a
motor: libLib.a
motor: libutilsLib.a
motor: /usr/lib/x86_64-linux-gnu/libGL.so
motor: /usr/lib/x86_64-linux-gnu/libGLU.so
motor: /usr/lib/x86_64-linux-gnu/libglut.so
motor: /usr/lib/x86_64-linux-gnu/libXmu.so
motor: /usr/lib/x86_64-linux-gnu/libXi.so
motor: CMakeFiles/motor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable motor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motor.dir/build: motor

.PHONY : CMakeFiles/motor.dir/build

CMakeFiles/motor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motor.dir/clean

CMakeFiles/motor.dir/depend:
	cd "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2" "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2" "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build" "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build" "/home/raquel/Desktop/Universidade/2º Semestre/CG/Projeto-CG/Fase2/build/CMakeFiles/motor.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/motor.dir/depend

