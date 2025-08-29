
#include <stdio.h>
#include <string.h>

#include "autovalores_vetores.h"
#include "det_bases.h"
#include "diagonalizacao_matriz.h"
#include "sis_lineares.h"
#include "telas.h"
#include "transformacoes.h"

#ifdef _WIN32
#include <windows.h>
#endif


int main() {
    // Adicione estas linhas NO COMEÇO da sua função main
#ifdef _WIN32
    // Define a página de código de saída do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    char menu_principal[29];// tem que ser 29 por conta do \0 e 28 é
    // pra ficar no meio


    int escolha;
    int nome;//esse é o nome que vai aparecer lá em cima
    do{
        int repetir;
        exibir_tela_estatica("menu_principal");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                loading();
                do{
                limpaTela();

                resolver_sistemas_lineares();
                printf("\n");
                printf("deseja repetir? 1 - Sim | 2 - Nao\n");
                scanf("%d", &repetir);
                }while (repetir!=2);

                limpaTela();
                break;

            case 2:
                loading();

                do{
                limpaTela();

                resolver_verificacoes();
                printf("\n");
                printf("deseja repetir? 0 para parar\n");
                scanf("%d", &repetir);
                }while (repetir!=0);

                limpaTela();
                break;


            case 3:
                loading();


                do{
                    limpaTela();

                    resolver_determinacao();
                    printf("\n");
                    printf("deseja repetir? 0 para parar\n");
                    scanf("%d", &repetir);
                }while (repetir!=0);


                break;

            case 4:
                loading();

                nome = 4;
                do{

                resolver_autovalores_autovetores();
                printf("\n");
                printf("\n");
                printf("\n");
                printf("deseja repetir? 0 para parar\n");
                scanf("%d", &repetir);
                }while(repetir!=0);

                limpaTela();
                break;

            case 5:
                loading();

                nome = 5;//esse é o nome que vai aparecer lá em cima
                do{


                resolver_diagonalizacao();
                printf("\n");
                printf("\n");
                printf("\n");
                printf("deseja repetir? 0 para parar\n");
                scanf("%d", &repetir);
                }while(repetir!=0);

                limpaTela();
                break;


            default:

                break;
        }

    } while(escolha!=0);


    return 0;

}

























//scanf ("%29[^\n]s", var);
//gets(texto); // faz a mesma coisa do scanf
//puts() //imprime somente texto na tela
//int c
// while ((c = getchar()) != '\n' && c != EOF);
//setlocale(LC_ALL, "Portuguese");

/*
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
    }




    return 0;
}
*/