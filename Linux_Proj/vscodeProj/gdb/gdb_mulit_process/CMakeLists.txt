cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(test)

add_compile_options(-g -Wall)

add_executable(multi_process_gdb multi_process_gdb.c)
