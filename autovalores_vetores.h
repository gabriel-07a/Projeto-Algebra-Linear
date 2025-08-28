//
// Created by gabriel on 26/08/2025.
//

#ifndef MAIN_CLION_AUTOVALORES_VETORES_H
#define MAIN_CLION_AUTOVALORES_VETORES_H
#include "struct_matriz.h"


void resolver_autovalores_autovetores();
void popular_matriz_2x2(Matriz *matriz,int nome);
void aVetorAvalor2();
int calcular_autovalores(double res_autovalores[2],Matriz matriz);
void calcular_autovetor(Matriz matriz, Matriz *autovetores, double lambda[2]);

#endif //MAIN_CLION_AUTOVALORES_VETORES_H