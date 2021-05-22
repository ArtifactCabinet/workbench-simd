cmake_minimum_required(VERSION 3.19)
project(workbench_simd_assembly)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-mmmx    \
                                        -msse    \
                                        -msse2   \
                                        -msse3   \
                                        -mssse3  \
                                        -msse4   \
                                        -msse4a  \
                                        -msse4.1 \
                                        -msse4.2 \
                                        -mavx    \
                                        -mavx2")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
else()
    message(FATAL_ERROR "Need GNU gcc" )
endif()

add_executable(main main.cpp)
add_executable(beginner beginner.cpp)
add_executable(simd_vect simd_vect.cpp)
add_executable(detect_intrinsics detect_intrinsics.cpp)