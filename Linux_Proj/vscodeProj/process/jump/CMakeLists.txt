cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(jump 
VERSION 1.0.0 
DESCRIPTION "用于实现非局部跳转"
LANGUAGES C)

add_compile_options(-Wall -g2)

add_executable(main main.c)