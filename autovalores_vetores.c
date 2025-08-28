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

    funcao_para_polular_matrizez_para_autovalores(&matriz, 4);

    int num_autovalores_reais = calcular_autovalores(resposta_autovalores, matriz);
    if (num_autovalores_reais < 2) {
        printf("\nEncerrando, pois não há autovalores reais para calcular os autovetores.\n");
        destruir_matriz(&matriz);      // Boa prática: liberar memória antes de sair
        destruir_matriz(&autovetores); // (supondo que você tenha uma função liberar_matriz)
        return;
    }


    calcular_autovetor(matriz, &autovetores, resposta_autovalores);

    tela_para_resultado_de_autovalore_vetores(resposta_autovalores, autovetores);
    destruir_matriz(&matriz);
    destruir_matriz(&autovetores);
}


//esse nome tá repetido lá no final
//trocar os nomes dessas telas para nao confundir e nao dar problema

int calcular_autovalores(double res_autovalores[2], Matriz matriz) {
    double traco, determinante, delta, b, a = 1.0;

    traco = matriz.dados[0][0] + matriz.dados[1][1]; // - (traco da matriz)
    determinante = matriz.dados[0][0] * matriz.dados[1][1] - matriz.dados[0][1] * matriz.dados[1][0];
    b = -traco;
    //delta = b * b - 4 * a * c;
    delta = b * b - 4.0 * a * determinante;


    if (delta < -EPS) {
        printf("autovalores complexos");
        return 0;
    }

    if (delta < EPS) { // apenas uma raiz (autovalores iguais)
        res_autovalores[0] = -b / (2.0 * a);
        res_autovalores[1] = res_autovalores[0];
    } else {
        res_autovalores[0] = (-b + sqrt(delta)) / (2.0 * a);
        res_autovalores[1] = (-b - sqrt(delta)) / (2.0 * a);
    }
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



