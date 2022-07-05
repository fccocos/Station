cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(hello-embeded-py LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 查找python解释器，"REQUIRED"表示当前查找的包是必要的
find_package(PythonInterp REQUIRED)

# 查找Python的头文件和库目录, "EXACT"表示限制CMAKE检测指定的版本
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

# 在3.12以上的cmake ，可以使用find_packege的新的python检测模块替换以上两条命令
# find_package(Python COMPONENTS Interpreter Development REQUIRED)

# message(STATUS "Sytem has the Python requested components: ${Python_FOUND}")
# message(STATUS "Sytem has the Python interpreter: ${Python_Interpreter_FOUND}")
# message(STATUS "Path to the Python interpreter: ${Python_EXECUTABLE}")
# message(STATUS "A short stirng unique to the interpreter: ${Python_INTERPRETER_ID}")
# message(STATUS "Standard platform dependent installation directory: ${Python_STDLIB}")
# message(STUATS "Standard platform dependent installation directory: ${Python_STDARCH}")
# message(STATUS "Third-parity platform independent installation directory: ${Python_SITELIB}")
# message(STATUS "Third-party platform dependent installation directory: ${Python_SITEARCH}")
# message(STATUS "System has the Python developments artifacts: ${Python_Development_FOUND}")
# message(STATUS "The Python include directories: ${Python_INCLUDE_DIRS}")
# message(STATUS "The Python library directories: ${Python_LIBRARY_DIRS}")
# message(STATUS "The Python libraries: ${Python_LIBRARIES}")
# message(STATUS "The Python runtiome library directories: ${Python_RUNTIME_LIBRARY_DIRS}")


# 添加一个可执行目标
add_executable(hello-embeded-py hello-embeded-py.c)

# 可执行文件包含python.h
target_include_directories(hello-embeded-py PRIVATE ${PYTHON_INCLUDE_DIRS})

# 将可执行文件连接到Python库
target_link_libraries(hello-embeded-py PRIVATE ${PYTHON_LIBRARIES})


