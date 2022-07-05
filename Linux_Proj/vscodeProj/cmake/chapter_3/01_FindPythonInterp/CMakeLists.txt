cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(findPython LANGUAGES NONE)
# 查找python解释器
find_package(PythonInterp REQUIRED)
# 执行Python命令并捕获他的输出和返回值
execute_process(
    COMMAND
        ${PYTHON_EXECUTABLE} "-c" "print('Hello, world')"
    RESULT_VARIABLE _status
    OUTPUT_VARIABLE _hello_world
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
# 打印Python命令的输出和返回值
message(STATUS "RESULT_VARIABLE is <${_status}>")
message(STATUS "OUTPUT_VARIABLE is <${_hello_world}>")

# 使用CMakePrintHelpers来打印输出变量
include("CMakePrintHelpers")
cmake_print_variables(_status, _hello_world)
