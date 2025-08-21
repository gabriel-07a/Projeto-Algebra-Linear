//
// Created by gabriel on 20/08/2025.
//

#include "sis_lineares.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


void escalonador(int linha, int coluna, double matriz[linha][coluna]) {
    double fator = 0.0;
    double aux[coluna];
    for (int pivo_atual =0; pivo_atual < linha-1; pivo_atual++) { //esse for vai percorrer todos os pivos, escolher o melhor e fazer a eliminação
        int maior_linha = pivo_atual;
        double maior = fabs(matriz[pivo_atual][pivo_atual]);

        for (int linha_busca = pivo_atual + 1; linha_busca < linha; linha_busca++) { //aq ele identifica se existe um possivel melhor pivo
            if (fabs(matriz[linha_busca][pivo_atual]) > maior) {
                maior = fabs(matriz[linha_busca][pivo_atual]);
                maior_linha = linha_busca;
            }
        }

        if (maior_linha != pivo_atual) { //aq ele faz a troca da linha de um pivo fraco para o melhor pivo
            memcpy(aux, matriz[pivo_atual], coluna * sizeof(double)); //essa função copia um vetor para o outro
            //matriz_aux[0] = matriz[contador_linha];
            memcpy(matriz[pivo_atual], matriz[maior_linha] , coluna * sizeof(double));
            //matriz[contador_linha] = matriz[maior_linha];
            memcpy(matriz[maior_linha], aux, coluna * sizeof(double));
            //matriz[maior] = matriz_aux[0];
        }
        // Se o pivô mais forte ainda for zero, não precisa eliminar nda
        if (fabs(matriz[pivo_atual][pivo_atual]) < 1e-9) {
            continue; // Pula para a próxima iteração do pivo_atual
        }
        //fazendo a eliminação
        for (int linha_busca = pivo_atual+1; linha_busca < linha; linha_busca++) {
            fator = matriz[linha_busca][pivo_atual] / matriz[pivo_atual][pivo_atual];
            for (int i=pivo_atual; i<coluna; i++) {
                matriz[linha_busca][i] -= fator * matriz[pivo_atual][i];
            }
        }

    }
}


int analista(int linha, int coluna, double matriz[linha][coluna]) {
    int linhas_nulas=0;

    for (int ler_linha = 0; ler_linha < linha; ler_linha++) {
        int leitor = 1;
        //verificando os coeficientes
        for (int ler_coluna =0; ler_coluna < coluna-1; ler_coluna++) { //a coluna é menos 1 por ter q ler apenas os coeficientes
            if (fabs(matriz[ler_linha][ler_coluna]) > 1e-9) { // verificando se o valor absoluto é maior que uma tolarancia, pois é double
                leitor = 0;
                break;
            }
        }
        if (leitor == 1) {
            if (fabs(matriz[ler_linha][coluna-1]) > 1e-9) {
                printf("Sistema Impossivel!\n");
                return 1;
            }
            linhas_nulas++;
        }
    }
    int quant_variaveis = coluna -1;
    int quant_linhas_normais = linha - linhas_nulas;
    if (quant_linhas_normais < quant_variaveis) {
        printf("Infinitas Soluçoes!\n");
        return 0;
    }else if (quant_linhas_normais == quant_variaveis) {
        printf("Solução Unica!\n");
        return 1;
    }else {
        printf("Sistema Impossivel!\n");
        return 0;
    }
}


void solucionador(int linha, int coluna, double matriz[linha][coluna]) {
    int num_variaveis = coluna -1;
    double res[num_variaveis];

    for (int i = num_variaveis - 1; i >= 0; i--) {
        double soma_conhecida = 0.0;
        for (int j = i + 1; j < num_variaveis; j++) {
            soma_conhecida += matriz[i][j] * res[j];
        }
        double termo_independente = matriz[i][num_variaveis];
        double pivo = matriz[i][i];

        res[i] = (termo_independente - soma_conhecida) / pivo;
    }

    printf("\n Resultados : \n");
    for (int i = 0; i < num_variaveis; i++) {
        printf("%.1lf  ", res[i]);
    }
}
