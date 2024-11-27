#include <stdio.h>
#include <stdlib.h>

double pi = 3.1415;

double area(double r) // Área do círculo
{
    return pi * r * r; // π*r²
}

void main()
{
    double x = 10;
    printf("&x = %p\n", &x); // Printa o endereço de x

    double *p = &pi;          // Ponteiro p do tipo double
    printf("\np = %p\n", p);  // Printa o endereço de pi, não o valor que é *p = 3,1415
    printf("*p = %lf\n", *p); // Printa o valor que p aponta, *p = valor de pi = 3,1415

    void *v = malloc(sizeof(double)); /* Executa malloc, reserva 8 bytes de memoria (tamanho do double)
    e armazena no ponteiro v, malloc retorna um ponteiro do "tipo" void*/
    double *d = v;
    // double *d = (double *)v --> É redundante fazer o cast explicito do ponteiro do "tipo" void pro ponteiro do tipo double

    printf("\nv = %p\n", v); // Mostra o endereço de memória reservada pelo malloc

    printf("*v = %lf\n", *(double *)(v)); // Faz o cast de v para um ponteiro do tipo double e mostra o valor de v (*v)

    printf("*d = %lf\n", *d); // Igual a printf("v = %lf\n", *(double *)(v));(L27) pois: double *d = v;(22)

    *d = pi;
    printf("\n*d = %lf\n", *d); // Agora printa o valor de pi

    free(v); // Libera a memória do ponteiro v

    printf("*v = %ld\n", &v); /* Por isso printa um valor aleatório (definido pelo SO)
    igual quando inicializa uma váriavel implicitamente, isto é, sem declarar valor */
    /*Em Java cada tipo tem um valor padrão especifico como o int que é 0 por padrão */
}