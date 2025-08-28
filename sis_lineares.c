//
// Created by gabriel & andré on 20/08/2025.
//

#include "sis_lineares.h"
#include "struct_matriz.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "telas.h"

/*
 * Essa biblioteca é feita para resolver sistema lineares
 * Ela é dividida basicamennte em três funções que resolvem o problema e uma função que organiza e chama as outras funções
 * A função resolver_sistemas_lineares é a única que é chamada fora dessa biblioteca, para uma melhor organização.
 */




/*
 *Essa é a função "mãe" chamada na tela principal e que resolve tudo sobre sistemas lineares
 *Ela é chamada e a partir daí faz tudo sozinha
 *Como: receber a entrada dos dados nescessarios, criar uma matriz do tipo Matriz(que é uma struct), criar uma cópia dessa matriz
 * para se poder usar a matriz copiada para ser usada para fazer os calculos nescessarios, e se nescessarios,
 * devolver a matriz original, além disso ela chama as funções nescessarias para fazer o calcudo de sistemas lineares completo.
 */

void resolver_sistemas_lineares() {
    int tamanho_linha, tamanho_coluna;
    //
    tela_sis_lineares_para_pegar_tamanho();
    scanf("%dx%d", &tamanho_linha, &tamanho_coluna);
    //aq ele basicamente pega o tamanho (linha por coluna) do sistema

    tamanho_coluna++;
    //adiciona mais um na coluna por causa que um sistema linear tem a variavel depois do igual

    Matriz matriz = criar_matriz(tamanho_linha, tamanho_coluna);
    //aqui nos estamos criando uma variavel matriz do tipo Matriz(struct)
    //essa struct é feita para deixar o codigo mais legivel e melhor
    //ela basicamente aloca dinamicamente a memoria para a matriz do tamanho escolhido pelo usuario
    //essa struct, além de armazenar o dados da matriz em si, ela também armazena e nescessita do número de linhas e colunas



    // Matriz aumentada, por isso o +1 na coluna
    if (tamanho_coluna <= 1) {
        printf("A coluna da matriz deve ser maior que 1.\n");
    }

    //Populando a matriz
    //
    if (tamanho_linha == 2 && tamanho_coluna == 3) {
        //Chama a função para popular matrizes 2 por 2
        funcao_para_polular_matriz_2x2(&matriz, 1);

    }else if (tamanho_linha == 3 && tamanho_coluna == 4) {
        //Chama a função para popular matrizes 3 por 3
        funcao_para_popular_matriz_3x3(&matriz, 1);

    }else {
        //Aqui ele basicamente pega os elementos da matriz e armazenam nela
        limpaTela();
        printf("Digite os elementos da matriz:\n");
        for (int i = 0; i < tamanho_linha; i++) {
            for (int j = 0; j < tamanho_coluna; j++) {
                printf("matriz [%d][%d] = ", i+1, j+1);
                scanf("%lf", &matriz.dados[i][j]);
                limpaTela();
            }
        }
    }



    //aqui é criada a copia citada em cima, basicamente para poder manter a matriz orignal intacta no progrma
    //usando somente a matriz copiada para os calculos
    Matriz matriz_copia = copia_matriz(matriz);

    //Aqui é chamada a primeira função
    escalonador(&matriz_copia);
    //Aqui ele usa a função analista para ver se o sistema pode continuar sendo calculado
    if (analista(matriz_copia) == 1) {
        //Se o sistema ter uma solução única ele chama essa função para terminar a resolução
        solucionador(&matriz_copia);
    }else {

    }

    destruir_matriz(&matriz);
    destruir_matriz(&matriz_copia);

}

