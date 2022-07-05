cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(testMsgqueue
    VERSION 1.0.0
    DESCRIPTION "消息队列系统调用的测试"
    HOMEPAGE_URL "www.gunfirefc.top"
    LANGUAGES C
    )

set(SOURCE msgqueue.h msgqueue.c)

add_compile_options(-Wall -g)

find_library(CUNIT NAME cunit PATHS /usr/local/lib NO_DEFAULT_PATH)

add_executable(testMsgqueue testMsgqueue.c ${SOURCE})

target_link_libraries(testMsgqueue ${CUNIT})

