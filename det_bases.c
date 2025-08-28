//
// Created by gabriel on 23/08/2025.
//

#include <stdio.h>
#include "det_bases.h"

#include "struct_matriz.h"
#define EPS 1e-9


void resolver_determinacao() {
    int ordem, quant_subconjuntos;
    double res_da_determinante;
    printf("Informe a dimensão do espaco (2 ou 3): ");
    scanf("%d", &ordem);
    printf("Informe a quantidade de subconjuntos: ");
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
            printf("Esse conjunto eh base para R%d.\n", ordem);
        }else {
            printf("Esse conjunto nao é uma base para R%d.\n", ordem);
        }
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

/*
int main() {
    int ordem;

    printf("Informe a dimensão dos vetores (2 ou 3): ");
    scanf("%d", &ordem);
    double matriz[3][3];
    if(ordem != 2 && ordem != 3) {
        printf("Ordem inválida. Somente 2x2 ou 3x3 são aceitas.\n");
        return 1;
    }


    transformar_vetor_em_matriz(ordem,matriz);

    double det = calcular_determinante(ordem, matriz);

    if(det != 0) {
        printf("É uma base.\n");
    }else {
        printf("Não é uma base.\n");
    }
    return 0;
}
*/