//
// Created by gabriel on 27/08/2025.
//

#include "telas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct_matriz.h"

#ifdef _WIN32
    #include <windows.h> // Para Sleep()
#else
    #include <unistd.h>  // Para usleep()
#endif

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


void limpaTela() {
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux e Mac
    #endif
}

void loading() {

    limpaTela();
    char *bloco_solido = "\u2588";
    for (int i = 0; i < 10; i++) {
        printf("\n");
    }
    // falta o espaço aq
    for (int i = 0; i < 20; i++) { printf(" "); }

    for (int i = 0; i < 2; i++) {
        for (int i = 0; i < 30; i++) {
            printf(WHITE"%s"RESET, bloco_solido);

            fflush(stdout);
            #ifdef _WIN32
                        Sleep(25); // No Windows, a função Sleep() aceita milissegundos
            #else
                        usleep(5 * 1000); // No Linux/macOS, usleep() aceita microssegundos
            #endif
        }
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("\n");
    }
}



char titulos[6][30];





void printa_com_espacos(double num, int largura) {
    //cria um buffer temporario
    //vai servir como o lugar em que vai ser colocado o texto
    char buffer[20];
    //a função snprintf é um tipo de printf que escreve a string no buffer em vez da tela
    //por isso a varivavel buffer
    //nesse caso ela vai formatar o numero com 1 casa decimal e retornar a quantidade de caracteres para a variavel
    int quant_caracteres = snprintf(buffer, sizeof(buffer), "%.1lf", num);

    // Calcula os espaços a serem adicionados
    //agora é pego a largura total que eu quero para a string e subtraio pela largura total que deu o número de entrada
    int quant_de_espacos_em_branco = largura - quant_caracteres;


    // Imprime o alinhamento
    printf("|");


    for (int i = 0; i < quant_de_espacos_em_branco-2; i++) {
        printf(" ");
    }
    printf("%.1lf", num);
    printf("  ");
}



void exibir_tela_estatica(const char* nome_tela) {
    limpaTela();
    FILE *arquivo;
    char linha[200];
    char tela_procurada[100];
    int tela_encontrada =0;

    sprintf(tela_procurada, "{Tela:%s}\n", nome_tela);

    arquivo = fopen("telas_menu.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo: telas_menu.txt");
        return;
    }

    limpaTela();
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (tela_encontrada == 1) {
            // ...verificamos se a linha atual é o começo de OUTRA tela.
            // A função strstr verifica se uma string contém outra.
            if (strstr(linha, "{Tela:") != NULL) {
                break; // Se for, paramos de imprimir
            }
            // Se não for o começo de outra tela, apenas imprimimos a linha.
            printf("%s", linha);
        }
        // Se ainda não encontramos a nossa tela...
        else {
            // ...verificamos se a linha atual é a tag que procuramos.
            // A função strcmp compara duas strings. Retorna 0 se forem iguais.
            if (strcmp(linha, tela_procurada) == 0) {
                tela_encontrada = 1; // Encontramos! Na próxima iteração, começaremos a imprimir.
            }
        }
    }

    fclose(arquivo);

}


void verificador(int count, double vetor[]){
    for(int i = 0; i < 7;i++){
        vetor[i]=0;
    }
}


//
//Telas para Sistemas Lineares
//


double vetor_para_imprimir_a_matriz_2x2[7];

void funcao_para_polular_matriz_2x2(Matriz *matriz,int nome){
    for (int i = 0; i < 7; i++) {
        vetor_para_imprimir_a_matriz_2x2[i] = 0.0;
    }

    double numero;
    int count=0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Matriz [%d],[%d] = ", i+1, j+1);
            scanf("%lf", &matriz->dados[i][j]);
            numero = matriz->dados[i][j];
            tela_para_popular_matriz_2x2(numero,nome, count);
            count++;
            if(count == 6){
                verificador(count,vetor_para_imprimir_a_matriz_2x2);
            }
        }
    }
}
void tela_para_popular_matriz_2x2(double numeroMatriz, int nome, int count) {
     //eu preciso de um trem para verificar dps se isso é maior que 5
     //isso serve para montar certo a matriz.

    limpaTela();
    vetor_para_imprimir_a_matriz_2x2[count] = numeroMatriz;


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
    printa_com_espacos(vetor_para_imprimir_a_matriz_2x2[0], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_2x2[1], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_2x2[2], 7);
    printf("|                                      ║\n");

    printf("║                                   +-------+-------+-------+                                      ║\n");
    printf("║                                   ");
    printa_com_espacos(vetor_para_imprimir_a_matriz_2x2[3], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_2x2[4], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_2x2[5], 7);
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

double vetor_para_imprimir_a_matriz_3x3[13];

void funcao_para_popular_matriz_3x3(Matriz *matriz, int nome) {
    for (int i = 0; i < 13; i++) {
        vetor_para_imprimir_a_matriz_3x3[i] = 0.0;
    }

    double numero;
    int count=0;
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

    vetor_para_imprimir_a_matriz_3x3[count] = numeroMatriz;

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
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[0], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[1], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[2], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[3], 7);
    printf("|                                ║\n");

    // Linha 2 da matriz
    printf("║                                 +-------+-------+-------+-------+                                ║\n");
    printf("║                                 ");
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[4], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[5], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[6], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[7], 7);
    printf("|                                ║\n");

    // Linha 3 da matriz
    printf("║                                 +-------+-------+-------+-------+                                ║\n");
    printf("║                                 ");
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[8], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[9], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[10], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_3x3[11], 7);
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



void funcao_para_pegar_as_transformacoes(int linhas, int colunas, Matriz *matriz) {

    exibir_tela_estatica("verificacao_injetividade_pegar_transformacoes");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%lf", &matriz->dados[i][j]);

        }
    }

}



//
// telas para determinação de bases
//



void tela_para_resultado_da_determinante(int numero) {

    limpaTela();
    char resultado[70];
    if (numero == 1) {
        strcpy(resultado, "Formam base determinante         ");
    }else {
        strcpy(resultado, "Não formam Base determinante     ");
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

double vetor_para_imprimir_a_matriz_para_autovalores[5];

void funcao_para_polular_matrizez_para_autovalores(Matriz *matriz,int nome){
    for (int i = 0; i < 5; i++) {
        vetor_para_imprimir_a_matriz_para_autovalores[i] = 0.0;
    }
    double numero;
    int count=0;
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
    limpaTela();
    vetor_para_imprimir_a_matriz_para_autovalores[count] = numeroMatriz;


    //fica meio bugadinho vendo aqui mas na hora de printar vai dar certo. que ele vai reservar
    // tem 98 "="
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                                  ║\n");
    printf("║                                         Matriz 2x2                                               ║\n");
    printf("║                                                                                                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite sua matriz:                                                                               ║\n");
    printf("║                                                                                                  ║\n");
    printf("║                                     +-------+-------+                                            ║\n");
    printf("║                                     ");
    printa_com_espacos(vetor_para_imprimir_a_matriz_para_autovalores[0], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_para_autovalores[1], 7);
    printf("|                                            ║\n");

    printf("║                                     +-------+-------+                                            ║\n");
    printf("║                                     ");
    printa_com_espacos(vetor_para_imprimir_a_matriz_para_autovalores[2], 7);
    printa_com_espacos(vetor_para_imprimir_a_matriz_para_autovalores[4], 7);
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