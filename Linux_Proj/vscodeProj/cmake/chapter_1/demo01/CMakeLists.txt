
## 版本一   通过OBJECT对象来构建静态库和动态库
# cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
# project(demo)
# # 构建对象库
# add_library(message-objs 
#     OBJECT 
#         Message.hpp Message.cpp)

# # 设置链接属性，在低版本的cmake中需要
# set_target_properties(message-objs
#     PROPERTIES 
#         POSITION_INDEPENDENT_CODE 1
#                     )

# # 通过对象库来构建静态库
# add_library(message-static
#     STATIC 
#         $<TARGET_OBJECTS:message-objs>
#             )

# add_library(message-shared
#     SHARED
#         $<TARGET_OBJECTS:message-objs>
#             )

# add_executable(main main.cpp)

# target_link_libraries(main message-static)

## 版本二 将Mesage静态库和动态库输出为同名

# cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# project(demo LANGUAGES CXX)

# # 构建对象库
# add_library(message-objs 
#     OBJECT 
#         message.hpp message.cpp)

# set_target_properties(message-objs 
#     PROPERTIES 
#         POSITION_INDEPENDENT_CODE 1)

# # 通过对象库构建共享库
# add_library(message-shared 
#     SHARED
#         $<TARGET_OBJECTS:message-objs>)

# # 将共享库message-shared名字改为message
# set_target_properties(message-shared
#     PROPERTIES
#         OUTPUT_NAME "message")

# # 通过对象库构建静态库
# add_library(message-static
#     STATIC
#         $<TARGET_OBJECTS:message-objs>)

# # 将静态库message-static输出为message

# set_target_properties(message-static
#     PROPERTIES 
#         OUTPUT_NAME "message")

# add_executable(main main.cpp)

# target_link_libraries(main  message-static)
#########################################################################
## 版本三   控制编译流程
# 1. 定义最低cmake版本、项目名称和支持的语言
# cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
# project(demo LANGUAGES CXX)

# # 2. 定义一个变量USE_LIBRARY, 设置为OFF, 并打印输出
# set(USE_LIBRARY OFF) # USE_LIBRARY为一个逻辑变量
# message(STATUS 
#     "Compile suorces into a library?${USE_LIBRARY}")

# # 3. 设置全局变量BUILD_SHARED_LIBS为OFF后，
# #    add_library的第二个省略后，将构建一个静态库
# set(BUILD_SHARED_LIBS OFF) # BUILD_SHARED_LIBS为一个全局的逻辑变量

# # 4. 设置一个列表变量_source, 用来存放message的源代码
# list(APPEND _source Message.hpp Message.cpp)

# # 5. 用if-else语句来控制编译流程
# if(USE_LIBRARY)
#     add_library(message ${_SOURCE})
#     add_executable(main main.cpp)
#     target_link_libraries(main message)
# else()
#     add_executable(main main.cpp ${_source})
# endif()
###########################################################################
# ## 版本4  通过选项变量为用户提供可选的编译方式
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# project(demo)
# # 设置选项变量USE_LIBRARY并初始化为OFF
# option(USE_LIBRARY "Compile sources into a library" OFF)
# # 设置环境变量BUILD_SHARED_LIBS为OFF，此时add_library
# # 的第二参数省略时，默认编译为静态库
# set(BUILD_SHARED_LIBS OFF)
# # 定义一个列表变量，用于存放源文件
# list(APPEND _source Message.hpp Message.cpp)
# # 构建对象库
# add_library(message-objs OBJECT ${_source})
# # 设置目标属性
# set_target_properties(message-objs
#     PROPERTIES
#         POSITION_INDEPENDENT_CODE 1)
# # 用if-else来控制编译流程


# if(USE_LIBRARY)

# # 通过对象库来构建静态库
# add_library(massage-static 
#     $<TARGET_OBJECTS:message-objs>)
# # 设置massage-static的输出名字
# set_target_properties(massage-static
#     PROPERTIES 
#         OUTPUT_NAME "message")
# # 通过对象库构建动态库
# add_library(message-shared 
#     SHARED 
#         $<TARGET_OBJECTS:message-objs>)
# # 设置message-shared的输出名字
# set_target_properties(message-shared 
#     PROPERTIES 
#         OUTPUT_NAME "message")
# # 添加可知文件
# add_executable(main main.cpp)

# # 目标链接库文件
# target_link_libraries(main massage-static)

# else()

# add_executable(main main.cpp ${_source})

# endif()
###############################################################################
# 版本4  通过为选项变量设定依赖来控制编译流程
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# project(demo LANGUAGES CXX)

# set(BUILD_SHARED_LIBS OFF)
# list(APPEND _source Message.hpp Message.cpp)

# option(USE_LIBRARY "Compile sources into libraries" OFF)
# #option(BUILD_SHARED_LIBRARY "Build a shared library" OFF)
# #option(BUILD_STATIC_LIBRARY "Build a static library" OFF)


# # 为BUILD_SHARED_LIBRARY和BUILD_STATIC_LIBRARY构建依赖
# # 将扩展包CmakeDependentOption包含进来
# include(CMakeDependentOption)
# # 为BUILD_SHARED_LIBRARY设置依赖
# cmake_dependent_option(
#     BUILD_SHARED_LIBRARY "Compile sources into a shared library" ON
#     "USE_LIBRARY" ON
# )
# # BUILD_STATIC_LIBRARY构建依赖
# cmake_dependent_option(
#     BUILD_STATIC_LIBRARY "Comile sources into a static library" OFF
#     "USE_LIBRARY" ON
# )

