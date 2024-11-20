#include <stdio.h>
#include "prime.h"

void main()
{
    int n;
    printf("Digite um número\n");
    scanf("%d", &n);
    /*while (n <= 1)
    {
        printf("Número inválido\n");
        printf("Digite um novo número\n");
        scanf("%d", &n);
    }*/

    if (is_prime(n) == true)
    {
        printf("N is prime");
    }
    else
    {
        printf("N is not prime");
    }
}
