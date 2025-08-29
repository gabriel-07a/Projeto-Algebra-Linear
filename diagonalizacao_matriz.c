//
// Created by gabriel & andré on 26/08/2025.
//

#include <stdio.h>
#include <math.h>
#include "diagonalizacao_matriz.h"
#include "autovalores_vetores.h"
#include "telas.h"
#define EPS 1e-9


/*
 * Essa biblioteca é feita para resolver a diagonalização de bases
 * Ela é dividida basicamennte em duas funções que resolvem o problema e uma função que organiza e chama as outras funções
 * A função resolver_diagonalizacao é a única que é chamada fora dessa biblioteca, para uma melhor organização.
 */





/*
 * Essa é a função "mãe" chamada na tela principal e que resolve tudo
 * Ela é chamada e a partir daí faz tudo sozinha
 * Primeiro essa crias as matrizes nescessarias para o progrma, depois chama uma função para poder popular as matrizes,
 * chama a função para calcular autovalores da biblioteca autovalores_vetores.h, chama a função que vai fazer a diagonalização,
 * faz a revificação da diagonalização a partir de uma outra função, e se, for diagonalizavel chama a função para imprimir essa matriz
 */

void resolver_diagonalizacao() {
    double lambda[2];
    double matriz_diagonalizada[2][2] = {{0,0},{0,0}};
    //cria as matrizes
    Matriz matriz = criar_matriz(2,2);
    Matriz autovetores = criar_matriz(2,2);
    //chama a função que vai printar a tela e popular as matrizes
    funcao_para_polular_matrizez_para_autovalores(&matriz, 2);
    //chama a função para fazer o calculo de autovales
    //esse função é a a função de outra biblioteca
    calcular_autovalores(lambda, matriz);
    //faz a diagonalização das matrizes 2x2
    diagoniza_2x2(&matriz, &autovetores, lambda, matriz_diagonalizada);
    //chamando a outra função para confirmar a diagonalização
    if (verficia_diagonalizacao(matriz, autovetores, matriz_diagonalizada) == 0){
        //se não é diagonalizavel imprime na tela
        limpaTela();
        printf("Nao eh diagonalizavel.\n");
    }else {
        //se for diagonalizes imprime na tela a matriz diagonalizada
        menuDiagonalizacao2x2(lambda); //isso daq é a tela
    }
}




//função que vai testar para ver se a matriz é mesmo diagonalizavel
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


//essa é a função que vai diagonalizar a matriz 2x2
void diagoniza_2x2(Matriz *matriz, Matriz *autovetores, double lambda[2], double matriz_diagonalizada[2][2]) {
    //verifica se tem apenas um autovetor linearmente idenpendente
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
