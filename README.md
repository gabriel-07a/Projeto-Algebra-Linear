# Projeto Álgebra Linear

Esse é um projeto feito para resolver a atividade avaliativa de algoritmos e técnicas de programação 2 em conjunto com a máteria de álgebra linear. O intuito do programa é resolver problemas de álgebra usando as estruturas vistas em ATP2 integrando assim as duas disciplinas, o projeto está dividido em varios arquivos .c e .h, que funionam como bibliotecas, foram dividios assim para facilitar na organização e no entendimento do codigo em geral.  
A função main fica resposável por fazer a iteração do menu principal, chamando cada biblioteca conforme a escolha do usuário, cada problema de álgebra está em um desses arquivos .c, que em conjunto são acompanhados com os arquivos .h, do mesmo nome. O arquivo telas.c é resposável pela interfaces do programa, as telas que não são estáticas ficaram no próprio arquivo, já as telas que são estáticas foram passadas para um arquivo .txt resposável por armazenar as mesmas. 
O arquivo struct_matriz.c é resposável pela criação de matrizes usando as structs, que é explicada no próprio arquivo, além de ser resposável por mais função relacionadas as matrizes. 




## Funcionalidades

- Resolução de Sistemas Lineares
- Verificação de Injetividade, Sobrejetividade e Bijetividade
- Determinação de Bases
- Cálculo de Autovalores e Autovetores
- Diagonalização de Matrizes


## Rodando localmente - Usando o CMake

Clone o projeto

```bash
  git clone https://github.com/gabriel-07a/Projeto-Algebra-Linear.git
```

Entre na pasta do projeto

```bash
  cd main_clion
```

Criar uma pasta para compilação

```bash
  mkdir build
```

Entrar na pasta

```bash
  cd build
```
Rodar o CMake para configurar o projeto
```bash
  cmake ..
```
Rodar o comando de build para compilar
```bash
  cmake --build .
```

## Rodando localmente - Sem usar o CMake

Baixe a pasta do projeto

Acesse a pasta pelo terminal
```bash
  cd projeto-algebra-linear
```
Compile usando o gcc
```bash
  gcc -o programa.exe main.c telas.c transformacoes.c struct_matriz.c sis_lineares.c diagonalizacao_matriz.c 
  det_bases.c autovalores_vetores.c -lm
```
Rode o arquivo .exe gerado
```bash
  ./programa.exe
```
## Apêndice

Para funcionar as interfaces do projeto é nescessário a utilização de um terminal ou IDE compátivel com o UTF8.  
O CMake no projeto foi feita para facilitar a compilação, mas ele não é obrigatório para compilar o programa.  
A pasta telas_menu.txt pode não funcionar se o código for radado em IDEs, pois ele nescessita está na pasta de trabalho na IDE, o que ser evitado usando o CMake. 


## Autores

- [@gabriel arcanjo](https://github.com/gabriel-07a)
- [@andré barbosa](https://github.com/andrebarbosafranca04-tech)

