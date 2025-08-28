//
// Created by gabriel on 21/08/2025.
//

#include "transformacoes.h"

#include <math.h>
#include <stdio.h>

#include "sis_lineares.h"
#include "struct_matriz.h"

void resolver_verificacoes() {
    int dimensao_r_inicial, dimensao_r_final;
    printf("Digite a dimensao do espaco vetorial inicial: ");
    scanf("%d", &dimensao_r_inicial);
    printf("Digite a dimensao do espaco vetorial final: ");
    scanf("%d", &dimensao_r_final);

    Matriz matriz = criar_matriz(dimensao_r_final, dimensao_r_inicial);

    printf("Digite as transformações lineares:\n");
    for (int i = 0; i < dimensao_r_final; i++) {
        for (int j = 0; j < dimensao_r_inicial; j++) {
            scanf("%lf", &matriz.dados[i][j]);
        }
    }

    verifica_transformacoes(matriz);

    destruir_matriz(&matriz);
}



int contar_pivos(Matriz m) {
    int contador_pivos = 0;

    for (int i = 0; i < m.linhas; i++) {
        int coluna_pivos = -1;
        for (int j = 0; j < m.colunas; j++) {
            if (fabs(m.dados[i][j]) > 1e-9) {
                coluna_pivos = j;
                contador_pivos++;
                break;
            }
        }


    }
    return contador_pivos;
}


void verifica_transformacoes(Matriz matriz) {
    escalonador(&matriz);
    int quant_pivos = contar_pivos(matriz);


    printf("Quant de pivos: %d\n", quant_pivos);
    //agr é só ver se tem o msm tanto de pivos e colunas
    if (matriz.colunas == quant_pivos) {
        printf("Essa matriz é injetora!\n");
    }else {
        printf("Essa matriz não é injetora\n");
    }


    if (matriz.linhas == quant_pivos) {
        printf("Essa matriz é sobrejetora!\n");
    }else {
        printf("Essa matriz não é sobrejetora!\n");
    }

    if (matriz.linhas == quant_pivos && matriz.colunas == quant_pivos) {
        printf("Portanto essa matriz é bijetora!\n");
    }


}
