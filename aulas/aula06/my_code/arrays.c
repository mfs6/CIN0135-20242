#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// void main()
// {
//     int arr[5];
//     // int arr[5]= {1,3,5,7,9} // preenchido explicitamente
//     int *p = arr; // ponteiro que guarda o endereço de memoria do array

//     for (int i = 0; i < 5; i++) // array com números impares, preenchido com for
//     {
//         arr[i] = (2 * i) + 1;
//     }

// for (int i = 0; i < 5; i++) // print do array
// {
//     //printf("%d\n", arr[i]); // print normal
//     printf("%d\n", p[i]); // printando via ponteiro
// }

//     for (int i = 0; i < 9; i++) /*printando acessando posições inexistentes do array,
//     acaba printando valores em posições fora do array, ou seja,
//     valores que estão na memoria depois do bloco de memoria alocado para o array */
//     {
//         printf("%d\n", arr[i]);
//     }
// }

// int main()
// {
//     int *arr; // declara um array como ponteiro quando ainda não sabe quantos elementos ele vai ter

//     int n;
//     scanf("Digite o tamanho do array %d", &n); // printa a msg e lê o valor de n passando o endereço de memoria em que n está

//     // arr = malloc(n * sizeof(int)); // um array com tamanho n inteiros, via malloc
//     //  cria um array que aloca como tamanho um bloco de n * sizeof(int) = n*4 bytes na memoria

//     arr = calloc(n, sizeof(int)); // o mesmo que malloc, mas mais direto

//     for (int i = 0; i < 5; i++) // array com números impares, preenchido com for
//     {
//         arr[i] = (2 * i) + 1;
//     }

//     free(arr); // lembrar de liberar a memória

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     // int arr[5][4];
//     int **arr[5]; // quando não sabe o numero de linhas e colunas

//     int nrows, ncols;

//     printf("Digite o numero de linhas do array");
//     scanf("%d", &nrows);

//     printf("Digite o numero de colunas do array");
//     scanf("%d", &ncols);

//     for (int i = 0; i < nrows; i++)
//     {
//         arr[i] = malloc(ncols * sizeof(int));
//     }

//     // for (int i = 0; i < 5; i++)
//     // {
//     //     arr[i] = malloc(ncols * sizeof(int));
//     // }

//     for (int i = 0; i < nrows; i++)
//     {
//         for (int j = 0; j < ncols; j++)
//         {
//             arr[i][j] = i + j;
//         }
//     }

//     for (int i = 0; i < nrows; i++)
//     {
//         for (int j = 0; j < ncols; j++)
//         {
//         }
//         printf("\n");
//     }

//     for (int i =0; i < nrows; i++){
//         free(arr[i]);
//     }

//     free(arr);
//     return 0;
// }

// void fixed_size_matrix()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             printf("\n");
//         }
//     }

//     return 0;
// }