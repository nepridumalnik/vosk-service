set(TARGET application)

set(SOURCES
    main.cpp
)

set(LIBRARIES
    Qt5::Widgets
    gui
)

find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
