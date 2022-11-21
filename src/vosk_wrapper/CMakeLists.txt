add_subdirectory(core)

set(TARGET vosk_test)

set(SOURCES
    main.cpp
)

set(LIBRARIES
    vosk_core
    Qt5::Core
    Qt5::Widgets
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
