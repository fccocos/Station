cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(TCP_SCSTLock)

add_compile_options(-Wall -g)

add_executable(cli cli.c)
add_executable(ser ser.c)

target_link_libraries(ser pthread)