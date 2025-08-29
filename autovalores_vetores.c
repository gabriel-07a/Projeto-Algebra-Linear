//
// Created by gabriel & andré on 26/08/2025.
//

#include <stdio.h>
#include <math.h>
#include "autovalores_vetores.h"
#include "struct_matriz.h"
#include "telas.h"
#define EPS 1e-9


/*
 * Essa biblioteca é feita para resolver o calculo de autovalores e autovetores
 * Ela é dividida basicamennte em duas funções que resolvem o problema e uma função que organiza e chama as outras funções
 * A função resolver_autovalores_autovetores é a única que é chamada fora dessa biblioteca, para uma melhor organização.
 */





/*
 * Essa é a função "mãe" chamada na tela principal e que resolve tudo
 * A única a ser chamaa fora dessa biblioteca
 * Ela faz a criação das matrizes nescessarias, chama uma função que imprime uma tela e recebe do usuario uma entrada,
 * verifica se é possível fazer o calculo com a quantidade de autovalores, chama a função para calcular os autovalores,
 * chama a função para calcular os autovetores, chama uma outra função para mostrar o resultado na tela
 * e depois destroi as matrizes criadas para liberar a memoria alocaca.
 */

void resolver_autovalores_autovetores() {
    double resposta_autovalores[2];
    //cria as duas matrizes nescessarias
    Matriz matriz = criar_matriz(2, 2);
    Matriz autovetores = criar_matriz(2, 2);

    //chama essa função da biblioteca telas.h, que imprime na tela e poplula a matriz
    funcao_para_polular_matrizez_para_autovalores(&matriz, 4);
    //chama a função para calcular os autovalores
    int num_autovalores_reais = calcular_autovalores(resposta_autovalores, matriz);
    //se não tem autovalores suficientes para o calculo encerra o programa
    if (num_autovalores_reais < 2) {
        printf("\nEncerrando, pois não há autovalores reais para calcular os autovetores.\n");
        destruir_matriz(&matriz);      //liberarando a memória antes de sair
        destruir_matriz(&autovetores);
        return;
    }

    //chama a função para calcular os autovetores
    calcular_autovetor(matriz, &autovetores, resposta_autovalores);
    //chama a função que vai mostrar na tela o resultados dos autovalores e vetores
    tela_para_resultado_de_autovalore_vetores(resposta_autovalores, autovetores);
    //libera a memoria das matrizes
    destruir_matriz(&matriz);
    destruir_matriz(&autovetores);
}

/*
 * Função que calcula os autovalores, ela faz o calculo do traço, da determinante, com esses resultados calcula
 * o delta, a partir do resultado do delta, verifica se os autovalores não são complexos, e se não, faz o calculo
 * dos autovalores
 */

int calcular_autovalores(double res_autovalores[2], Matriz matriz) {
    double traco, determinante, delta, b, a = 1.0;

    traco = matriz.dados[0][0] + matriz.dados[1][1]; // - (traco da matriz)
    //calculando a determinante da matriz
    determinante = matriz.dados[0][0] * matriz.dados[1][1] - matriz.dados[0][1] * matriz.dados[1][0];
    b = -traco;
    //delta = b * b - 4 * a * c;
    //calcula o delta da matriz
    delta = b * b - 4.0 * a * determinante;
    //verifica se os autovalores não são complexo
    if (delta < -EPS) {
        printf("autovalores complexos");
        return 0;
    }
    //se eles não forem complexos ele faz o calculo deles
    if (delta < EPS) { // apenas uma raiz (autovalores iguais)
        res_autovalores[0] = -b / (2.0 * a);
        res_autovalores[1] = res_autovalores[0];
    } else {
        res_autovalores[0] = (-b + sqrt(delta)) / (2.0 * a);
        res_autovalores[1] = (-b - sqrt(delta)) / (2.0 * a);
    }
    return 2;
}

/*
 * Essa é a função que vai fazer o calculo dos autovetores, ela recebe o lambda, que é basicamente
 * o resultados dos autovalores, e calcula os autovetores a partir disso
 */

void calcular_autovetor(Matriz matriz, Matriz *autovetores, double lambda[2]) {
    //iteração para fazer o calculo todo
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
    }
}



