//
// Created by gabriel on 27/08/2025.
//

#ifndef MAIN_CLION_TELAS_H
#define MAIN_CLION_TELAS_H

void loading();
void inicializa_titulos(char titulos[][30]);
void limpaVetor(double vetor[], int tam);
void print_with_padding(double num, int width);
void limpaTela();
void menuPrincipal();
void doisTela(double numeroMatriz, int nome);
void tresTela(double numeroMatriz, int nome);
void Det_basesmenu();
void Det_Resultado(int numero);
void aAtelas(double lambda[2], double autovetores[2][2]);
void menuDiagonalizacao2x2(double lambda[2]);

#endif //MAIN_CLION_TELAS_H