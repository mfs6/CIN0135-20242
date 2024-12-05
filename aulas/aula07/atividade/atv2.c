#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m;
    int n;
    int p;
    int **matriz_a;
    int **matriz_b;

    do
    {
        printf("M = ");
        scanf("\n%d", &m);

        printf("N = ");
        scanf("\n%d", &n);

        printf("P = ");
        scanf("\n%d", &p);
    } while (!(2 <= m <= 10) || !(2 <= n <= 10) || !(2 <= p <= 10));

    // matriz_a = calloc(m, sizeof(int)); /* Primeiro aloca as linhas */
    // for (int i = 0; i < m; i++)
    // {
    //     matriz_a[i] = calloc(n, sizeof(int)); /* Depois aloca cada coluna em cada linha */
    // }

    // Testar metodo
    alocar_matriz(matriz_a, m, n);
    alocar_matriz(matriz_b, n, p);

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