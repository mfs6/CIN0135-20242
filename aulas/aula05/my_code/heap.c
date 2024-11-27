#include <stdio.h>
#include <stdlib.h>

int *a(int x)
{
    int *p = (int *)malloc(sizeof(int)); /* Declara um ponteiro p do tipo int e coloca em p
    o endereço retornado por malloc que tem o tamanho de um int (4 bytes) */
    /* Faz o cast pra ponteiro do tipo int pq malloc retorna um ponteiro tipo void,
    e p é um ponteiro do tipo int */

    *p = x; // Atribui ao valor do ponteiro p (*p) o valor x recebido como parâmetro
    
    printf("\np = %p\n", p);
    printf("*p = %d\n", *p);

    return p;
}

void b(int x)
{
    int *p = (int *)malloc(sizeof(int)); /* Declara um ponteiro p do tipo int e coloca em p
    o endereço retornado por malloc que tem o tamanho de um int (4 bytes) */
    /* Faz o cast pra ponteiro do tipo int pq malloc retorna um ponteiro tipo void,
    e p é um ponteiro do tipo int */

    *p = x; // Atribui ao valor do ponteiro p (*p) o valor x recebido como parâmetro

    printf("\np = %p\n", p);
    printf("*p = %d\n", *p);
}

void main()
{
    int *q = a(12345);

    printf("\nDepois de chamar a:\n");
    printf("\nq = %p\n", q);
    printf("*q = %d\n", *q);

    printf("\nDepois de chamar b:\n"); // Printa antes pq b é void e os prints estão dentro dele
    b(12345);

    *q = 54321; // muda apenas o valor de q (*q)

    printf("\nApós mudar o valor de q, ou seja, *q");
    printf("\nq = %p\n", q);
    printf("*q = %d\n", *q);

    free(q); // Limpa o endereço de memória que q aponta, ou seja, limpa o valor (*q)

    printf("\nDepois de liberar q:\n");
    printf("q = %p\n", q);   /* O endereço continua o mesmo (endereço de p)
    que foi retornado pelo malloc da função a mas o valor de q (*q) muda */
    printf("*q = %d\n", *q); /* Por isso printa um valor aleatório (definido pelo SO)
    igual quando inicializa uma váriavel implicitamente, isto é, sem declarar valor */
    /*Em Java cada tipo tem um valor padrão especifico como o int que é 0 por padrão */
}