//
// Created by gabriel on 21/08/2025.
//

#include "transformacoes.h"

#include <math.h>
#include <stdio.h>

#include "sis_lineares.h"
#include "struct_matriz.h"
#include "telas.h"

void resolver_verificacoes() {
    int dimensao_r_inicial, dimensao_r_final;
    tela_verificacao_para_pegar_dimensoes();
    scanf("%d %d", &dimensao_r_inicial, &dimensao_r_final);



    Matriz matriz = criar_matriz(dimensao_r_final, dimensao_r_inicial);

    funcao_para_pegar_as_transformacoes(dimensao_r_final, dimensao_r_inicial, &matriz);


    verifica_transformacoes(matriz, dimensao_r_inicial, dimensao_r_final);

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


void verifica_transformacoes(Matriz matriz, int r_inicial, int r_final) {
    escalonador(&matriz);
    int quant_pivos = contar_pivos(matriz);

    limpaTela();
    printf("═══════════════════════════════════════\n");
    printf("    A transformacao de R%d em R%d:\n", r_inicial, r_final);

    //agr é só ver se tem o msm tanto de pivos e colunas
    if (matriz.colunas == quant_pivos) {
        printf("Eh injetora!\n", r_inicial, r_final);
    }else {
        printf("Nao é injetora!\n", r_inicial, r_final);
    }


    if (matriz.linhas == quant_pivos) {
        printf("Eh sobrejetora!\n", r_inicial, r_final);
    }else {
        printf("Nao é sobrejetora!\n", r_inicial, r_final);
    }

    if (matriz.linhas == quant_pivos && matriz.colunas == quant_pivos) {
        printf("Portanto essa transformacao é bijetora!\n");
        printf("═══════════════════════════════════════");
    }else {
        printf("═══════════════════════════════════════");
    }


}
