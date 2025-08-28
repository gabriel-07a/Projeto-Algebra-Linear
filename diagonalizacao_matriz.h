//
// Created by gabriel on 26/08/2025.
//

#ifndef MAIN_CLION_DIAGONALIZACAO_MATRIZ_H
#define MAIN_CLION_DIAGONALIZACAO_MATRIZ_H
#include "struct_matriz.h"

void resolver_diagonalizacao();
int verficia_diagonalizacao(Matriz matriz, Matriz autovetores, double matriz_diagonalizada[2][2]);
void diagoniza_2x2(Matriz *matriz, Matriz *autovetores, double lambda[2], double matriz_diagonalizada[2][2]);


#endif //MAIN_CLION_DIAGONALIZACAO_MATRIZ_H