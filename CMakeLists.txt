cmake_minimum_required(VERSION 3.0)

project(crytoMoney CXX)

# add_executable(prog main.c)

set(LIBSRC src/base_algorithms.h src/datastructures.h src/elliptic_curves.h)

add_library(acrodictLib ${LIBSRC}) # create library acroditclib with a list of h files
set_target_properties(acrodictLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(prog src/main.cpp) # prog is the executable from main.cpp
target_link_libraries(prog acrodictLib) # link prog executable with acrodictLib
# set_target_properties(prog PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(prog PROPERTIES COMPILE_FLAGS "-std=c++17")