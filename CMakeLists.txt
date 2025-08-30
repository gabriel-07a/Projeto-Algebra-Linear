cmake_minimum_required(VERSION 3.16)
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
        struct_matriz.h
        telas.c
        telas.h)

if(UNIX)
target_link_libraries(main_clion PRIVATE m)
endif()

configure_file(${CMAKE_SOURCE_DIR}/telas_menu.txt
${CMAKE_CURRENT_BINARY_DIR}/telas_menu.txt
COPYONLY)

