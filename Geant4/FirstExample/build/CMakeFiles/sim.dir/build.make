# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/sim.cc.o: ../sim.cc
CMakeFiles/sim.dir/sim.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/sim.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/sim.cc.o -MF CMakeFiles/sim.dir/sim.cc.o.d -o CMakeFiles/sim.dir/sim.cc.o -c /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/sim.cc

CMakeFiles/sim.dir/sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/sim.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/sim.cc > CMakeFiles/sim.dir/sim.cc.i

CMakeFiles/sim.dir/sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/sim.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/sim.cc -o CMakeFiles/sim.dir/sim.cc.s

CMakeFiles/sim.dir/src/action.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/action.cc.o: ../src/action.cc
CMakeFiles/sim.dir/src/action.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim.dir/src/action.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/src/action.cc.o -MF CMakeFiles/sim.dir/src/action.cc.o.d -o CMakeFiles/sim.dir/src/action.cc.o -c /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/action.cc

CMakeFiles/sim.dir/src/action.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/action.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/action.cc > CMakeFiles/sim.dir/src/action.cc.i

CMakeFiles/sim.dir/src/action.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/action.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/action.cc -o CMakeFiles/sim.dir/src/action.cc.s

CMakeFiles/sim.dir/src/construction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/construction.cc.o: ../src/construction.cc
CMakeFiles/sim.dir/src/construction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim.dir/src/construction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/src/construction.cc.o -MF CMakeFiles/sim.dir/src/construction.cc.o.d -o CMakeFiles/sim.dir/src/construction.cc.o -c /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/construction.cc

CMakeFiles/sim.dir/src/construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/construction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/construction.cc > CMakeFiles/sim.dir/src/construction.cc.i

CMakeFiles/sim.dir/src/construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/construction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/construction.cc -o CMakeFiles/sim.dir/src/construction.cc.s

CMakeFiles/sim.dir/src/generator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/generator.cc.o: ../src/generator.cc
CMakeFiles/sim.dir/src/generator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim.dir/src/generator.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/src/generator.cc.o -MF CMakeFiles/sim.dir/src/generator.cc.o.d -o CMakeFiles/sim.dir/src/generator.cc.o -c /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/generator.cc

CMakeFiles/sim.dir/src/generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/generator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/generator.cc > CMakeFiles/sim.dir/src/generator.cc.i

CMakeFiles/sim.dir/src/generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/generator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/generator.cc -o CMakeFiles/sim.dir/src/generator.cc.s

CMakeFiles/sim.dir/src/physics.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/physics.cc.o: ../src/physics.cc
CMakeFiles/sim.dir/src/physics.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sim.dir/src/physics.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/src/physics.cc.o -MF CMakeFiles/sim.dir/src/physics.cc.o.d -o CMakeFiles/sim.dir/src/physics.cc.o -c /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/physics.cc

CMakeFiles/sim.dir/src/physics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/physics.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/physics.cc > CMakeFiles/sim.dir/src/physics.cc.i

CMakeFiles/sim.dir/src/physics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/physics.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/src/physics.cc -o CMakeFiles/sim.dir/src/physics.cc.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/sim.cc.o" \
"CMakeFiles/sim.dir/src/action.cc.o" \
"CMakeFiles/sim.dir/src/construction.cc.o" \
"CMakeFiles/sim.dir/src/generator.cc.o" \
"CMakeFiles/sim.dir/src/physics.cc.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/sim.cc.o
sim: CMakeFiles/sim.dir/src/action.cc.o
sim: CMakeFiles/sim.dir/src/construction.cc.o
sim: CMakeFiles/sim.dir/src/generator.cc.o
sim: CMakeFiles/sim.dir/src/physics.cc.o
sim: CMakeFiles/sim.dir/build.make
sim: /usr/lib/libG4Tree.so
sim: /usr/lib/libG4FR.so
sim: /usr/lib/libG4GMocren.so
sim: /usr/lib/libG4visHepRep.so
sim: /usr/lib/libG4RayTracer.so
sim: /usr/lib/libG4VRML.so
sim: /usr/lib/libG4OpenGL.so
sim: /usr/lib/libG4visQt3D.so
sim: /usr/lib/libG4OpenInventor.so
sim: /usr/lib/libG4ToolsSG.so
sim: /usr/lib/libG4vis_management.so
sim: /usr/lib/libG4modeling.so
sim: /usr/lib/libG4interfaces.so
sim: /usr/lib/libG4persistency.so
sim: /usr/lib/libG4error_propagation.so
sim: /usr/lib/libG4readout.so
sim: /usr/lib/libG4physicslists.so
sim: /usr/lib/libG4tasking.so
sim: /usr/lib/libG4parmodels.so
sim: /usr/lib/libQt53DExtras.so.5.15.4
sim: /usr/lib/libQt53DInput.so.5.15.4
sim: /usr/lib/libQt53DLogic.so.5.15.4
sim: /usr/lib/libQt53DRender.so.5.15.4
sim: /usr/lib/libQt53DCore.so.5.15.4
sim: /usr/lib/libQt5Network.so.5.15.4
sim: /usr/lib/libG4gl2ps.so
sim: /usr/lib/libSoQt.so.1.6.0
sim: /usr/lib/libCoin.so.4.0.1
sim: /usr/lib/libOpenGL.so
sim: /usr/lib/libGLX.so
sim: /usr/lib/libSM.so
sim: /usr/lib/libICE.so
sim: /usr/lib/libX11.so
sim: /usr/lib/libXext.so
sim: /usr/lib/libXi.so
sim: /usr/lib/libXmu.so
sim: /usr/lib/libXext.so
sim: /usr/lib/libXm.so
sim: /usr/lib/libXt.so
sim: /usr/lib/libICE.so
sim: /usr/lib/libSM.so
sim: /usr/lib/libX11.so
sim: /usr/lib/libGL.so
sim: /usr/lib/libQt5OpenGL.so.5.15.4
sim: /usr/lib/libQt5PrintSupport.so.5.15.4
sim: /usr/lib/libQt5Widgets.so.5.15.4
sim: /usr/lib/libQt5Gui.so.5.15.4
sim: /usr/lib/libQt5Core.so.5.15.4
sim: /usr/lib/libxerces-c.so
sim: /usr/lib/libG4run.so
sim: /usr/lib/libG4event.so
sim: /usr/lib/libG4tracking.so
sim: /usr/lib/libG4processes.so
sim: /usr/lib/libG4analysis.so
sim: /usr/lib/libG4tools.so
sim: /usr/lib/libz.so
sim: /usr/lib/libexpat.so
sim: /usr/lib/libG4digits_hits.so
sim: /usr/lib/libG4track.so
sim: /usr/lib/libG4particles.so
sim: /usr/lib/libG4geometry.so
sim: /usr/lib/libG4materials.so
sim: /usr/lib/libG4graphics_reps.so
sim: /usr/lib/libG4intercoms.so
sim: /usr/lib/libG4global.so
sim: /usr/lib/libG4clhep.so
sim: /usr/lib/libG4ptl.so.0.0.2
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim
.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build /home/pviscone/Desktop/CMEPDA/Geant4/FirstExample/build/CMakeFiles/sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sim.dir/depend

