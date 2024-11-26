#include <stdlib.h>

// void a(int x)
// {
//     int *p = (int *)malloc(sizeof(int)); /* coloca em *p o endereço retornado
//      por malloc que tem o tamanho de um int (4 bytes)*/
//     /* faz o cast pra ponteiro do tipo int pq malloc retorna um ponteiro tipo void,
//     e p é um ponteiro do tipo int*/
//     *p = x;
//     printf("p = %p\n", p);
//     printf("*p = %d\n", *p);
// }

int *a(int x)
{
    int *p = (int *)malloc(sizeof(int)); /* coloca em *p o endereço retornado
     por malloc que tem o tamanho de um int (4 bytes)*/
    /* faz o cast pra ponteiro do tipo int pq malloc retorna um ponteiro tipo void,
    e p é um ponteiro do tipo int*/
    *p = x;
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    return p;
}

void main()
{
    //a(12345);

    //int *q;
    int *q = a(12345);

    *q = 54321;

    printf("antes de sair (*q) %d\n", *q);
    printf("antes de sair (q) %p\n", q);

    free(q); // Limpa o valor (*q) do endereço de memória que q aponta

    printf("antes de sair (q) %p\n", q);
    printf("antes de sair (*q) %d\n", *q); // por isso printa um valor aleatório (algo como um valor null)
}
