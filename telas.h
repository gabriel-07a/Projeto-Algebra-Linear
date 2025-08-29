//
// Created by gabriel on 27/08/2025.
//

#ifndef MAIN_CLION_TELAS_H
#define MAIN_CLION_TELAS_H
#include "struct_matriz.h"

void loading();



void exibir_tela_estatica(const char* nome_tela);

//telas para popular matrizes
void funcao_para_polular_matriz_2x2(Matriz *matriz,int nome);
void tela_para_popular_matriz_2x2(double numeroMatriz, int nome, int count);

void verificador(int count, double vetor[]);

void funcao_para_popular_matriz_3x3(Matriz *matriz, int nome);
void tela_para_popular_matriz_3x3(double numeroMatriz, int nome, int count);

//telas para sistemas lineares
//void tela_sis_lineares_para_pegar_tamanho();

//telas para verificações
//void tela_verificacao_para_pegar_dimensoes();
void funcao_para_pegar_as_transformacoes(int linhas, int colunas, Matriz *matriz);
//void tela_para_pegar_as_transformacoes();

//telas para determinação de bases
//void tela_menu_determinacao_de_bases();
//void tela_para_pegar_quant_subconjuntos();
void tela_para_resultado_da_determinante(int numero);

//telas para autovalores e autovetores
void funcao_para_polular_matrizez_para_autovalores(Matriz *matriz,int nome);
void tela_para_resultado_de_autovalore_vetores(double lambda[2], Matriz autovetores);
void tela_para_popular_matrizes_para_autovalores(double numeroMatriz, int nome, int count);

//telas para diagonalização de matrizes
void menuDiagonalizacao2x2(double lambda[2]);

void printa_com_espacos(double num, int largura);
void limpaTela();



#endif //MAIN_CLION_TELAS_H