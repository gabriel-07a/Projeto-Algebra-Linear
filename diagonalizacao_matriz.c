//
// Created by gabriel on 26/08/2025.
//

#include <stdio.h>
#include <math.h>
#include "diagonalizacao_matriz.h"

#include "autovalores_vetores.h"
#include "telas.h"

const double EPS = 1e-9;

void resolver_diagonalizacao() {
    double lambda[2];
    double matriz_diagonalizada[2][2] = {{0,0},{0,0}};
    Matriz matriz = criar_matriz(2,2);
    Matriz autovetores = criar_matriz(2,2);

    popular_matriz_2x2(&matriz, 4);

    calcular_autovalores(lambda, matriz);

    diagoniza_2x2(&matriz, &autovetores, lambda, matriz_diagonalizada);

    //chamando a outra função para confirmar a diagonalização
    if (verficia_diagonalizacao(matriz, autovetores, matriz_diagonalizada) == 0){
        limpaTela();
        printf("Nao eh diagonalizavel.\n");
    }else {
        menuDiagonalizacao2x2(lambda); //isso daq é a tela
    }
}

void popular_matriz_2x2(Matriz *matriz,int nome){
    double numero;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz->dados[i][j]);
            numero = matriz->dados[i][j];
            doisTela(numero,nome);
        }
    }
}





int verficia_diagonalizacao(Matriz matriz, Matriz autovetores, double matriz_diagonalizada[2][2]) {
    double det_p = autovetores.dados[0][0] * autovetores.dados[1][1] - autovetores.dados[0][1] * autovetores.dados[1][0];
    if (fabs(det_p) < EPS) return 0;

    double p_inv[2][2];
    double inv_det_p = 1.0 / det_p;
    p_inv[0][0] =  autovetores.dados[1][1] * inv_det_p;
    p_inv[0][1] = -autovetores.dados[0][1] * inv_det_p;
    p_inv[1][0] = -autovetores.dados[1][0] * inv_det_p;
    p_inv[1][1] =  autovetores.dados[0][0] * inv_det_p;

    double result_pd[2][2];
    result_pd[0][0] = autovetores.dados[0][0]*matriz_diagonalizada[0][0] + autovetores.dados[0][1]*matriz_diagonalizada[1][0];
    result_pd[0][1] = autovetores.dados[0][0]*matriz_diagonalizada[0][1] + autovetores.dados[0][1]*matriz_diagonalizada[1][1];
    result_pd[1][0] = autovetores.dados[1][0]*matriz_diagonalizada[0][0] + autovetores.dados[1][1]*matriz_diagonalizada[1][0];
    result_pd[1][1] = autovetores.dados[1][0]*matriz_diagonalizada[0][1] + autovetores.dados[1][1]*matriz_diagonalizada[1][1];

    double final_matrix[2][2];
    final_matrix[0][0] = result_pd[0][0]*p_inv[0][0] + result_pd[0][1]*p_inv[1][0];
    final_matrix[0][1] = result_pd[0][0]*p_inv[0][1] + result_pd[0][1]*p_inv[1][1];
    final_matrix[1][0] = result_pd[1][0]*p_inv[0][0] + result_pd[1][1]*p_inv[1][0];
    final_matrix[1][1] = result_pd[1][0]*p_inv[0][1] + result_pd[1][1]*p_inv[1][1];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (fabs(final_matrix[i][j] - matriz.dados[i][j]) > EPS)
                return 0;
    return 1;
}




void diagoniza_2x2(Matriz *matriz, Matriz *autovetores, double lambda[2], double matriz_diagonalizada[2][2]) {


    //autovalores_iguas();
    if (fabs(lambda[0] - lambda[1]) < EPS) {
        // Autovalores iguais
        double m00 = matriz->dados[0][0] - lambda[0];
        double m01 = matriz->dados[0][1];
        double m10 = matriz->dados[1][0];
        double m11 = matriz->dados[1][1] - lambda[0];

        if (fabs(m00) < EPS && fabs(m01) < EPS && fabs(m10) < EPS && fabs(m11) < EPS) {
            // Matriz diagonalizável, identidade ou múltiplo
            autovetores->dados[0][0] = 1; autovetores->dados[1][0] = 0;
            autovetores->dados[0][1] = 0; autovetores->dados[1][1] = 1;
        } else {
                limpaTela();
            printf("Nao e' diagonalizavel. Apenas um autovetor linearmente independente.\n");
            return;
        }
        matriz_diagonalizada[0][0] = lambda[0];
        matriz_diagonalizada[1][1] = lambda[0];
    }
    //autovalores distintos
    else {
        // Autovalores distintos: calcular autovetores normalmente
        for (int i = 0; i < 2; i++) {
            double m00 = matriz->dados[0][0] - lambda[i];
            double m01 = matriz->dados[0][1];
            double m10 = matriz->dados[1][0];
            double m11 = matriz->dados[1][1] - lambda[i];

            if (fabs(m01) > EPS) {
                autovetores->dados[0][i] = -m01;
                autovetores->dados[1][i] = m00;
            } else if (fabs(m10) > EPS) {
                autovetores->dados[0][i] = -m11;
                autovetores->dados[1][i] = m10;
            } else {
                autovetores->dados[0][i] = 1;
                autovetores->dados[1][i] = 0;
                if (i == 1 && fabs(autovetores->dados[0][0] - autovetores->dados[0][1]) < EPS && fabs(autovetores->dados[1][0] - autovetores->dados[1][1]) < EPS) {
                    autovetores->dados[0][i] = 0; autovetores->dados[1][i] = 1;
                }
            }
            printf("Autovetor para lambda=%.2lf: (%.2lf, %.2lf)\n", lambda[i], autovetores->dados[0][i], autovetores->dados[1][i]);
            matriz_diagonalizada[i][i] = lambda[i];
        }
    }


}




/*
int main() {
    double matriz[2][2] = {{2,0},{0,3}};
    processa_matriz_2x2(matriz);

    printf("\n");
    double matriz2[2][2] = {{1,1},{0,1}};
    processa_matriz_2x2(matriz2);

    printf("\n");
    double matriz4[2][2] = {{1,0},{0,1}};
    processa_matriz_2x2(matriz4);

    printf("\n");
    double matriz3[2][2] = {{5,0},{0,5}};
    processa_matriz_2x2(matriz3);

    return 0;
}
*/