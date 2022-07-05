cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(testMyshm 
        VERSION 1.0.0
        DESCRIPTION "共享队列系统调用的测试"
        HOMEPAGE_URL "www.gunfirefc.top"
        LANGUAGES C 
       )   

set(SEMSRC mysem.h mysem.c)
set(SHMSRC Myshm.h Myshm.c)

add_compile_options(-Wall -g)

add_executable(testMyshm testMyshm.c ${SEMSRC} ${SHMSRC})

target_link_libraries(testMyshm cunit)