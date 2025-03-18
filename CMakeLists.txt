cmake_minimum_required(VERSION 3.10)

# Set project
project(DLL_Project VERSION 1.0 LANGUAGES C)

# Set C complier
set(CMAKE_C_COMPILER "gcc")

# set source folder variable and add it in directories 
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SRC_DIR})

# collect all source files from from source folder 
set(SOURCES ${SRC_DIR}/main.c ${SRC_DIR}/mydll.c)

#set the executable
add_executable(dll ${SOURCES})

#set target compile options
target_compile_options(dll PRIVATE -Wall -Wextra -Wpedantic)