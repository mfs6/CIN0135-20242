#include <stdio.h>

// Aritmética de ponteiros
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i[p]); // reparem que e i[p] e nao p[i]
    }
}