# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build

# Include any dependencies generated for this target.
include CMakeFiles/RTWeekend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RTWeekend.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RTWeekend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RTWeekend.dir/flags.make

CMakeFiles/RTWeekend.dir/main.cpp.obj: CMakeFiles/RTWeekend.dir/flags.make
CMakeFiles/RTWeekend.dir/main.cpp.obj: CMakeFiles/RTWeekend.dir/includes_CXX.rsp
CMakeFiles/RTWeekend.dir/main.cpp.obj: C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/main.cpp
CMakeFiles/RTWeekend.dir/main.cpp.obj: CMakeFiles/RTWeekend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RTWeekend.dir/main.cpp.obj"
	C:\Users\yongpeng.chen\mingw64\mingw64_2\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RTWeekend.dir/main.cpp.obj -MF CMakeFiles\RTWeekend.dir\main.cpp.obj.d -o CMakeFiles\RTWeekend.dir\main.cpp.obj -c C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\main.cpp

CMakeFiles/RTWeekend.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RTWeekend.dir/main.cpp.i"
	C:\Users\yongpeng.chen\mingw64\mingw64_2\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\main.cpp > CMakeFiles\RTWeekend.dir\main.cpp.i

CMakeFiles/RTWeekend.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RTWeekend.dir/main.cpp.s"
	C:\Users\yongpeng.chen\mingw64\mingw64_2\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\main.cpp -o CMakeFiles\RTWeekend.dir\main.cpp.s

CMakeFiles/RTWeekend.dir/camera.cpp.obj: CMakeFiles/RTWeekend.dir/flags.make
CMakeFiles/RTWeekend.dir/camera.cpp.obj: CMakeFiles/RTWeekend.dir/includes_CXX.rsp
CMakeFiles/RTWeekend.dir/camera.cpp.obj: C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/camera.cpp
CMakeFiles/RTWeekend.dir/camera.cpp.obj: CMakeFiles/RTWeekend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RTWeekend.dir/camera.cpp.obj"
	C:\Users\yongpeng.chen\mingw64\mingw64_2\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RTWeekend.dir/camera.cpp.obj -MF CMakeFiles\RTWeekend.dir\camera.cpp.obj.d -o CMakeFiles\RTWeekend.dir\camera.cpp.obj -c C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\camera.cpp

CMakeFiles/RTWeekend.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RTWeekend.dir/camera.cpp.i"
	C:\Users\yongpeng.chen\mingw64\mingw64_2\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\camera.cpp > CMakeFiles\RTWeekend.dir\camera.cpp.i

CMakeFiles/RTWeekend.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RTWeekend.dir/camera.cpp.s"
	C:\Users\yongpeng.chen\mingw64\mingw64_2\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\camera.cpp -o CMakeFiles\RTWeekend.dir\camera.cpp.s

# Object files for target RTWeekend
RTWeekend_OBJECTS = \
"CMakeFiles/RTWeekend.dir/main.cpp.obj" \
"CMakeFiles/RTWeekend.dir/camera.cpp.obj"

# External object files for target RTWeekend
RTWeekend_EXTERNAL_OBJECTS =

C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe: CMakeFiles/RTWeekend.dir/main.cpp.obj
C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe: CMakeFiles/RTWeekend.dir/camera.cpp.obj
C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe: CMakeFiles/RTWeekend.dir/build.make
C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe: CMakeFiles/RTWeekend.dir/linkLibs.rsp
C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe: CMakeFiles/RTWeekend.dir/objects1.rsp
C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe: CMakeFiles/RTWeekend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\z-result.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RTWeekend.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RTWeekend.dir/build: C:/Users/yongpeng.chen/Desktop/ray_tracing_in_one_weekend/ray_tracing_in_one_weekend/z-result.exe
.PHONY : CMakeFiles/RTWeekend.dir/build

CMakeFiles/RTWeekend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RTWeekend.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RTWeekend.dir/clean

CMakeFiles/RTWeekend.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build C:\Users\yongpeng.chen\Desktop\ray_tracing_in_one_weekend\ray_tracing_in_one_weekend\build\CMakeFiles\RTWeekend.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/RTWeekend.dir/depend

