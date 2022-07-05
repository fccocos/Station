cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(testMysem
    VERSION 1.0.0
    DESCRIPTION "消息队列系统调用的测试"
    HOMEPAGE_URL "www.gunfirefc.top"
    LANGUAGES C
    )

set(SOURCE mysem.h mysem.c)

add_compile_options(-Wall -g)

find_library(CUNIT NAME cunit PATHS /usr/local/lib NO_DEFAULT_PATH)

add_executable(testMysem testMysem.c ${SOURCE})

target_link_libraries(testMysem ${CUNIT})

