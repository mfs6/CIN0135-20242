#include <stdio.h>
#include "prime.h"

void main()
{
    printf("Digite um número inteiro positivo\nN = ");
    int n;
    scanf("%d", &n);

    if (is_prime(n) == true)
    {
        printf("N é primo\n");
    }
    else
    {
        printf("N não é primo\n");
        //primefactors(n);
    }
}