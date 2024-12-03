#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m; // linha
    int n; // coluna
    int p;
    int **matriz_a;
    int **matriz_b;

    // matriz_a = calloc(m, sizeof(int)); /* Primeiro aloca as linhas */
    // for (int i = 0; i < m; i++)
    // {
    //     matriz_a[i] = calloc(n, sizeof(int)); /* Depois aloca cada coluna em cada linha */
    // }

    // Testar metodo
    alocar_matriz(matriz_a, m, n);
    alocar_matriz(matriz_b, m, n);

    // matriz_b = calloc(m, sizeof(int)); /* Primeiro aloca as linhas */
    // for (int i = 0; i < m; i++)
    // {
    //     matriz_b[i] = calloc(n, sizeof(int)); /* Depois aloca cada coluna em cada linha */
    // }
}

void alocar_matriz(int **matriz, int m, int n)
{

    matriz = calloc(m, sizeof(int)); /* Primeiro aloca as linhas */
    for (int i = 0; i < m; i++)
    {
        matriz[i] = calloc(n, sizeof(int)); /* Depois aloca cada coluna em cada linha */
    }
}