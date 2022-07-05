cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(environ LANGUAGES C)

add_compile_options(-Wall -g2)

add_executable(main main.c)