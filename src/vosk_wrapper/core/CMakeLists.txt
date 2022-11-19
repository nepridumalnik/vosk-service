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

add_library(${TARGET} SHARED ${SOURCES})
target_link_libraries(${TARGET} PUBLIC ${LIBRARIES})
