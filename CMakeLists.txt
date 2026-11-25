cmake_minimum_required(VERSION 3.16)

project(GeantIV)

find_package(Geant4 REQUIRED)

include(${Geant4_USE_FILE})

add_executable(GeantIV
 main.cpp
 Detector.cpp
 Generator.cpp
 SteppingAction.cpp
 ActionInitialization.cpp
)

target_link_libraries(GeantIV ${Geant4_LIBRARIES})