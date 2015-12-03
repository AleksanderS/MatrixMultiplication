#########################
# CMakeLists.txt
# Alex Lindemann
# 11/25/2015
# Matrix Multiplication.
#########################

cmake_minimum_required(VERSION 3.3)
project(MatrixMultiplication)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES main.c Stack.c Stack.h Queue.c Queue.h Postfix.c Postfix.h Integer.c Integer.h FileIO.c FileIO.h)

add_executable(MatrixMultiplication ${SOURCE_FILES} Stack.c Stack.h Postfix.c Postfix.h Integer.c Integer.h FileIO.c FileIO.h)