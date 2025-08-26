//
// Created by gabriel on 21/08/2025.
//

#include "transformacoes.h"

#include <math.h>
#include <stdio.h>

#include "sis_lineares.h"

int contar_pivos(int linha, int coluna, double matriz[linha][coluna]) {
    int contador_pivos = 0;

    for (int i = 0; i < linha; i++) {
        int coluna_pivos = -1;
        for (int j = 0; j < coluna; j++) {
            if (fabs(matriz[i][j]) > 1e-9) {
                coluna_pivos = j;
                contador_pivos++;
                break;
            }
        }


    }
    return contador_pivos;
}

void verifica_transformacoes(int linha, int coluna, double matriz[linha][coluna]) {
    escalonador(linha, coluna, matriz);
    int quant_pivos = contar_pivos(linha, coluna, matriz);


    printf("Quant de pivos: %d\n", quant_pivos);
    //agr é só ver se tem o msm tanto de pivos e colunas
    if (coluna == quant_pivos) {
        printf("Essa matriz é injetora!\n");
    }else {
        printf("Essa matriz não é injetora\n");
    }


    if (linha == quant_pivos) {
        printf("Essa matriz é sobrejetora!\n");
    }else {
        printf("Essa matriz não é sobrejetora!\n");
    }

    if (linha == quant_pivos && coluna == quant_pivos) {
        printf("Essa matriz é bijetora!\n");
    }

    printf("Matriz escalonada:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%8.3f ", matriz[i][j]);
        }
        printf("\n");
    }
}
