cmake_minimum_required(VERSION 3.22.1)
project(exercises
        VERSION 1
        DESCRIPTION "Упражения из раздела 1.5.4"
        HOMEPAGE_URL https://github.com/Bytbager/kernighan-ritchie-c
        LANGUAGES C)
set(CMAKE_C_COMPILER gcc)
add_executable(start-program start-program.c)
add_executable(exercise-2 exercise-2.c)
