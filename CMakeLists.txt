cmake_minimum_required(VERSION 3.12)
project(AutomatedParkingLot)

# Set the source directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)

# Create a list of source files
set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Vehicle.cpp
    ${SRC_DIR}/Car.cpp
    ${SRC_DIR}/Motorcycle.cpp
    ${SRC_DIR}/Bus.cpp
    ${SRC_DIR}/ParkingLot.cpp
)

# Create a list of header files
set(HEADERS
    ${INCLUDE_DIR}/Constants.h
    ${INCLUDE_DIR}/Utils.h
    ${INCLUDE_DIR}/Vehicle.h
    ${INCLUDE_DIR}/Car.h
    ${INCLUDE_DIR}/Motorcycle.h
    ${INCLUDE_DIR}/Bus.h
    ${INCLUDE_DIR}/ParkingLot.h
)

# Specify the executable
add_executable(AutomatedParkingLot ${SOURCES} ${HEADERS})

# Set the C++ standard and features
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_features(AutomatedParkingLot PRIVATE cxx_std_11)

# Include the 'include' directory for header files
target_include_directories(AutomatedParkingLot PRIVATE ${INCLUDE_DIR})

# Set "AutomatedParkingLot" as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT AutomatedParkingLot)
