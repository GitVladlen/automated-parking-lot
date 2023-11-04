set(SOURCES
    main.cpp
)

add_executable(AutomatedParkingLot 
    ${SOURCES}
)

target_link_libraries(AutomatedParkingLot
    APL
)
