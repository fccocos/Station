cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(pure_embedding_py LANGUAGES CXX)

# 设置C的标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含python的interpreter libs include
find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

# 探测正确打包的python模块，指定安装位置和版本
execute_process(
    COMMAND
        ${PTYTHON_EXECUTABLE} "-c" "import re, numpy; print(re,compile('/__init__.py.*').sub('',numpy.__file__))"
    RESULT_VARIABLE _numpy_status
    OUTPUT_VARIABLE _numpy_location
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 查看是否找到numpy模块
if(NOT _numpy_status)
    set(NumPy ${_numpy_location} CACHE STRING "Location of NumPy" )
endif()

# 探测NumPy的版本
execute_process(
    COMMAND
        ${PTYTHON_EXECUTABLE} "-c" "import numpy; print(numpy.__version__)"
    OUTPUT_VARIABLE _numpy_version
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 使用FindPackageHandleStandardArgs的CMake包以正确的格式设置NumPy_FOUND 变量和输出信息
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(numpy
    FOUND_VAR numpy_FOUND
    REQUIRED_VARS numpy
    VERSION_VAR _numpy_version
)

add_executable(pure_embedding_py "")

target_sources(pure_embedding_py
    PRIVATE 
       pure_embedding_py.cpp    
    )
target_include_directories(pure_embedding_py
    PRIVATE 
        ${PYTHON_INCLUDE_DIRS}
    )
target_link_libraries(pure_embedding_py
    PRIVATE
        ${PYTHON_LIBRARIES}
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different 
        ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
        ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
    DEPENDS 
        ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
)

target_sources(pure_embedding_py
    PRIVATE
        ${CMKAE_CURRENT_SOURCE_DIR}/use_numpy.py
    )
