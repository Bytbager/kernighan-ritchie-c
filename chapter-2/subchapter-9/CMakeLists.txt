cmake_minimum_required(VERSION 3.22.1)
project(exercises
        VERSION 1
        DESCRIPTION "Упражения из раздела 2.9"
        HOMEPAGE_URL https://github.com/Bytbager/kernighan-ritchie-c
        LANGUAGES C)
set(CMAKE_C_COMPILER gcc)
add_executable(exercise-1 exercise-1.c)
add_executable(exercise-2 exercise-2.c)
add_executable(exercise-3 exercise-3.c)
