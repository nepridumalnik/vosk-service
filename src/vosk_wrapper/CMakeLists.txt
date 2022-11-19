add_subdirectory(core)

set(TARGET vosk_test)

set(SOURCES
    main.cpp
)

set(LIBRARIES
    vosk_core
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
