cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(client_server_mode)

add_compile_options(-Wall -g)

add_executable(client client.c)

add_executable(serv serv.c)