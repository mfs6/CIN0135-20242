#include <stdio.h>
#include <stdlib.h>

double pi = 3.1415;

double area(double r)
{

    return pi * r * r;
}

void main()
{

    double x = 10;
    printf("&x = %p\n", &x); // printa o endereço de x

    double *p = &pi;
    printf("p = %p\n", p);   // printa o endereço de pi, não o valor que é *p = 3,1415
    printf("*p = %lf\n", *p); // printa o valor que *p aponta, o valor de pi = 3,1415

    void *v = malloc(sizeof(double)); /* executa malloc, reserva memoria
    no tamanho do double (8 bytes se não me engano) e armazena no ponteiro v, malloc retorna um ponteiro*/
    double *d = v;
    // double *d = (double *)v --> é redundante

    //printf("d = %lf\n", d);

    printf("v = %p\n", v); // mostra o endereço de memória reservado pelo malloc

    printf("*v = %lf\n", *(double *)(v)); // faz o cast de v para um ponteiro de um double e mostra o valor v (*v)

    printf("*d = %lf\n", *d); /* igual a printf("v = %lf\n", *(double *)(v)); // faz o
    cast de v para um ponteiro de um double*/

    // v é um ponteiro pra um void
    // interprete v como um ponteiro pra em double
    //**(double * )(v) valor que está armazenado no endereço void *v

    *d = pi;
    printf("\n*d = %lf\n", *d); //  agora printa o valor de pi

    free(v); // liberar a memória do ponteiro v
    free(v);
}