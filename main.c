#include <stdio.h>
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
    #ifdef _WIN32
        // Define a página do código de saída do console para UTF-8
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif



    int escolha;
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
                printf("deseja repetir? 0 para parar\n");
                scanf("%d", &repetir);
                }while (repetir!=0);

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




