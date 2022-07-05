cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(server_select)
add_compile_options(-Wall -g)
add_executable(client client.c)
add_executable(server server.c)

