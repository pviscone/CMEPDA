cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)

project(Simulation)

find_package(Geant4 REQUIRED ui_all vis_all)


include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(sim sim.cc ${sources} ${headers})
target_link_libraries(sim ${Geant4_LIBRARIES})


#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build B1. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(SCRIPTS
    vis.mac
    analysis.ipynb
    run.mac
    a.sh
    )

foreach(_script ${SCRIPTS})
    configure_file(
        ${PROJECT_SOURCE_DIR}/${_script}
        ${PROJECT_BINARY_DIR}/${_script}
        COPYONLY
    )
endforeach()





add_custom_target(Simulation DEPENDS sim)
