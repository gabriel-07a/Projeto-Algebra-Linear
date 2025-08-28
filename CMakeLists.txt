cmake_minimum_required(VERSION 3.31)
project(main_clion C)

set(CMAKE_C_STANDARD 99)

add_executable(main_clion main.c
        sis_lineares.c
        sis_lineares.h
        transformacoes.c
        transformacoes.h
        det_bases.c
        det_bases.h
        diagonalizacao_matriz.c
        diagonalizacao_matriz.h
        autovalores_vetores.c
        autovalores_vetores.h
        struct_matriz.c
        struct_matriz.h)
target_link_libraries(main_clion PRIVATE m)
