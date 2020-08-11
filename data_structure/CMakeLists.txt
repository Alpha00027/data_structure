cmake_minimum_required(VERSION 3.0.0)
project(data_structure VERSION 0.1.0)

add_library(data_structure STATIC "")
add_library(data_structure::lib ALIAS data_structure)

target_include_directories(data_structure
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(data_structure
PRIVATE
    src/a_cstring.cpp
    src/a_string.cpp
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/a_cstring.h
    ${CMAKE_CURRENT_LIST_DIR}/include/a_string.h
    ${CMAKE_CURRENT_LIST_DIR}/include/a_shared_ptr.h
)

