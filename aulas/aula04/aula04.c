#include <stdio.h>

//params.c

int soma(int *a, int *b){
    int a2 = quadrado(*a);
    int b2 = quadrado(*b);
    return a2+b2;
}

int quadrado(int v){
    int z = v * v;
    return z;
}

int fat(int x){
    //printf("."); // pequisar: segmentation fault (core dumped)
    if (x<=2) return x;
    return x * fat(x-1);
}

int fat2(int x){
    int f = 1;
    for(; x >= 2;x--){
        f*=x;
    }

    return f;
}

void swap(int *a, int *b){
    int t = *a;
   *a = *b;
   *b = t;
}


void main()
{
   int a = 20;
    
   int b = 10;

    printf("antes a=%d, b=%d\n", a, b);

   swap(&a,&b);

    printf("depois a=%d, b=%d\n", a, b);

   //int c = soma(&a,&b);

    //printf("%d² + %d² = %d\n", a, b, c);

    //a = 4;
    //int f = fat(a);
    //printf("%d! = %d\n", a, fat(4));
    //printf("%d\n", fat2(4));

    
}