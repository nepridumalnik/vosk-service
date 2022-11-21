set(TARGET server)

set(SOURCES
    impl/server_impl.cpp
)

set(LIBRARIES
)

add_library(${TARGET} SHARED ${SOURCES})
target_link_libraries(${TARGET} PUBLIC ${LIBRARIES})
