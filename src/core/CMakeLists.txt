find_library(VOSK libvosk PATHS ${VOSK_DIR})

set(TARGET vosk_server)

set(SOURCES
    main.cpp

    impl/core_impl.cpp
    impl/model_impl.cpp
    impl/listener_impl.cpp
)

set(LIBRARIES
    ${VOSK}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} ${LIBRARIES})
