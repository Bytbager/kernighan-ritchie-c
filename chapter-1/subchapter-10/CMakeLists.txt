cmake_minimum_required(VERSION 3.22.1)
project(exercises
        VERSION 1
        DESCRIPTION "Упражения из раздела 1.10"
        HOMEPAGE_URL https://github.com/Bytbager/kernighan-ritchie-c
        LANGUAGES C)
set(CMAKE_C_COMPILER gcc)
add_executable(start-program start-program.c)
add_executable(detab exercise-1.c)
add_executable(entab exercise-2.c)
add_executable(exercise-3 exercise-3.c)
add_executable(exercise-4 exercise-4.c)
add_executable(exercise-5 exercise-5.c)