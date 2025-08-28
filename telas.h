//
// Created by gabriel on 27/08/2025.
//

#ifndef MAIN_CLION_TELAS_H
#define MAIN_CLION_TELAS_H
#include "struct_matriz.h"

void loading();
void inicializa_titulos(char titulos[][30]);
void limpaVetor(double vetor[], int tam);

//telas para popular matrizes
void funcao_para_polular_matriz_2x2(Matriz *matriz,int nome);
void tela_para_popular_matriz_2x2(double numeroMatriz, int nome, int count);

void funcao_para_popular_matriz_3x3(Matriz *matriz, int nome);
void tela_para_popular_matriz_3x3(double numeroMatriz, int nome, int count);

//telas para sistemas lineares
void tela_sis_lineares_para_pegar_tamanho();

//telas para verificações
void tela_verificacao_para_pegar_dimensoes();
void funcao_para_pegar_as_transformacoes(int linhas, int colunas, Matriz *matriz);
void tela_para_pegar_as_transformacoes();

void print_with_padding(double num, int width);
void limpaTela();
void menuPrincipal();

void Det_basesmenu();
void Det_Resultado(int numero);
void aAtelas(double lambda[2], Matriz autovetores);
void menuDiagonalizacao2x2(double lambda[2]);

#endif //MAIN_CLION_TELAS_H