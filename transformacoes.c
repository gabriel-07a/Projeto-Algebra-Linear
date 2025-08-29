//
// Created by gabriel & andré on 21/08/2025.
//

#include "transformacoes.h"
#include <math.h>
#include <stdio.h>
#include "sis_lineares.h"
#include "struct_matriz.h"
#include "telas.h"


/*
 * Essa biblioteca é feita para resolver a verificação de injetividade, sobrejetividade e bijetividade
 * Ela é dividida em duas funções que resolvem os problemas e uma função que organiza e chama as outras funções
 * A função resolver_verificacoes é a única que é chamada fora dessa biblioteca, para uma melhor organização.
 */





/*
 * Essa é a função "mãe" chamada na tela principal e que resolve tudo para fazer as verificações
 * Ela é chamada e a partir daí faz tudo sozinha
 * Ela chama a tela para poder receber do usuario a entrada das dimensões dos vetores,
 * cria as variaveis e a matriz para o programa, chama a função para pegar as transformações, e essa função chama uma tela e
 * tabém poupula a matriz passada e chama a função verifica_transformacoes que faz todo o colculo nescessario.
 */

void resolver_verificacoes() {
    //primerio é recebido do usuario as dimensões para que seja criada a matriz
    int dimensao_r_inicial, dimensao_r_final;
    exibir_tela_estatica("verificacao_injetividade_pegar_dimensoes");
    scanf("%d %d", &dimensao_r_inicial, &dimensao_r_final);

    //aqui está sendo criada a matriz com as dimensões passadas
    Matriz matriz = criar_matriz(dimensao_r_final, dimensao_r_inicial);
    //essa função chama uma tela para receber do usuario os dados e popula a matriz criada
    funcao_para_pegar_as_transformacoes(dimensao_r_final, dimensao_r_inicial, &matriz);

    //essa função faz basicamente a verificação para determinar, a partir da quantidade de pivos,
    //oque os vetores passados são
    verifica_transformacoes(matriz, dimensao_r_inicial, dimensao_r_final);

    //basicamente destroi a matriz criada, depois de ser usada, porque elas foram alocadas dinamiacamente
    //e essa memoria precisa ser liberada
    destruir_matriz(&matriz);
}

/*
 * Essa é a função chamada pela função abaixo, ela basicamente conta a quantidade de pivos
 * que a matriz criada a partir dos vetores tem, e as retorna
 */

int contar_pivos(Matriz m) {
    //recebe a matriz como parametro
    int contador_pivos = 0;
    //inicia a contagem a quantidade de pivos
    for (int i = 0; i < m.linhas; i++) {
        int coluna_pivos = -1;
        for (int j = 0; j < m.colunas; j++) {
            if (fabs(m.dados[i][j]) > 1e-9) {
                coluna_pivos = j;
                contador_pivos++;
                break;
            }
        }
    }
    //e retorna essa quantidade
    return contador_pivos;
}

/*
 * Essa é a função que faz o calculo bem basico de verificações, ela primeiro chama a função
 * escalonador() que é da biblioteca sis_lineares.h, depois de feito o escalonamento, ela chama
 * a função para contar os pivos, depois já imprime na tela o resultado, comparando a quantidade de pivos
 * com as colunas, para decidir se é injetora, e com a quantidade de linhas, para decidir se é sobrejetora,
 * depois se a trasformação for injetora e sobrejetora, logicamente ele também imprime que ela é bijetora
 */


void verifica_transformacoes(Matriz matriz, int r_inicial, int r_final) {
    //chamando a função de escalonar da biblioteca sis_lineares.h
    escalonador(&matriz);
    //chamando a função para contar os pivos e os recebendo em uma variavel
    int quant_pivos = contar_pivos(matriz);
    //limpa a tela e já imprime os resultados
    limpaTela();
    printf("═══════════════════════════════════════\n");
    printf("    A transformacao de R%d em R%d:\n", r_inicial, r_final);
    //imprime os resultados logicos com base na quantidade de linhas e colunas da matriz criada
    //com base nos vetores de transformações passados pelo usuario
    if (matriz.colunas == quant_pivos) {
        printf("Eh injetora!\n");
    }else {
        printf("Nao é injetora!\n");
    }

    if (matriz.linhas == quant_pivos) {
        printf("Eh sobrejetora!\n");
    }else {
        printf("Nao é sobrejetora!\n");
    }

    if (matriz.linhas == quant_pivos && matriz.colunas == quant_pivos) {
        printf("Portanto essa transformacao é bijetora!\n");
        printf("═══════════════════════════════════════");
    }else {
        printf("═══════════════════════════════════════");
    }


}
