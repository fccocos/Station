cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(linear-algebra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMKAE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# find_package(Eigen 3.3 REQUIRED CONFI)

include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-march=native" _march_native_works)
check_cxx_compiler_flag("-xHost" _xhost_works)

set(_CXX_FLAGS )
if(_march_native_works)
    message(STATUS "Using processor's vector instructions (-march=native compiler flag set)")
    set(_CXX_FLAGS "-march=native")
elseif(_xhost_works)
    message(STATUS "Using processor's vector instructions (-xHost compiler flag set)")
    set(_CXX_FLAGS "-xHost")
else()
    message(STATUS "No suitable compiler flag found for vectorization")
endif()

add_executable(linear-algebra-optimaze linear-algebra.cpp)

target_compile_options(linear-algebra-optimaze 
    PRIVATE 
        ${_CXX_FLAGS})