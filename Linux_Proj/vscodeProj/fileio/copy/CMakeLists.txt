cmake_minimum_required(VERSION 2.6)

project(copy)

include_directories("../../lib")

set(SRC_LIST copy.c ../../lib/error_functions.c ../../lib/get_num.c)

add_executable(copy ${SRC_LIST})