/*
 * Essa a primeira função chamada para calcular o sistema, o escalonador
 * Ele primeiramente analisa e percorre cada pivo para ver se ele é o melhor pivo,
 * o melhor pivo é o maior número de sua coluna, isso é feito para que o codigo faça divisões por números maiores
 * o que evita de um possivel arredondamento pelo número ser muito pequeno
 * Depois se ele identificar que o pivo não é o melhor ele faz a troca das linhas com o uso da fução memcpy
 * que pega uma linha dessa matriz, guarda em um vetor auxiliar, pega a linha do possivel melhor pivo escolhido
 * e depois coloca no lugar do pivo que depois é passado paro o lugar dessa outra linha.
 * Assim, ele já começa o outro passo que é o da eliminação, que é basicamente eliminar (tornar zero)
 * todos as variaveis abaixo dos pivos.
 */
void escalonador(Matriz *matriz) {
    //Esse fator é usado para fazer a eliminação
    double fator;
    //criando um vetor auxiliar
    //Ele teve que ser criado usando a alocação dinamica para evitar possiveis problemas com estouro de memoria
    double *aux = (double *)malloc(matriz->colunas * sizeof(double));

    for (int pivo_atual =0; pivo_atual < matriz->linhas-1; pivo_atual++) {
        //esse for vai percorrer todos os pivos, escolher o melhor e fazer a eliminação
        int maior_linha = pivo_atual;
        //essa função fabs (float absolute) é para pegar o valor abosoluto
        double maior = fabs(matriz->dados[pivo_atual][pivo_atual]);

        //aq ele identifica se existe um possivel melhor pivo dentro da coluna do pivo atual
        for (int linha_busca = pivo_atual + 1; linha_busca < matriz->linhas; linha_busca++) {
            // se o valor absoluto da linha de busca for maior que a variavel maior
            // ele basimente coloca esse valor dentro da variavel maior
            if (fabs(matriz->dados[linha_busca][pivo_atual]) > maior) {
                maior = fabs(matriz->dados[linha_busca][pivo_atual]);
                maior_linha = linha_busca;
            }
        }

        //aq ele faz a troca da linha de um pivo fraco para o melhor pivo
        if (maior_linha != pivo_atual) {
            //essa função copia um vetor para o outro
            //assim ela é usada para copiar uma linha da matriz para um vetor

            //aqui está sendo copiado a linha pivo atual, isso é feito porque ele não é o melhor pivo possivel
            //essa linha está sendo copiada para um vetor auxilixar
            memcpy(aux, matriz->dados[pivo_atual], matriz->colunas * sizeof(double));
            //aqui a linha do pivo atual é sobreposta pela linha do possivel melhor pivo
            memcpy(matriz->dados[pivo_atual], matriz->dados[maior_linha] , matriz->colunas * sizeof(double));
            //já aqui a linha do possivel melhor pivo é sobreposta pela linha do pivo atual, que foi armazenada no vetor auxiliar
            memcpy(matriz->dados[maior_linha], aux, matriz->colunas * sizeof(double));
        }
        // Se o pivô mais forte ainda for zero, não precisa eliminar nda
        if (fabs(matriz->dados[pivo_atual][pivo_atual]) < 1e-9) {
            continue; // Pula para a próxima o proximo pivo
        }

        //esse for é responsavel para fazer a eliminação de todas as variaveis abaixo do pivo atual
        for (int linha_busca = pivo_atual+1; linha_busca < matriz->linhas; linha_busca++) {
            //o fator é ultilizado para garantir que o elemento se torne igual a zero
            fator = matriz->dados[linha_busca][pivo_atual] / matriz->dados[pivo_atual][pivo_atual];
            for (int i=pivo_atual; i<matriz->colunas; i++) {
                //subtrai um multiplo da linha do pivo atual
                matriz->dados[linha_busca][i] -= fator * matriz->dados[pivo_atual][i];
            }
        }

    }

    //liberando a memoria alocada para o vetor
    free(aux);

}


/*
 * Esse é o analista, ele vem depois do escalonador para poder analizar se o sistema tem solução unica
 * e para decidir se o calculo vai continuar sendo feito
 * Primeiro ele lê e analisa se tem linha nulas no sistema, depois é simples
 * ele pega a quantidade de variaveis e de linhas normais e a partir disso consegue saber
 * se o sistema tem infinitas soluções, tem solução unica ou é impossivel
 * e detalhe: aqui eu não preciso passar por ponteiro porque eu não vou fazer alterações na matriz nessa função
 */

