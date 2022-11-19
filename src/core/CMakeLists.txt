find_library(VOSK libvosk PATHS ${VOSK_DIR})

set(TARGET vosk_core)

set(SOURCES
    impl/core_impl.cpp
    impl/model_impl.cpp
    impl/listener_impl.cpp
)

set(LIBRARIES
    ${VOSK}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${TARGET} SHARED ${SOURCES})
target_link_libraries(${TARGET} PUBLIC ${LIBRARIES})

add_executable(vosk_test main.cpp)
target_link_libraries(vosk_test ${TARGET})
