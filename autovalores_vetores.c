//
// Created by gabriel on 26/08/2025.
//

#include <stdio.h>
#include <math.h>
#include "autovalores_vetores.h"

#define EPS 1e-9

void resolver_autovalores_autovetores() {

}

void popular_matriz_2x2(double matriz[2][2],int nome){
    double numero;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
            numero = matriz[i][j];
            doisTela(numero, nome);

        }
    }
}

//esse nome tá repetido lá no final
//trocar os nomes dessas telas para nao confundir e nao dar problema


void aVetorAvalor2(){
    double matriz[2][2];
    double autovetores[2][2];
    popularDois(matriz, 4);

    double lambda[2];
    double a, b, c, delta;
    a = 1;
    b = -(matriz[0][0] + matriz[1][1]); // - (traco da matriz)
    c = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];


    delta = b * b - 4 * a * c;


    if (delta < 0) {
        printf("autovalores complexos");
        return;
    }

    lambda[0] = (-b + sqrt(delta)) / (2.0 * a);
    lambda[1] = (-b - sqrt(delta)) / (2.0 * a);




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
            // Se o primeiro autovetor for (1, 0), garante que o segundo não seja igual
            if (i == 1 && fabs(autovetores[0][0] - autovetores[0][1]) < EPS && fabs(autovetores[1][0] - autovetores[1][1]) < EPS) {
                autovetores[0][i] = 0;
                autovetores[1][i] = 1;
            }
        }
        /*printf("Autovetor para lambda=%.2lf: (%.2lf, %.2lf)\n", lambda[i], autovetores[0][i], autovetores[1][i]);*/
    }

    //aAtelas(lambda, autovetores); // essa é a tela printada
}


