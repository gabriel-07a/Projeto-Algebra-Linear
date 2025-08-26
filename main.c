
#include <stdio.h>
#include "sis_lineares.h"
#include "transformacoes.h"



//scanf ("%29[^\n]s", var);
//gets(texto); // faz a mesma coisa do scanf
//puts() //imprime somente texto na tela
//int c
// while ((c = getchar()) != '\n' && c != EOF);
//setlocale(LC_ALL, "Portuguese");


int main(void) {
    int linha, coluna, tem_solucao=0;
    //double fator = 0.0;
    printf("Digite o tamanho da matriz: M N\n");
    scanf("%d %d", &linha, &coluna);
    double matriz[linha][coluna], aux[coluna];
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    // 3 por 4
    // linha = 3;
    // coluna = 4;

    verifica_transformacoes(linha, coluna, matriz);

    /*
    escalonador(linha, coluna, matriz);

    tem_solucao = analista(linha, coluna, matriz);

    if (tem_solucao) {
        solucionador(linha, coluna, matriz);
    } else {
        printf("Fim do programa!");
        return 0;
    }


    /*printf("matriz escalonada: \n");
    for (int linhaa =0; linhaa < linha; linhaa++) {
        for (int colunaa =0; colunaa < coluna; colunaa++) {
            printf("%.1lf  ", matriz[linhaa][colunaa]);
        }
        printf("\n");
    }
    printf("\n\n");


    //impressao
    printf("antes da operção: \n");
    for (int linhaa =0; linhaa < linha; linhaa++) {
        for (int colunaa =0; colunaa < coluna; colunaa++) {
            printf("%.1lf  ", matriz[linhaa][colunaa]);
        }
        printf("\n");
    }




    //impressao
    printf("Depois da operção: \n");
    for (int linhaa =0; linhaa < linha; linhaa++) {
        for (int colunaa =0; colunaa < coluna; colunaa++) {
            printf("%.1lf  ", matriz[linhaa][colunaa]);
        }
        printf("\n");
    }*/




    return 0;
}
