cmake_minimum_required(VERSION 3.28)
project(matlabc C)

include_directories(matlabc/Inc
)#头文件

file(GLOB_RECURSE SOURCES "matlabc/*.*")#源文件


set(CMAKE_C_STANDARD 11)
add_executable(matlabc main.c ${SOURCES})
