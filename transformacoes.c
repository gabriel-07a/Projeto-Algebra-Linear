//
// Created by gabriel on 21/08/2025.
//

#include "transformacoes.h"

#include <stdio.h>

void verifica_transformacoes(int linha, int coluna, int quant_pivos) {
    printf("Quant de pivos: %d\n", quant_pivos);
    //agr é só ver se tem o msm tanto de pivos e colunas
    if (coluna == quant_pivos) {
        printf("Essa matriz é injetora!\n");
    }else {
        printf("Essa matriz não é injetora\n");
    }
    //obs deu certo de prima essa porra!!!

    if (linha == quant_pivos) {
        printf("Essa matriz é sobrejetora!\n");
    }else {
        printf("Essa matriz não é sobrejetora!\n");
    }

    if (linha == quant_pivos && coluna == quant_pivos) {
        printf("Essa matriz é bijetora!\n");
    }
}
