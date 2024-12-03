#include <stdio.h>
#include <stdlib.h>

int *rand_array(int n)
{
    int delta = 1000 / n; /* Limite até 1000 */
    int *arr = calloc(n, sizeof(int));
    arr[0] = rand() % delta;
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + (rand() % delta);
    }
    return arr;
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }

    printf("\n");
}

void reverte(int *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int aux = n - 1 - i;
        int temp = arr[i];
        arr[i] = arr[aux];
        arr[aux] = temp;
    }
    // outra forma
    /* for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int aux = n - 1 - i;
        int temp = arr[i];
        arr[i] = arr[aux];
        arr[aux] = temp;
    } */
}

void main()
{
    int t;
    printf("Tamanho: ");
    scanf("\n%d", &t);

    int *array = rand_array(t);

    printf("Array:\n");
    /* for (int i = 0; i < t; i++)
    {
        printf("%d \n", array[i]);
    } metodo proprio */

    print_array(array, t);

    reverte(array, t);

    printf("Array invertido:\n");

    print_array(array, t);
    free(array);

    /* for (int i = t - 1; i >= 0; i--)
    {
        printf("%d \n", array[i]);
    } metodo proprio */
}
