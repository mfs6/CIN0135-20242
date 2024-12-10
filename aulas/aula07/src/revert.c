#include <stdlib.h>
#include <stdio.h>


int *rand_array(int n) {
    int delta = 1000/n;
    int *arr = calloc(n, sizeof(int));
    arr[0] = rand()%delta;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i-1] + (rand() % delta);
    }
    return arr;
}

void print_array(int *arr, int n) 
{
    for (int i = 0; i< n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void revert_array(int *arr, int n)
{
    for (int i = 0, j = n-1; i < j; i++, j--) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}


int main() {
    int n = 0;
    while (n < 1 || n > 100) {
        printf("\nEnter array size 1<=n<=100: ");
        scanf("%d", &n);
    }
    int *arr = rand_array(n);
    printf("Ordem direta: ");
    print_array(arr, n);
    revert_array(arr, n);
    printf("Ordem reversa: ");
    print_array(arr, n);
    free(arr);
}