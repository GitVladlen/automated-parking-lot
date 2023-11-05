set(HEADERS
    AutomatedParkingLotApp.h
)
set(SOURCES
    AutomatedParkingLotApp.cpp
    main.cpp
)

add_executable(AutomatedParkingLot 
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(AutomatedParkingLot
    APL
)
