set(TARGET gui)

set(SOURCES
    application.cpp
    application.hpp
)

set(LIBRARIES
    Qt5::Widgets
    Qt5::Core
)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)

add_library(${TARGET} SHARED ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})