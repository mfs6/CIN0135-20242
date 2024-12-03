#include <stdlib.h>
#include <stdio.h>


int *a(int x) {
    int *p = (int *)malloc(sizeof(int));
    *p = x;
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    return p;
}



int main() {
    int *q = a(12345);

    *q = 54321;

    printf("antes de sair %d\n", *q);
    printf("antes de sair %p\n", q);

    free(q);
}