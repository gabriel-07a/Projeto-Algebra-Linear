//
// Created by gabriel & andré on 23/08/2025.
//

#include <stdio.h>
#include "det_bases.h"
#include <math.h>
#include "struct_matriz.h"
#include "telas.h"
#define EPS 1e-9 //numero epsilon para comparar valores double a zero


/*
 * Essa biblioteca é feita para resolver a determinação de bases de um r inicial para um r final
 * Ela é dividida basicamennte em duas funções que resolvem o problema e uma função que organiza e chama as outras funções
 * além de uma pequena função para limpar o buffer de entrada
 * A função resolver_determinacao é a única que é chamada fora dessa biblioteca, para uma melhor organização.
 */





/*
 * Essa é a função "mãe" chamada na tela principal e que resolve tudo
 * Ela é chamada fora da biblioteca e a partir daí faz tudo sozinha
 * Primeiro chama a função para exibir o menu que pede a ordem dos vetores, depois chama a função
 * para exibir a tela que pede a entrada da quantidade de subconjuntos que existem,
 * verfica se a partir desses subconjuntos é possível formar uma base, se sim, cria a matriz nescessaria
 * chama a função para pedir os vetores de entrada e trasforma-lós em matriz, chama a outra função
 * para calcular a determinante da matriz e a partir daí chama a tela pra imprimir o resultado.
 */

void resolver_determinacao() {
    int ordem, quant_subconjuntos, resposta_do_usuario=2;
    double res_da_determinante;
    do {
        //chama a tela que pede ao usuario a ordem da matriz
        exibir_tela_estatica("menu_determinacao_bases");
        //verifica se na entrada foram digitadas outras coisas além de números
        if (scanf("%d", &resposta_do_usuario) != 1) {
            limpar_buffer_entrada();
            continue;
        }
        //verifica se o usuario escolheu algumas das duas possiveis escolhas
        if (resposta_do_usuario == 1) {
            ordem = 2;
            limpar_buffer_entrada();
            break;
        }else if (resposta_do_usuario == 2) {
            ordem = 3;
            limpar_buffer_entrada();
            break;
        }else {
            //se o usuario não escolheu as opções exitentes o precosso roda denovo
            limpar_buffer_entrada();
        }
    } while (1);

    //exibe a tela que requere do usuario a quantidade de subconjuntos
    exibir_tela_estatica("subconjuntos_determinacao_bases");
    scanf("%d", &quant_subconjuntos);
    //verifica se a quantidade de subconjuntos possibilita a formação de uma base
    if (quant_subconjuntos < ordem) {
        printf("Não forma uma base, pois a dimensao eh R%d e tem %d vetores.\n", ordem, quant_subconjuntos);
    }else if (quant_subconjuntos > ordem) {
        printf("Não forma uma base, pois a dimensao eh R%d e tem %d vetores.\n", ordem, quant_subconjuntos);
    }else {
        //se a partir da quantidade de subconjuntos for possivel formar uma bases
        //é criada a matriz e chamada as funções nescessarias
        Matriz matriz = criar_matriz(ordem, ordem);
        //essa função pede ao o usuario a entrada dos vetores e já os trasforma em uma matriz
        transformar_vetor_em_matriz(&matriz);
        //chama a função para calcular a determinante e armazena ela na variavel
        res_da_determinante = calcular_determinante(&matriz);
        //decide se, a partir do resultado da determinante, é possível formar uma base ou não
        if((fabs(res_da_determinante)) > EPS) {
            tela_para_resultado_da_determinante(1);
        }else {
            tela_para_resultado_da_determinante(0);
        }
        destruir_matriz(&matriz);

    }



}

//funçãozinha para limpar o buffer de entrada
void limpar_buffer_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

//basicamente trasforma o vetor digitado pelo usuario para uma matriz da ordem escolhida
void transformar_vetor_em_matriz(Matriz *matriz) {
    //se a ordem que o usuario escolheu for 2, ele pede a quantidade nescessaria para criar
    //uma matriz 2 por 2
    if (matriz->linhas == 2) {
        printf("Digite o primeiro vetor: x y\n");
        scanf("%lf %lf", &matriz->dados[0][0], &matriz->dados[1][0]);
        //scanf("%lf %lf", matriz->dados[0][0], matriz->dados[1][0]);
        printf("Digite o segundo vetor: x y\n");
        scanf("%lf %lf", &matriz->dados[0][1], &matriz->dados[1][1]);
    }
    //se a ordem foi 3, ele pede a quantidade para popular uma matriz 3 por 3
    else{
        printf("Digite o primeiro vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz->dados[0][0], &matriz->dados[1][0], &matriz->dados[2][0]);
        printf("Digite o segundo vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz->dados[0][1], &matriz->dados[1][1], &matriz->dados[2][1]);
        printf("Digite o terceiro vetor: x y z\n");
        scanf("%lf %lf %lf", &matriz->dados[0][2], &matriz->dados[1][2], &matriz->dados[2][2]);
    }
}


// Função que calcula a determinante da matriz
double calcular_determinante(Matriz *matriz) {
    //cria as variaveis para receber a soma principal e secundaria
    //que somente são usadas para calcular a determinante de matrizes 3x3
    double det=0.0, soma_principal=0.0, soma_secundaria=0.0;
    //se a matriz for 2 por 2 ele faz o calculo da determinante
    //que nesse caso é mais facil por a matriz ser dois por dois
    if(matriz->linhas == 2) {
        //o calculo dessa matriz é basicamente subtrair a multiplicação da linha principal pela linha secundaria
        det = (matriz->dados[0][0] * matriz->dados[1][1]) - (matriz->dados[0][1] * matriz->dados[1][0]);
    } else if(matriz->linhas == 3) {
        //nesse caso ele faz o calculo da soma principal e o da soma secundaria e calcula a determinte
        //que para matrizes 3x3 é a soma principal menos a soma secundaria
        soma_principal = matriz->dados[0][0] * matriz->dados[1][1] * matriz->dados[2][2]
                       + matriz->dados[0][1] * matriz->dados[1][2] * matriz->dados[2][0]
                       + matriz->dados[0][2] * matriz->dados[1][0] * matriz->dados[2][1];

        soma_secundaria = matriz->dados[0][2] * matriz->dados[1][1] * matriz->dados[2][0]
                        + matriz->dados[0][0] * matriz->dados[1][2] * matriz->dados[2][1]
                        + matriz->dados[0][1] * matriz->dados[1][0] * matriz->dados[2][2];

        det = soma_principal - soma_secundaria;
    }
    //retorna o valor da determinante
    return det;
}

