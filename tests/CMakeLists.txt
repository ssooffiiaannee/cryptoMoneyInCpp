cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests test_ec.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} ) #phthread)