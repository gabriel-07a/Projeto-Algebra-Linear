//
// Created by gabriel on 23/08/2025.
//

#include <stdio.h>
#include "det_bases.h"

#include "struct_matriz.h"
#include "telas.h"
#define EPS 1e-9


void resolver_determinacao() {
    int ordem, quant_subconjuntos, resposta_do_usuario;
    double res_da_determinante;
    do {
        tela_menu_determinacao_de_bases();
        scanf("%d", &resposta_do_usuario);
        if (resposta_do_usuario == 1) {
            ordem = 2;
        }else if (resposta_do_usuario == 2) {
            ordem = 3;
        }else if (resposta_do_usuario == 0) {
            return;
        }
    } while (resposta_do_usuario < 0 || resposta_do_usuario > 2);

    tela_para_pegar_quant_subconjuntos();
    scanf("%d", &quant_subconjuntos);

    if (quant_subconjuntos < ordem) {
        printf("Não forma uma base, pois a dimensao eh R%d e tem %d vetores.\n", ordem, quant_subconjuntos);
    }else if (quant_subconjuntos > ordem) {
        printf("Não forma uma base, pois a dimensao eh R%d e tem %d vetores.\n", ordem, quant_subconjuntos);
    }else {
        Matriz matriz = criar_matriz(ordem, ordem);
        transformar_vetor_em_matriz(&matriz);
        res_da_determinante = calcular_determinante(&matriz);
        if(res_da_determinante > EPS) {
            tela_para_resultado_da_determinante(1);
        }else {
            tela_para_resultado_da_determinante(0);
        }
        destruir_matriz(&matriz);

    }



}

void transformar_vetor_em_matriz(Matriz *matriz) {
    if (matriz->linhas == 2) {
        printf("Digite o primeiro vetor: x y\n");
        scanf("%lf %lf", &matriz->dados[0][0], &matriz->dados[1][0]);
        //scanf("%lf %lf", matriz->dados[0][0], matriz->dados[1][0]);
        printf("Digite o segundo vetor: x y\n");
        scanf("%lf %lf", &matriz->dados[0][1], &matriz->dados[1][1]);
    }else{
        printf("Digite o primeiro vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz->dados[0][0], &matriz->dados[1][0], &matriz->dados[2][0]);
        printf("Digite o segundo vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz->dados[0][1], &matriz->dados[1][1], &matriz->dados[2][1]);
        printf("Digite o terceiro vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz->dados[0][2], &matriz->dados[1][2], &matriz->dados[2][2]);
    }
    /*
    printf("Depois da operção: \n");
    for (int linhaa =0; linhaa < matriz->linhas; linhaa++) {
        for (int colunaa =0; colunaa < matriz->linhas; colunaa++) {
            printf("%.1lf  ", matriz->dados[linhaa][colunaa]);
        }
        printf("\n");
    }*/
}


// Função para calcular o determinante
double calcular_determinante(Matriz *matriz) {
    double det, soma_principal, soma_secundaria;

    if(matriz->linhas == 2) {
        det = (matriz->dados[0][0] * matriz->dados[1][1]) - (matriz->dados[0][1] * matriz->dados[1][0]);
    } else if(matriz->linhas == 3) {
        soma_principal = matriz->dados[0][0] * matriz->dados[1][1] * matriz->dados[2][2]
                       + matriz->dados[0][1] * matriz->dados[1][2] * matriz->dados[2][0]
                       + matriz->dados[0][2] * matriz->dados[1][0] * matriz->dados[2][1];

        soma_secundaria = matriz->dados[0][2] * matriz->dados[1][1] * matriz->dados[2][0]
                        + matriz->dados[0][0] * matriz->dados[1][2] * matriz->dados[2][1]
                        + matriz->dados[0][1] * matriz->dados[1][0] * matriz->dados[2][2];

        det = soma_principal - soma_secundaria;
    }
    printf("Determinante %lf\n", det);

    return det;
}

