//
// Created by gabriel on 27/08/2025.
//

#include "telas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h> // Para usleep()

#include "struct_matriz.h"

/**/
//CORES DE TEXTO
#define WHITE   "\x1b[37m"
#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

//CORES DE FUNDO
#define BG_BLACK   "\x1b[40m"
#define BG_RED     "\x1b[41m"
#define BG_GREEN   "\x1b[42m"
#define BG_YELLOW  "\x1b[43m"
#define BG_BLUE    "\x1b[44m"
#define BG_MAGENTA "\x1b[45m"
#define BG_CYAN    "\x1b[46m"
#define BG_WHITE   "\x1b[47m"

/**/
//qqr coisa o trem pra cancelar tudo tá aqkk


void loading() {
    limpaTela();
    char *bloco_solido = "\u2588";
    for (int i = 0; i < 10; i++) {
        printf("\n");
    }
    // falta o espaço aq
    for (int i = 0; i < 20; i++) { printf(" "); }

    for (int i = 0; i < 2; i++) {
        for (int i = 0; i < 60; i++) {
            printf(BLACK"%s"RESET, bloco_solido);

            fflush(stdout);
            usleep(25000); // isso muda o tempo
        }
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("\n");
    }
}

// se bugar é só apagar aq é fingir que nao rolo ndkkkk

/*
void loading(){

}
*/
//linha 138 precisa de ajuste
//tem que tratar os titulos pq eu fui animal e coloquei como se começasse em 1
char titulos[6][30];






/*esse "width está relacionado a largura que eu determinei "-" para cada numero
oq vai funcionar bem até numeros menores que 1k"*/
void print_with_padding(double num, int width) {
    char buffer[20]; // Um buffer temporário para a string
    int chars_printed = snprintf(buffer, sizeof(buffer), "%.2lf", num);

    // Calcula os espaços a serem adicionados
    int padding = width - chars_printed;

    // Imprime o alinhamento
    printf("|");
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%.1lf", num);
}

void limpaTela() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux e Mac
#endif
}

