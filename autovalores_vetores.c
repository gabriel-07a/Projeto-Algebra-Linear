//
// Created by gabriel on 26/08/2025.
//

#include <stdio.h>
#include <math.h>
#include "autovalores_vetores.h"

#include "struct_matriz.h"
#include "telas.h"

#define EPS 1e-9

void resolver_autovalores_autovetores() {
    double resposta_autovalores[2];
    Matriz matriz = criar_matriz(2, 2);
    Matriz autovetores = criar_matriz(2, 2);

    popular_matriz_2x2(&matriz, 4);

    int num_autovalores_reais = calcular_autovalores(resposta_autovalores, matriz);
    if (num_autovalores_reais < 2) {
        printf("\nEncerrando, pois não há autovalores reais para calcular os autovetores.\n");
        destruir_matriz(&matriz);      // Boa prática: liberar memória antes de sair
        destruir_matriz(&autovetores); // (supondo que você tenha uma função liberar_matriz)
        return;
    }


    calcular_autovetor(matriz, &autovetores, resposta_autovalores);

    aAtelas(resposta_autovalores, autovetores);
}

void popular_matriz_2x2(Matriz *matriz,int nome){
    double numero;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz->dados[i][j]);
            numero = matriz->dados[i][j];
            doisTela(numero, nome);

        }
    }
}

//esse nome tá repetido lá no final
//trocar os nomes dessas telas para nao confundir e nao dar problema

int calcular_autovalores(double res_autovalores[2], Matriz matriz) {
    double traco, determinante, delta, b;

    traco = matriz.dados[0][0] + matriz.dados[1][1]; // - (traco da matriz)
    determinante = matriz.dados[0][0] * matriz.dados[1][1] - matriz.dados[0][1] * matriz.dados[1][0];
    b = -traco;
    //delta = b * b - 4 * a * c;
    delta = b * b - 4.0 * 1.0 * determinante;


    if (delta < 0) {
        printf("autovalores complexos");
        return 0;
    }

    res_autovalores[0] = (-b + sqrt(delta)) / 2.0;
    res_autovalores[1] = (-b - sqrt(delta)) / 2.0;
    return 2;
}

void calcular_autovetor(Matriz matriz, Matriz *autovetores, double lambda[2]) {
    for (int i = 0; i < 2; i++) {
        double m00 = matriz.dados[0][0] - lambda[i];
        double m01 = matriz.dados[0][1];
        double m10 = matriz.dados[1][0];
        double m11 = matriz.dados[1][1] - lambda[i];

        if (fabs(m01) > EPS) {
            autovetores->dados[0][i] = -m01;
            autovetores->dados[1][i] = m00;
        } else if (fabs(m10) > EPS) {
            autovetores->dados[0][i] = -m11;
            autovetores->dados[1][i] = m10;
        } else {
            autovetores->dados[0][i] = 1;
            autovetores->dados[1][i] = 0;
            // Se o primeiro autovetor for (1, 0), garante que o segundo não seja igual
            if (i == 1 && fabs(autovetores->dados[0][0] - autovetores->dados[0][1]) < EPS && fabs(autovetores->dados[1][0] - autovetores->dados[1][1]) < EPS) {
                autovetores->dados[0][i] = 0;
                autovetores->dados[1][i] = 1;
            }
        }
        /*printf("Autovetor para lambda=%.2lf: (%.2lf, %.2lf)\n", lambda[i], autovetores[0][i], autovetores[1][i]);*/
    }
}



