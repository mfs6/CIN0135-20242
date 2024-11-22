#include <stdio.h>

// params.c --> nome do arquivo equivalente a esse na aula (ver se ele vai postar no src como na aula3)

int quadrado(int v) // Calcula o ² de um número
{
    int z = v * v;
    return z;
    // return v * v;
}

int somadosquadrados(int *x, int *y) // Recebe os endereços de memória onde estão os valores que serão usados na função
{
    int a = quadrado(*x);
    // Chama a função quadrado passando o valor que está sendo apontado pelo ponteiro por causa do * e não o endereço de memória
    int b = quadrado(*y);
    return a + b;
    // return quadrado(*x) + quadrado(*y);
}

int fatorial(int x) // Função fatorial recursiva consertada da aula, usando switch case
{
    int z;
    switch (x)
    {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        z = x * fatorial(x - 1); // Chama novamente a função passando o x-1 e multiplicando recursivamente (melhor pra debug)
        // return x * fatorial(x - 1);
    }
}

int fatorial2(int x) // Função fatorial usando while/for
{
    int f = 1;
    for (; x >= 2; x--)
    {
        f *= x;
    }

    // while (x >= 2)
    // {
    //     f *= x;
    //     x--;
    // }

    return f;
}

void swap(int *a, int *b) // Recebe os endereços de memória onde estão os valores que serão usados na função
{
    int t = *a;
    *a = *b;
    *b = t;
    // Faz o swap passando o valor que está sendo apontado pelo ponteiro por causa do * e não o endereço de memória, ainda usando a variável temporária t
}

void main()
{
    int a = 3;

    int b = 5;

    printf("Antes a = %d e b = %d\n", a, b);

    swap(&a, &b); // Função usando ponteiros -> manda os endereços de memória para a função

    printf("Depois a = %d e b = %d\n", a, b);

    int s = somadosquadrados(&a, &b); // Função usando ponteiros -> manda os endereços de memória para a função

    printf("%d² + %d² = %d\n", a, b, s);

    int f = fatorial(a);

    printf("%d! = %d\n", a, f);

    int f2 = fatorial2(a);

    printf("%d! = %d\n", a, f2);
}