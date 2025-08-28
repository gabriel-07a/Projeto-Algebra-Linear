//
// Created by gabriel on 26/08/2025.
//

#include "struct_matriz.h"

#include <stdio.h>
#include <stdlib.h>



//se usar a passagem por valor (matriz m) o c faz uma copia da matriz original trabalha só na copia
//ja se eu usar a passgem por ponteiro ele entrega o enderco da memoria onde a matriz esta guardada
//assim ele pode trabalhar na original, por isso que eu passei o ponteiro na funçao de destruir matriz



Matriz criar_matriz(int linhas, int colunas) {
    //preparando as dimensões da matriz
    Matriz matriz;
    matriz.linhas = linhas;
    matriz.colunas = colunas;

    //aq ele está pedindo para o sistema para criar um endereco que vai apontar para uma lista de enderecos que
    //vao apontar para uma lista de numeros, formando assim uma matriz
    //o malloc está pedindo a memoria para o sistema que sejam suficiente para criar quant(linhas) de ponteiros
    //ele multiplica linhas * o tamanho de um endereco que aponta para uma lista de numero, meio que ele está alocando memoria
    //para uma quantidade(linhas) de vetores double
    matriz.dados = (double **)malloc(linhas * sizeof(double*));
    //se quiser aq tambem podemos usar a função calloc que similar a função malloc que reserva a memoria
    //a função calloc também limpa a memoria reservada, resultando em uma matriz já populada com zeros

    //aqui ele vai verificar se deu certo essa alocacao de memoria de cima
    if (matriz.dados == NULL) {
        printf("Erro ao alocar memoria para as linhas!\n");
        exit(1); //encerra o programa
    }

    //agora ele cria os outros enderecos que estão sendo apontados pelo endereco criado acima
    //esses enderecos apontam para uma lista de double
    //essa lista vai ter tamanho (colunas * o tamanho de um tipo double)
    for (int i =0; i < linhas; i++) {
        matriz.dados[i] = (double *)malloc(colunas * sizeof(double));
        if (matriz.dados[i] == NULL) {
            //aqui ele vai verificar se deu certo ao criar esses enderecos
            printf("Erro ao alocar memoria para as colunas!\n");
            exit(1);
        }
    }

    //agora esse funçao está retornando basicamente um esqueleto de uma matriz do tamanho linhas x colunas
    //pronto para ser populado
    return matriz;
}

void destruir_matriz(Matriz *matriz) {
    //é preciso esse função para liberar a memoria para o sistema, ja que ao usar o malloc,
    //no fim do programa é nescessario usar o free

    //liberando primerio a memoria do endereço que aponta para a lista de numero
    //depois que se libera a memoria do endereço que estava apontando para esses enderecos
    for (int i = 0; i < matriz->linhas; i++) {
        free(matriz->dados[i]);
    }

    free(matriz->dados);
    //limpando o struct agora
    matriz->dados = NULL;
    matriz->linhas = 0;
    matriz->colunas = 0;
    //essas setinhas (->) é um atalho para um ponteiro de uma struct
    // ou seja, ao inves de fazer asism: (*matriz).dados
    // e so fazer matriz->dados

}

Matriz copia_matriz(Matriz matriz_original) {
    //criando uma matriz copia para usar ela para fazer os calculos
    //porque se nescessario eu posso mostrar a matriz inicial no fim
    Matriz copia_matriz = criar_matriz(matriz_original.linhas, matriz_original.colunas);

    for (int i = 0; i < matriz_original.linhas; i++) {
        for (int j = 0; j < matriz_original.colunas; j++) {
            copia_matriz.dados[i][j] = matriz_original.dados[i][j];
        }
    }

    return copia_matriz;
}



void imprimir_matriz(Matriz m) {
    printf("\nMatriz %d x %d:\n", m.linhas, m.colunas);
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            // O acesso aos elementos é feito da mesma forma que um array 2D normal
            printf("%8.2f", m.dados[i][j]);
        }
        printf("\n");
    }
}