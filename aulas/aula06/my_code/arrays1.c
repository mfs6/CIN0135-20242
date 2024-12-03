#include <stdio.h>

// Array: conceitos inicias
void main()
{
    // int arr[5]; /* Array com tamanho definido e inicializado vazio */
    int arr[5] = {115, 3, 5, 7, 9}; /* Preenchido explicitamente */
    int *p = arr;                   /* Ponteiro que guarda o endereço de memória do array */

    // Preenchendo um array com os 5 primeiros números ímpares
    for (int i = 0; i < 5; i++)
    {
        // Coloca na posição i um número ímpar
        arr[i] = (2 * i) + 1; /* (2 * i) sempre gera um número par, somando mais 1 sempre gera um número ímpar */
    }

    // Printando os elementos do array
    // for (int i = 0; i < 5; i++)
    // {
    //     // printf("\n%d\n", arr[i]); /* Print "normal", printa o elemento que está na posição i do array */
    //     printf("\n%d\n", p[i]); /* Printando via ponteiro */
    // }

    // Print acessando posições inexistentes do array
    /* Acaba printando valores em posições fora do array, ou seja, valores
    aleatórios que estão na memória depois do bloco de memória alocado para o array */
    for (int i = 0; i < 10; i++)
    {
        // printf("\n%d\n", arr[i]); /* Print "normal", printa o elemento que está na posição i do array */
        printf("\n%d\n", p[i]); /* Printando via ponteiro */
    }
    printf("\n%ld\n", p);  /* Printa o endereço de memória do array, já que p é o ponteiro que aponta para este endereço */
    printf("\n%d\n", *p); /* Printa o valor do primeiro elemento do array, já que o valor ao qual o ponteiro aponta é o primeiro elemento */
}