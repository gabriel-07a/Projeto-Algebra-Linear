//
// Created by gabriel on 23/08/2025.
//

#include <stdio.h>
#include "det_bases.h"

void transformar_vetor_em_matriz(int ordem, double matriz[3][3]) {
    if (ordem == 2) {
        printf("Digite o primeiro vetor: x y\n");
        scanf("%lf %lf", &matriz[0][0], &matriz[1][0]);
        printf("Digite o segundo vetor: x y\n");
        scanf("%lf %lf", &matriz[0][1], &matriz[1][1]);
    }else{
        printf("Digite o primeiro vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz[0][0], &matriz[1][0], &matriz[2][0]);
        printf("Digite o segundo vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz[0][1], &matriz[1][1], &matriz[2][1]);
        printf("Digite o terceiro vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz[0][2], &matriz[1][2], &matriz[2][2]);
    }
    printf("Depois da operção: \n");
    for (int linhaa =0; linhaa < ordem; linhaa++) {
        for (int colunaa =0; colunaa < ordem; colunaa++) {
            printf("%.1lf  ", matriz[linhaa][colunaa]);
        }
        printf("\n");
    }
}


// Função para calcular o determinante
double calcular_determinante(int ordem, double matriz[3][3]) {
    double det, d, soma_principal, soma_secundaria;

    if(ordem == 2) {
        det = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    } else if(ordem == 3) {
        soma_principal = matriz[0][0] * matriz[1][1] * matriz[2][2]
            + matriz[0][1] * matriz[1][2] * matriz[2][0]
            + matriz[0][2] * matriz[1][0] * matriz[2][1];

        soma_secundaria = matriz[0][2] * matriz[1][1] * matriz[2][0]
          + matriz[0][0] * matriz[1][2] * matriz[2][1]
          + matriz[0][1] * matriz[1][0] * matriz[2][2];

        det = soma_principal - soma_secundaria;
    } else {
        det = 0;
    }
    printf("%lf\n", det);

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