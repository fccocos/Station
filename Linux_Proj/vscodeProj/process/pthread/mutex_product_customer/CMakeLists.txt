cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(mutex_product_customer
    VERSION 1.0.0
    DESCRIPTION "用互斥锁实现生产者和消费者模式"
    HOMEPAGE_URL "www.gunfirefc.top"
    LANGUAGES C 
    )

add_compile_options(-Wall -g)

add_executable(mutex_product_customer mutex_product_customer.c)

target_link_libraries(mutex_product_customer  pthread)
