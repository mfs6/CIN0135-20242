#include <stdio.h>
#include <stdlib.h>


// Array como ponteiro e com tamanho definido via malloc/calloc
void main()
{
    // Declara um array como ponteiro sem tamanho definido
    int *arr;

    int n;

    printf("\nDigite o tamanho do array: ");
    scanf("\n%d", &n); /* scanf sempre requer um endereço de memória pra armarzenar o valor lido (&n) */

    // arr = malloc(n * sizeof(int)); /* Cria um array que aloca como tamanho um bloco de n * 4 bytes na memória */

    arr = calloc(n, sizeof(int)); /* o mesmo que malloc, mas mais direto */

    // Preenchendo um array com os 5 primeiros números ímpares
    for (int i = 0; i < 5; i++)
    {
        // Coloca na posição i um número ímpar
        arr[i] = (2 * i) + 1; /* (2 * i) sempre gera um número par, somando mais 1 sempre gera um número ímpar */
    }

    // Printando os elementos do array
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d\n", arr[i]); /* Print "normal", printa o elemento que está na posição i do array */
    }

    free(arr); // Lembrar de liberar a memória sempre que estiver usando ponteiros

}