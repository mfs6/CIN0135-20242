#include<stdio.h>
#include<stdbool.h>

void main(){
    
    // bool b = false;
    // printf("b = %d, size=%ld\n",b, sizeof(b));

    // char c = 'c';
    // printf("c = %c\n",c);

    // int i = 0b01111111111111111111111111111111;//maior inteiro
    // printf("i = %d\n",i);
    // i++;
    // printf("i = %d\n",i);

    // long l = 12265741387454345;
    // printf("l = %d\n",l);
    
    // float f = 3.14;
    // printf("f = %f\n",f);

    int i =1024;

    printf("valor de i = %d\n", i);
    printf("tamanho de i = %ld\n", sizeof(i));
    printf("endereço de i = %ld\n\n", &i);

    int *p = &i;//declaracao de ponteiro para int i

    printf("valor de p = %ld\n", p);
    printf("tamanho de p = %ld\n", sizeof(p));
    printf("endereço de p = %ld\n\n", &p);

    int j = -127; // pega o valor da variavel que o ponteiro aponta
     *p = j;

    printf("valor de i = %d\n", j);
    printf("tamanho de i = %ld\n", sizeof(j));
    printf("endereço de i = %ld\n\n", &j);

    // int k =-127;
    // *p = k;

    // printf("valor de k = %ld\n", k);
    // printf("tamanho de k = %ld\n", sizeof(k));
    // printf("endereço de k = %ld\n", &k);


}