set(TARGET server)

find_package(Boost REQUIRED COMPONENTS system)

set(SOURCES
    impl/server_impl.cpp
)

set(LIBRARIES
    ${Boost_LIBRARIES}
)

add_library(${TARGET} SHARED ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
target_include_directories(${TARGET} PRIVATE ${Boost_INCLUDE_DIRS})
