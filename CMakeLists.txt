cmake_minimum_required(VERSION 3.31)
project(ME2 C)

set(CMAKE_C_STANDARD 11)

add_executable(ME2 main.c
        Cliente.h
        Cliente.c
        clientee.c
        automoveis.c
        endereco.c
        Automoveis.h
        Automoveiss.c
)
