cmake_minimum_required(VERSION 3.24)
project(myhash C)

set(CMAKE_C_STANDARD 11)

add_executable(myhash_test myhash_test.c myhash.c)