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
    //para fazer o switch com a escolha do usuario
    int escolha;
    do{
        int repetir;
        //imprime o menu principal do programa
        exibir_tela_estatica("menu_principal");
        //recebe de entrada a escolha do usuario
        scanf("%d", &escolha);
        //vai para a opcao que o usuario escolheu
        switch (escolha) {
            case 1:
                //Sistemas Lineares
                loading();
                do{
                    limpaTela();
                    //chama a função mãe da biblioteca sis_lineares.h
                    resolver_sistemas_lineares();
                    printf("\n");
                    printf("deseja repetir? 0 para parar\n");
                    scanf("%d", &repetir);
                }while (repetir!=0);
                limpaTela();
                break;

            case 2:
                //Verificação de injetiviadade, sobrejetividade e bijetividade
                loading();
                do{
                    limpaTela();
                    //chama a função mãe da biblioteca transformacoes.h
                    resolver_verificacoes();
                    printf("\n");
                    printf("deseja repetir? 0 para parar\n");
                    scanf("%d", &repetir);
                }while (repetir!=0);
                limpaTela();
                break;


            case 3:
                //Determinação de bases
                loading();
                do{
                    limpaTela();
                    //chama a função mãe da biblioteca det_bases.h
                    resolver_determinacao();
                    printf("\n");
                    printf("deseja repetir? 0 para parar\n");
                    scanf("%d", &repetir);
                }while (repetir!=0);
                limpaTela();
                break;

            case 4:
                //Autovalores e autovetores
                loading();
                do{
                    limpaTela();
                    //chama a função mãe da biblioteca autovalores_vetores.h
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
                    limpaTela();
                    //chama a funçaõ mãe da biblioteca diagonalizacao_matriz.h
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




