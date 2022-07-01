cmake_minimum_required(VERSION 3.16)
project(Triple_modular_redundancy C)

set(CMAKE_C_STANDARD 99)

add_executable(Triple_modular_redundancy main.c source.c source.h pipe.c pipe.h sink.c sink.h define.h sink.c sink.h)
