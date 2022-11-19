cmake_minimum_required(VERSION 3.22)
project(vosk)

include(cmake/configure.cmake)

include_directories(src)

add_subdirectory(src)
