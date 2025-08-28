//
// Created by gabriel on 27/08/2025.
//

#include "telas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h> // Para usleep()

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

void inicializa_titulos(char titulos[][30]) {
    strcpy(titulos[1], "       Sistemas Lineares      ");
    strcpy(titulos[2], "  Verificação de injetividade ");
    strcpy(titulos[3], "    Determinação de Bases     ");
    strcpy(titulos[4], "  Autovetores e Autovalores   ");
    strcpy(titulos[5], "Diagonalização de Matrizes 2x2");
}


//eu preciso de um trem para verificar dps se isso é maior que 5
int count = 0; //isso serve para montar certo a matriz.
double vetor[4];

int Tcount = 0; //T de tres
double Tvetor[9];

void limpaVetor(double vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        vetor[i] = 0;
    }
}

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
    printf("%.2lf", num);
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

//esse nome tá repetido lá no final
//trocar os nomes dessas telas para nao confundir e nao dar problema
void doisTela(double numeroMatriz, int nome) {
    limpaTela();
    vetor[count] = numeroMatriz;
    count++;
    if (count == 4) {
        count = 0;
        limpaVetor(vetor, 4); // assim o vetor será limpo para proxima iteração
    }

    //fica meio bugadinho vendo aqui mas na hora de printar vai dar certo. que ele vai reservar
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                 %s                                   ║\n", titulos[nome]);
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite sua matriz:                                                                               ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   +-------+-------+                                              ║\n");
    printf("║                                   ");
    print_with_padding(vetor[0], 7);
    print_with_padding(vetor[1], 7);
    printf(" |                                              ║\n");

    printf("║                                   +-------+-------+                                              ║\n");
    printf("║                                   ");
    print_with_padding(vetor[2], 7);
    print_with_padding(vetor[3], 7);
    printf(" |                                              ║\n");

    printf("║                                   +-------+-------+                                              ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    printf("\n");
    printf("====================================================================================================\n");
    /*for(int i = 0 ; i < 4 ; i++){
         printf("%.2lf\n", vetor[i]);
     }
         */ //tá servindo só pra eu verificar se essa encrenca tava ou nao prestando kk
}


//essa vai servir para popular 3x3
void tresTela(double numeroMatriz, int nome) {
    limpaTela();

    Tvetor[Tcount] = numeroMatriz;

    Tcount++;

    if (Tcount == 9) {
        Tcount = 0; // Reseta o contador para o primeiro elemento
        limpaVetor(Tvetor, 9);
    }

    // Header da tela
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                            %s                                 ║\n", titulos[nome]);
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite sua matriz:                                                                               ║\n");
    printf("║                                                                                                  ║\n");

    // Linha 1 da matriz
    printf("║                                 +-------+-------+-------+                                        ║\n");
    printf("║                                 ");
    print_with_padding(Tvetor[0], 7);
    print_with_padding(Tvetor[1], 7);
    print_with_padding(Tvetor[2], 7);
    printf(" |                                       ║\n");

    // Linha 2 da matriz
    printf("║                                 +-------+-------+-------+                                        ║\n");
    printf("║                                 ");
    print_with_padding(Tvetor[3], 7);
    print_with_padding(Tvetor[4], 7);
    print_with_padding(Tvetor[5], 7);
    printf(" |                                       ║\n");

    // Linha 3 da matriz
    printf("║                                 +-------+-------+-------+                                        ║\n");
    printf("║                                 ");
    print_with_padding(Tvetor[6], 7);
    print_with_padding(Tvetor[7], 7);
    print_with_padding(Tvetor[8], 7);
    printf(" |                                       ║\n");

    printf("║                                 +-------+-------+-------+                                        ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}


void Det_basesmenu() {
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
    printf("║  [3]_ Indefinida (Em desenvolvimento)                                                            ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
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


void Det_Resultado(int numero) {
    limpaTela();
    char resultado[2][30];
    strcpy(resultado[0], "Não formam Base determinante = 0 ");
    strcpy(resultado[1], "Formam base     determinante != 0");
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
    printf("║                                   %s                               ║\n", resultado[numero]);
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


/*void Det_basesDois(){
limpaTela();
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

}*/
//deixei essa acima aqui pra caso a gente decida implementar mais aquela que o pablo falou lá


//essa é do autovalores
//o mesmo nome das variáveis está aq pra ficar mais organizado e ficar autoexplicativo
void aAtelas(double lambda[2], double autovetores[2][2]) {
    limpaTela();
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                   Autovetores e Autovalores                                      ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Os autovalores são %7.2lf e %7.2lf                                                 ║\n", lambda[0],
           lambda[1]); //tem que ficar assim mesmo por conta das casa que ele vai
    //mas é bom ver se isso aq nao vai dar mais espaço ou espaço de menos
    printf("║ Para lambda_1:                                                                                   ║\n");
    printf("║                       %7.2lf  |                                                     ║\n",
           autovetores[0][0]);
    printf("║                       %7.2lf  |                                                     ║\n",
           autovetores[1][0]);
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║ Para lambda_2:                                                                                   ║\n");
    printf("║                       %7.2lf  |                                                     ║\n",
           autovetores[0][1]);
    printf("║                       %7.2lf  |                                                     ║\n",
           autovetores[1][1]);
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("====================================================================================================\n");
}

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
    printf("║ Os autovalores são %7.2lf e %7.2lf                                                 ║\n", lambda[0],
           lambda[1]); //tem que ficar assim mesmo por conta das casa que ele vai
    //mas é bom ver se isso aq nao vai dar mais espaço ou espaço de menos
    printf("║                                                                                                  ║\n");
    printf("║ Matriz diagonalizada:                                                                            ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                     %7.2lf |    0                                                         ║\n",
           lambda[0]);
    printf("║                        0   |    %7.2lf                                                    ║\n",
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
