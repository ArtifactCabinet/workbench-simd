cmake_minimum_required(VERSION 3.19)
project(workbench_simd_assembly)

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
else()
    message(FATAL_ERROR "Need GNU gcc" )
endif()

add_executable(main main.cpp)
add_executable(beginner beginner.cpp)
add_executable(simd_vect simd_vect.cpp)
add_executable(detect_intrinsics detect_intrinsics.cpp)