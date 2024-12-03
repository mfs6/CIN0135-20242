#include <stdio.h>
#include <stdlib.h>

// Array bidimensional (matriz) -> array[linhas][colunas]
void main()
{
    // int arr[5][4]; /* Array bidimensional com tamanho definido e inicializado vazio */
    // int array[3][2] = {{1, 1}, {1,2}, {1,3}}; /* Array bidimensional preenchido explicitamente */

    // Declara um array bidimensional como ponteiro sem tamanho definido
    int **arr;

    int nlinhas, ncolunas;

    printf("\nDigite o número de linhas do array: ");
    scanf("\n%d", &nlinhas); /* scanf sempre requer um endereço de memória pra armarzenar o valor lido (&nlinhas) */

    printf("\nDigite o número de colunas do array: ");
    scanf("\n%d", &ncolunas); /* scanf sempre requer um endereço de memória pra armarzenar o valor lido (&ncolunas) */

    /* // Alocar memória para o array de ponteiros (linhas)
    int** arr = (int**)malloc(nlinhas * sizeof(int*)); */

    arr = malloc(nlinhas * sizeof(int)); /* Por que não precisa fazer o cast? */

    // Alocar memória para cada linha (Explicar melhor esse for)
    for (int i = 0; i < nlinhas; i++)
    {
        arr[i] = malloc(ncolunas * sizeof(int));
    }

    // Preenchendo o array
    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            arr[i][j] = i + j;
        }
    }

    // Printando os elementos do array
    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            printf("%d ", arr[i][j]); /* Printa o(s) elemento(s) j (colunas) da linha i */
        }
        printf("\n"); /* Passa pra próxima linha antes de iterar em i (linhas) */
    }

    // Libera memória de cada linha
    for (int i = 0; i < nlinhas; i++)
    {
        free(arr[i]);
    }

    // Libera memória do array geral
    free(arr);
}

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