int analista(Matriz matriz) {
    //variavel usada para contar o quantidade de linhas nulas no sistema
    int linhas_nulas=0;

    for (int ler_linha = 0; ler_linha < matriz.linhas; ler_linha++) {
        int leitor = 1;
        //verificando os coeficientes
        //a coluna é menos 1 por ter q ler apenas os coeficientes
        for (int ler_coluna =0; ler_coluna < matriz.colunas-1; ler_coluna++) {
            // verificando se o valor absoluto é maior que uma tolarancia, pois é double
            if (fabs(matriz.dados[ler_linha][ler_coluna]) > 1e-9) {
                //se algum elemento da linha for maior que zero, ele para de checar, já que essa não deve ser uma linha nula
                leitor = 0;
                break;
            }
        }
        //aqui ele analisa se uma linha que foi considerada nula tem sua igualdade difente de zero
        //e se tiver ele já para o programa, pois esse já é um sistema impossivel
        if (leitor == 1) {
            if (fabs(matriz.dados[ler_linha][matriz.colunas-1]) > 1e-9) {
                printf("Sistema Impossivel!\n");
                return 0;
            }
            linhas_nulas++;
        }
    }
    //pegando a quantidade de variaveis e de linha normais
    int quant_variaveis = matriz.colunas -1;
    int quant_linhas_normais = matriz.linhas - linhas_nulas;
    //se a quantidade de linha normais, ou seja, linhas completamente zeradas, for maior que a quantidade de variaveis
    //esse sistema é um sistema que tem infinitas soluções possiveis
    if (quant_linhas_normais < quant_variaveis) {
        printf("Infinitas Soluçoes!\n");
        return 0;
        //se a quantidade de linhas normais for igual a quantidade de variaveis esse é um sistema com solução unica
    }else if (quant_linhas_normais == quant_variaveis) {
        printf("Solução Unica!\n");
        return 1;
        //Se não esse é um sistema que é impossivel, pois a quatidade de variaveis é maior que a quantidade de linhas
    }else {
        printf("Sistema Impossivel!\n");
        return 0;
    }
}

/*
 * Esse é o solucionador, a ultima função para se calcular um sistema
 * ele é responsável por pegar as variaveis restantes, e escalando o sistema
 * resolve todas as variaveis dele
 * Primeiro ele pega o numero de variaveis do sistema, cria um vetor em cima disso, esse vetor é usado para
 * devolver a resposta do sistema, depois ele começa a resolver o escalonamento
 * Assim ele pega uma soma dos termos, depois subtrai o termo independente pela soma dos outros termos
 * e divide tudo pelo coeficiente da variavel
 */

void solucionador(Matriz *matriz) {
    //pega a quantidade de variaveis
    int num_variaveis = matriz->colunas -1;
    //cria um vetor para armazenar os resultados
    double res[num_variaveis];

    //Resolvendo o escalonamento feito de baixo para cima
    for (int i = num_variaveis - 1; i >= 0; i--) {
        //buscando o pivô, que é o primeiro elemento não nulo
        int coluna_pivo = -1;
        for (int j = 0; j < num_variaveis; j++) {
            if (fabs(matriz->dados[i][j]) > 1e-9) {
                coluna_pivo = j;
                break;
            }
        }

        if (coluna_pivo == -1) continue; //se a linha for nula ele pula

        double soma = 0.0;
        for (int j = coluna_pivo + 1; j < num_variaveis; j++) {
            //faz a soma dos termos antes da igualdade
            soma += matriz->dados[i][j] * res[j];
        }

        //calcula o resultado, subtraindo o termo independete pela soma dos outros e dividindo pelo coeficiente
        res[coluna_pivo] = (matriz->dados[i][num_variaveis] - soma) / matriz->dados[i][coluna_pivo];
    }

    //printa o resultado
    printf("\n Resultados: \n");
    for (int i = 0; i < num_variaveis; i++) {
        printf("%.1lf  ", res[i]);
    }
}
