#include <stdio.h>
#include <stdlib.h>

// Gerando um array com números aleatórios dentro de um limite definido (1000)
int *rand_array(int n)
{
    int delta = 1000 / n; /* Fator que limita os números gerados do array até 1000 */

    // Aloca memória para o array que está sendo declarado como ponteiro, no tamanho que foi passado como parâmetro
    int *arr = calloc(n, sizeof(int));

    // Define que o primeiro elemento do array será um número dentro do limite
    arr[0] = rand() % delta;

    for (int i = 1; i < n; i++)
    {
        // Pega o número da posição anterior e soma com um próximo número gerado aleatóriamente, mas dentro do limite
        arr[i] = arr[i - 1] + (rand() % delta); /* Ordem crescente */
    }

    return arr;
}

// Printa todos os elementos do array, por isso passa o tamanho como parâmetro
void print_array(int *arr, int n)
{
    // Itera em todos os elementos do array e printa todos eles
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void reverte(int *arr, int n)
{
    /* for (int i = 0; i < n / 2; i++)
    {
        int aux = n - 1 - i;
        int temp = arr[i];
        arr[i] = arr[aux];
        arr[aux] = temp;
    } */

    // Outra forma
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int aux = n - 1 - i;
        int temp = arr[i];
        arr[i] = arr[aux];
        arr[aux] = temp;
    }
}

void main()
{
    int t;

    do
    {
        printf("Digite o tamanho do array: ");
        scanf("\n%d", &t);
    } while (t > 100 || t <= 0);

    int *array = rand_array(t);

    printf("\nArray: ");

    print_array(array, t);

    reverte(array, t);

    printf("\nArray: ");

    print_array(array, t);

    free(array);
}