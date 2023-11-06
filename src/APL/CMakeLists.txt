# Set the source directories
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/APL)

# Create a list of source files
set(SOURCES
    ${SRC_DIR}/Logger.cpp
    ${SRC_DIR}/Vehicle.cpp
    ${SRC_DIR}/Car.cpp
    ${SRC_DIR}/Motorcycle.cpp
    ${SRC_DIR}/Bus.cpp
    ${SRC_DIR}/ParkingLot.cpp
)

# Create a list of header files
set(HEADERS
    ${INCLUDE_DIR}/Constants.h
    ${INCLUDE_DIR}/UniqueIDGenerator.h
    ${INCLUDE_DIR}/Logger.h
    ${INCLUDE_DIR}/Exceptions.h
    ${INCLUDE_DIR}/Vehicle.h
    ${INCLUDE_DIR}/Car.h
    ${INCLUDE_DIR}/Motorcycle.h
    ${INCLUDE_DIR}/Bus.h
    ${INCLUDE_DIR}/ParkingLot.h
)

add_library(APL ${SOURCES} ${HEADERS})

target_include_directories(APL PUBLIC include)
