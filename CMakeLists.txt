CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(big_integer_project)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(big_integer_library SHARED big_integer.h big_integer.cpp)

add_executable(big_integer main.cpp)

target_link_libraries(big_integer big_integer_library)
