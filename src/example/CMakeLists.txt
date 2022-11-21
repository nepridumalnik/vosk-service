find_library(VOSK libvosk PATHS ${VOSK_DIR})

set(TARGET example)

set(SOURCES example.cpp)

set(LIBRARIES ${VOSK})

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
