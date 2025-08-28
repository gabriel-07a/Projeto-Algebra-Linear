//
// Created by gabriel & andré on 26/08/2025.
//

#ifndef MAIN_CLION_STRUCT_MATRIZ_H
#define MAIN_CLION_STRUCT_MATRIZ_H

typedef struct {
    int linhas;
    int colunas;
    double **dados;
} Matriz;

Matriz criar_matriz(int linhas, int colunas);
void destruir_matriz(Matriz *matriz);
void imprimir_matriz(Matriz m);
Matriz copia_matriz(Matriz matriz_original);

#endif //MAIN_CLION_STRUCT_MATRIZ_H