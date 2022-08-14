cmake_minimum_required(VERSION 3.0)

project(crytoMoney CXX)

# add_executable(prog main.c)

set(LIBSRC src/base_algorithms.h src/datastructures.h src/elliptic_curves.h)

add_library(acrodictLib ${LIBSRC})
set_target_properties(acrodictLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(prog src/main.cpp)
target_link_libraries(prog acrodictLib)
# set_target_properties(prog PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(prog PROPERTIES COMPILE_FLAGS "-std=c++17")