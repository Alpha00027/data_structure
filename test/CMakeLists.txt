cmake_minimum_required(VERSION 3.0.0)
project(data_structure_test_1 VERSION 0.1.0)

add_executable(data_structure_test "")

#find_package(GTest REQUIRED)

target_include_directories(data_structure_test
PRIVATE    
    #${GTEST_INCLUDE_DIRS}
)

target_sources(data_structure_test 
PRIVATE
    test_a_cstring.cpp
    test_a_string.cpp
)

target_link_libraries(data_structure_test
data_structure::lib
gtest
gtest_main
pthread
)