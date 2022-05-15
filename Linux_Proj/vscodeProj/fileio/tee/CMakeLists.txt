cmake_minimum_required(VERSION 2.6)

project(tee)

include_directories("../../lib")

set(SRC_LIST tee.c ../../lib/error_functions.c ../../lib/get_num.c)

add_compile_options(-Wall -g)

add_executable(tee ${SRC_LIST})