void menuPrincipal() {
    limpaTela();
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                        MENU PRINCIPAL                                            ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  [1]_ Sistemas Lineares                                                                          ║\n");
    printf("║  [2]_ Verificação de injetividade                                                                ║\n");
    printf("║  [3]_ Determinação de Bases                                                                      ║\n");
    printf("║  [4]_ Autovetores e Autovalores                                                                  ║\n");
    printf("║  [5]_ Diagonalização de Matrizes 2x2                                                             ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║ 0 - Para sair                                                                                    ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}

//
//Telas para Sistemas Lineares
//


void tela_sis_lineares_para_pegar_tamanho() {
    limpaTela();
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                          Sistemas Lineares                                       ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  Digite o tamanho do sistema linear:                                                             ║\n");
    printf("║                                                                                                  ║\n");
    printf("║  Exemplo: 2x2 (2 por 2),                                                                         ║\n");
    printf("║           3x3 (3 por 3),                                                                         ║\n");
    printf("║           nxn (n por n)                                                                          ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}


void funcao_para_polular_matriz_2x2(Matriz *matriz,int nome){
    double numero, count=0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz->dados[i][j]);
            numero = matriz->dados[i][j];
            tela_para_popular_matriz_2x2(numero,nome, count);
            count++;
        }
    }
}
void tela_para_popular_matriz_2x2(double numeroMatriz, int nome, int count) {
    //eu preciso de um trem para verificar dps se isso é maior que 5
     //isso serve para montar certo a matriz.
    double vetor_para_imprimir_a_matriz[7];
    limpaTela();
    vetor_para_imprimir_a_matriz[count] = numeroMatriz;


    //fica meio bugadinho vendo aqui mas na hora de printar vai dar certo. que ele vai reservar
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                      Sistemas Lineares 2x2                                       ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite sua matriz:                                                                               ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   +-------+-------+-------+                                      ║\n");
    printf("║                                   ");
    print_with_padding(vetor_para_imprimir_a_matriz[0], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[1], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[2], 8);
    printf("|                                      ║\n");

    printf("║                                   +-------+-------+-------+                                      ║\n");
    printf("║                                   ");
    print_with_padding(vetor_para_imprimir_a_matriz[3], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[4], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[5], 8);
    printf("|                                      ║\n");

    printf("║                                   +-------+-------+-------+                                      ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    printf("\n");
    printf("====================================================================================================\n");

}


//essa vai servir para popular 3x3
void funcao_para_popular_matriz_3x3(Matriz *matriz, int nome) {
    double numero, count =0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz->dados[i][j]);
            numero = matriz->dados[i][j];
            tela_para_popular_matriz_3x3(numero,nome, count);
            count++;
        }
    }

}
void tela_para_popular_matriz_3x3(double numeroMatriz, int nome, int count) {
    limpaTela();
    double vetor_para_imprimir_a_matriz[13];
    vetor_para_imprimir_a_matriz[count] = numeroMatriz;

    // Header da tela
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                      Sistemas Lineares 3x3                                       ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite sua matriz:                                                                               ║\n");
    printf("║                                                                                                  ║\n");

    // Linha 1 da matriz
    printf("║                                 +-------+-------+-------+-------+                                ║\n");
    printf("║                                 ");
    print_with_padding(vetor_para_imprimir_a_matriz[0], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[1], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[2], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[3], 8);
    printf("|                                ║\n");

    // Linha 2 da matriz
    printf("║                                 +-------+-------+-------+-------+                                ║\n");
    printf("║                                 ");
    print_with_padding(vetor_para_imprimir_a_matriz[4], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[5], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[6], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[7], 8);
    printf("|                                ║\n");

    // Linha 3 da matriz
    printf("║                                 +-------+-------+-------+-------+                                ║\n");
    printf("║                                 ");
    print_with_padding(vetor_para_imprimir_a_matriz[8], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[9], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[10], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[11], 8);
    printf("|                                ║\n");

    printf("║                                 +-------+-------+-------+-------+                                ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}




//
// Telas para verificação de injetividade
//

void tela_verificacao_para_pegar_dimensoes() {
    limpaTela();
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                Verificação de Injetividade, Sobrejetividade e Bijetividade                       ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  Digite a dimensão do R inicial e do R final:                                                    ║\n");
    printf("║                                                                                                  ║\n");
    printf("║  Exemplo: 3 2,                                                                                   ║\n");
    printf("║           2 2,                                                                                   ║\n");
    printf("║           3 3                                                                                    ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}

void funcao_para_pegar_as_transformacoes(int linhas, int colunas, Matriz *matriz) {
    tela_para_pegar_as_transformacoes();
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%lf", &matriz->dados[i][j]);

        }
    }

}
void tela_para_pegar_as_transformacoes() {
    limpaTela();
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                Verificação de Injetividade, Sobrejetividade e Bijetividade                       ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  Digite as trasformacoes lineares:                                                               ║\n");
    printf("║                                                                                                  ║\n");
    printf("║  Exemplo: para R(inicial) = 2 e R(final) = 3: x y                                                ║\n");
    printf("║                                               x y                                                ║\n");
    printf("║                                               x y                                                ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║           para R(inicial) = 3 e R(final) = 3: x y z                                              ║\n");
    printf("║                                               x y z                                              ║\n");
    printf("║                                               x y z                                              ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}





//
// telas para determinação de bases
//


void tela_menu_determinacao_de_bases() {
    limpaTela();
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   Determinação de Bases                                          ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  [1]_ Vetores 2x2 que formam uma matriz quadrada                                                 ║\n");
    printf("║  [2]_ Vetores 3x3 que formam uma matriz quadrada                                                 ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}

void tela_para_pegar_quant_subconjuntos() {
    limpaTela();
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   Determinação de Bases                                          ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  Digite a quantidade de subconjuntos:                                                            ║\n");
    printf("║                                                                                                  ║\n");
    printf("║  Exemplo: 3,                                                                                     ║\n");
    printf("║           2,                                                                                     ║\n");
    printf("║           4                                                                                      ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}

void tela_para_resultado_da_determinante(int numero) {
    limpaTela();
    char resultado[30];
    if (numero == 1) {
        strcpy(resultado, "Formam base determinante != 0    ");
    }else {
        strcpy(resultado, "Não formam Base determinante = 0 ");
    }
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   Determinação de Bases                                          ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   %s                              ║\n", resultado);
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}




//
//telas para autovalores e autovetores
//


void funcao_para_polular_matrizez_para_autovalores(Matriz *matriz,int nome){
    double numero, count=0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz->dados[i][j]);
            numero = matriz->dados[i][j];
            tela_para_popular_matrizes_para_autovalores(numero,nome, count);
            count++;
        }
    }
}
void tela_para_popular_matrizes_para_autovalores(double numeroMatriz, int nome, int count) {
    double vetor_para_imprimir_a_matriz[5];
    limpaTela();
    vetor_para_imprimir_a_matriz[count] = numeroMatriz;


    //fica meio bugadinho vendo aqui mas na hora de printar vai dar certo. que ele vai reservar
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                      Sistemas Lineares 2x2                                       ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite sua matriz:                                                                               ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                     +-------+-------+                                            ║\n");
    printf("║                                     ");
    print_with_padding(vetor_para_imprimir_a_matriz[0], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[1], 8);
    printf("|                                            ║\n");

    printf("║                                     +-------+-------+                                            ║\n");
    printf("║                                     ");
    print_with_padding(vetor_para_imprimir_a_matriz[2], 8);
    print_with_padding(vetor_para_imprimir_a_matriz[4], 8);
    printf("|                                            ║\n");

    printf("║                                     +-------+-------+                                            ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    printf("\n");
    printf("====================================================================================================\n");

}

void tela_para_resultado_de_autovalore_vetores(double lambda[2], Matriz autovetores) {
    limpaTela();
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   Autovetores e Autovalores                                      ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Os autovalores são %7.2lf e %7.2lf                                                             ║\n", lambda[0],
           lambda[1]); //tem que ficar assim mesmo por conta das casa que ele vai
    //mas é bom ver se isso aq nao vai dar mais espaço ou espaço de menos
    printf("║ Para lambda_1:                                                                                   ║\n");
    printf("║                       %7.2lf  |                                                                 ║\n",
           autovetores.dados[0][0]);
    printf("║                       %7.2lf  |                                                                 ║\n",
           autovetores.dados[1][0]);
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║ Para lambda_2:                                                                                   ║\n");
    printf("║                       %7.2lf  |                                                                 ║\n",
           autovetores.dados[0][1]);
    printf("║                       %7.2lf  |                                                                 ║\n",
           autovetores.dados[1][1]);
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}




//
//telas para diagonalização de matrizes
//




void menuDiagonalizacao2x2(double lambda[2]) {
    limpaTela();
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                 Diagonalização de Matrizes 2x2                                   ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Os autovalores são %7.2lf e %7.2lf                                                             ║\n", lambda[0],
           lambda[1]); //tem que ficar assim mesmo por conta das casa que ele vai
    //mas é bom ver se isso aq nao vai dar mais espaço ou espaço de menos
    printf("║                                                                                                  ║\n");
    printf("║ Matriz diagonalizada:                                                                            ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                     %7.2lf |    0                                                               ║\n",
           lambda[0]);
    printf("║                        0   |    %7.2lf                                                          ║\n",
           lambda[1]);
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}