# add_library(message-objs OBJECT ${_source})
# set_target_properties(message-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)

# if(USE_LIBRARY)
#     #构建静态库
#     if(BUILD_STATIC_LIBRARY)
#         add_library(message-static $<TARGET_OBJECTS:message-objs>)
#         set_target_properties(message-static PROPERTIES OUTPUT_NAME "message")
#         add_executable(main-static main.cpp)
#         target_link_libraries(main-static message-static)
#     endif()
#     #构建动态库
#     if(BUILD_SHARED_LIBRARY)
#         add_library(message-shared SHARED $<TARGET_OBJECTS:message-objs>)
#         set_target_properties(message-shared PROPERTIES OUTPUT_NAME "message")
#         add_executable(main-shared main.cpp)
#         target_link_libraries(main-shared message-shared)
#     endif()

# else()
#     add_executable(main main.cpp ${_source})
# endif()
#############################################################################

# 版本5 用与显示额外的编译全局变量 CMAKE_<lang>_compiler_xxx
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# project(cmake_test_version_5 LANGUAGES C CXX)

# # 获取CMAKE_CXX_COMPILER_LOADED的值,并输出
# message(STATUS "Is the C++ compiler loadeds? ${CMAKE_CXX_COMPILER_LOADED}")
# if(CMAKE_CXX_COMPILER_LOADED)
#     message(STATUS "The c++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
#     message(STATUS "Is the c++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
#     message(STATUS "The c++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
# endif()

# # 获取CMAKE_CXX_COMPILER_LOADED的值,并输出
# message(STATUS "Is the C compiler loadeds? ${CMAKE_C_COMPILER_LOADED}")
# if(CMAKE_CXX_COMPILER_LOADED)
#     message(STATUS "The C compiler ID is: ${CMAKE_C_COMPILER_ID}")
#     message(STATUS "Is the C from GNU? ${CMAKE_COMPILER_IS_GNUC  }")
#     message(STATUS "The C compiler version is: ${CMAKE_C_COMPILER_VERSION}")
# endif()

# set(BUILD_SHARED_LIBS OFF)
# list(APPEND _source Message.hpp Message.cpp)

# option(USE_LIBRARY "The compiler into libraries" OFF)
# include(CMakeDependentOption)
# cmake_dependent_option(
#     BUILD_SHARED_LIBRARY "Building a shared library" ON
#     "USE_LIBRARY" ON
# )
# cmake_dependent_option(
#     BUILD_STATIC_LIBRARY "Buiding a static library" OFF
#     "USE_LIBRARY" ON
# )

# add_library(message-objs OBJECT ${_source})
# set_target_properties(message-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)

# if(USE_LIBRARY)
#     if(BUILD_SHARED_LIBRARY)
#         add_library(message-shared SHARED $<TARGET_OBJECTS:message-objs>)
#         set_target_properties(message-shared PROPERTIES OUTPUT_NAME "message")
#         add_executable(main-shared main.cpp)
#         target_link_libraries(main-static mesasge-shared)
#     endif()
#     if(BUILD_STATIC_LIBRARY)
#     add_library(message-static  $<TARGET_OBJECTS:message-objs>)
#     set_target_properties(message-static PROPERTIES OUTPUT_NAME "message")
#     add_executable(main-static main.cpp)
#     target_link_libraries(main-static mesasge-static)
#     endif()
# else()
#     add_executable(main main.cpp ${_source})
# endif()
##############################################################################

# 版本6：设置构建类型并查看请相关设置 cmake_<lang>_flags_构建类型
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(cmake_test_verion_6 LANGUAGES C CXX)

# 通过CMAKE_BUILD_TYPE来设置构建类型
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
# 打印构建类型
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
# 打印出CMAKE设置的对应编译标志
message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGAS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")
message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGAS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

set(BUILD_SHARED_LIBS OFF)
list(APPEND _source Message.hpp Message.cpp)
option(USE_LIBRARY "Compile source into libraries" OFF)
include(CMakeDependentOption)
cmake_dependent_option(
    BUILD_SHARED_LIBRARY "Building a shared library" ON
    "USE_LIBRARY" ON)
cmake_dependent_option(
    BUILD_STATIC_LIBRARY "Building a static library" OFF
    "USE_LIBRARY" ON
)

add_library(message-objs OBJECT ${_source})
set_target_properties(message-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)

if(USE_LIBRARY)
    if(BUILD_SHARED_LIBRARY)
        add_library(message-shared SHARED $<TARGET_OBJECTS:message-objs>)
        set_target_properties(message-shared PROPERTIES OUTPUT_NAME "message")
        add_executable(main-shared main.cpp)
        target_link_libraries(main-shared message-shared)
    endif()
    if(BUILD_STATIC_LIBRARY)
        add_library(message-static $<TARGET_OBJECTS:message-objs>)
        set_target_properties(message-static PROPERTIES OUTPUT_NAME "message")
        add_executable(main-static main.cpp)
        target_link_libraries(main-static message)
    endif()
else()
    add_executable(main main.cpp ${_source})
endif()
#################################################################################