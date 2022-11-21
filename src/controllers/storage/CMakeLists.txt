set(TARGET storage)

find_package(SOCI CONFIG REQUIRED)

set(SOURCES
    impl/storage_impl.cpp
)

set(LIBRARIES
    SOCI::soci_core
    SOCI::soci_empty
    SOCI::soci_sqlite3
)

add_library(${TARGET} SHARED ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
