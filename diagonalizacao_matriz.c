//
// Created by gabriel on 26/08/2025.
//

#include <stdio.h>
#include <math.h>
#include "diagonalizacao_matriz.h"

const double EPS = 1e-9;

int bhaskara(double a, double b, double c, double x[2]) {
    double delta = b * b - 4 * a * c;

    if (delta < -EPS) return -1;

    if (delta < EPS) { // Apenas uma raiz
        x[0] = -b / (2.0 * a);
        x[1] = x[0];
    } else {
        x[0] = (-b + sqrt(delta)) / (2.0 * a);
        x[1] = (-b - sqrt(delta)) / (2.0 * a);
    }
    return 0;
}

double det_dois(double matriz[2][2]) {
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

int dia_dois(double p[2][2], double matriz[2][2], double d[2][2]) {
    double det_p = det_dois(p);
    if (fabs(det_p) < EPS) return 0;

    double p_inv[2][2];
    double inv_det_p = 1.0 / det_p;
    p_inv[0][0] =  p[1][1] * inv_det_p;
    p_inv[0][1] = -p[0][1] * inv_det_p;
    p_inv[1][0] = -p[1][0] * inv_det_p;
    p_inv[1][1] =  p[0][0] * inv_det_p;

    double result_pd[2][2];
    result_pd[0][0] = p[0][0]*d[0][0] + p[0][1]*d[1][0];
    result_pd[0][1] = p[0][0]*d[0][1] + p[0][1]*d[1][1];
    result_pd[1][0] = p[1][0]*d[0][0] + p[1][1]*d[1][0];
    result_pd[1][1] = p[1][0]*d[0][1] + p[1][1]*d[1][1];

    double final_matrix[2][2];
    final_matrix[0][0] = result_pd[0][0]*p_inv[0][0] + result_pd[0][1]*p_inv[1][0];
    final_matrix[0][1] = result_pd[0][0]*p_inv[0][1] + result_pd[0][1]*p_inv[1][1];
    final_matrix[1][0] = result_pd[1][0]*p_inv[0][0] + result_pd[1][1]*p_inv[1][0];
    final_matrix[1][1] = result_pd[1][0]*p_inv[0][1] + result_pd[1][1]*p_inv[1][1];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (fabs(final_matrix[i][j] - matriz[i][j]) > EPS)
                return 0;
    return 1;
}

void processa_matriz_2x2(double matriz[2][2]) {
    double a = 1;
    double b = -(matriz[0][0] + matriz[1][1]);
    double c = det_dois(matriz);
    double lambda[2];

    if (bhaskara(a,b,c,lambda) < 0) {
        printf("Autovalores complexos\n");
        return;
    }

    printf("Os Autovalores sao: %.2lf e %.2lf\n", lambda[0], lambda[1]);

    double autovetores[2][2];
    double matriz_diagonalizada[2][2] = {{0,0},{0,0}};

    if (fabs(lambda[0] - lambda[1]) < EPS) {
        // Autovalores iguais
        double m00 = matriz[0][0] - lambda[0];
        double m01 = matriz[0][1];
        double m10 = matriz[1][0];
        double m11 = matriz[1][1] - lambda[0];

        if (fabs(m00) < EPS && fabs(m01) < EPS && fabs(m10) < EPS && fabs(m11) < EPS) {
            // Matriz diagonalizável, identidade ou múltiplo
            autovetores[0][0] = 1; autovetores[1][0] = 0;
            autovetores[0][1] = 0; autovetores[1][1] = 1;
        } else {
            printf("Nao e' diagonalizavel. Apenas um autovetor linearmente independente.\n");
            return;
        }
        matriz_diagonalizada[0][0] = lambda[0];
        matriz_diagonalizada[1][1] = lambda[0];
    } else {
        // Autovalores distintos: calcular autovetores normalmente
        for (int i = 0; i < 2; i++) {
            double m00 = matriz[0][0] - lambda[i];
            double m01 = matriz[0][1];
            double m10 = matriz[1][0];
            double m11 = matriz[1][1] - lambda[i];

            if (fabs(m01) > EPS) {
                autovetores[0][i] = -m01;
                autovetores[1][i] = m00;
            } else if (fabs(m10) > EPS) {
                autovetores[0][i] = -m11;
                autovetores[1][i] = m10;
            } else {
                autovetores[0][i] = 1;
                autovetores[1][i] = 0;
                if (i == 1 && fabs(autovetores[0][0] - autovetores[0][1]) < EPS && fabs(autovetores[1][0] - autovetores[1][1]) < EPS) {
                    autovetores[0][i] = 0; autovetores[1][i] = 1;
                }
            }
            printf("Autovetor para lambda= %.2lf: (%.2lf, %.2lf)\n", lambda[i], autovetores[0][i], autovetores[1][i]);
            matriz_diagonalizada[i][i] = lambda[i];
        }
    }

    if (dia_dois(autovetores, matriz, matriz_diagonalizada) == 0)
        printf("Nao eh diagonalizavel.\n");
    else {
        printf("Matriz diagonalizada (D):\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                printf(" %.2lf ", matriz_diagonalizada[i][j]);
            printf("\n");
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