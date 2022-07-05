cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(optimaze 
VERSION 1.0.0
DESCRIPTION "非局部跳转的优化问题"
HOMEPAGE_URL "www.gunfirefc.top"
LANGUAGES C)
add_compile_options(-Wall -O)
add_executable(optimaze optimaze.c)
