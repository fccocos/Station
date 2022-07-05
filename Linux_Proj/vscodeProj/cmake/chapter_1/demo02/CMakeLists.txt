# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project(geometry LANGUAGES C CXX)

# # 打印当前标志
# message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# list(APPEND _source 
#         geometry_circle.hpp
#         geometry_circle.cpp
#         geometry_polygon.hpp
#         geometry_polygon.cpp
#         geometry_rhombus.hpp
#         geometry_rhombus.cpp
#         geometry_square.hpp
#         geometry_square.cpp
#     )

# # 对于无法在windows上使用的编译标志我们需要进行处理
# list(APPEND _flags
#         "-fPIC"
#         "-Wall"
#     )
# if(NOT WIN32)
#     list(APPEND _flags "-Wextra" "-Wpedantic")
# endif()

# add_library(geometry STATIC ${_source})

# # 为geometry设置编译选项
# target_compile_options(geometry
#     PRIVATE 
#         ${_flags}
#     )

# add_executable(compute_area compute_area.cpp)

# # 为compute_area设置编译选项
# target_compile_options(compute_area
#     PRIVATE
#         "-fPIC"
#     )

# target_link_libraries(compute_area geometry)
#######################################################

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(geometry LANGUAGES C CXX)
# 打印当前标志
message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")
list(APPEND _source 
        geometry_circle.hpp
        geometry_circle.cpp
        geometry_polygon.hpp
        geometry_polygon.cpp
        geometry_rhombus.hpp
        geometry_rhombus.cpp
        geometry_square.hpp
        geometry_square.cpp
    )
# 通过CMKAE_<LANG>_COMPILER_ID来区别不同的平台
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    list(APPEND CMAKE_CXX_FLAGS "-fno-rtti" "-fno-exceptions")
    list(APPEND CMAKE_CXX_FLAGS_DEBUG 
        "-Wsuggest-final-types" "-Wsuggest-final-methods" "-Wsuggest-override")
    list(APPEND CMAKE_CXX_FLAGS_RELEASE
        "-O3" "-Wno-unused")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    list(APPEND CMAKE_CXX_FLAGS
        "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics")
    list(APPEND CMAKE_CXX_FLAGS_DEBUG
        "-Wdocumentation")
    list(APPEND CMAKE_CXX_FLAGS_RELEASE
        "-o3" "-Wno-unused")
endif()

add_library(geometry STATIC ${_source})
add_executable(compute_area compute_area.cpp)
target_link_libraries(compute_area geometry)