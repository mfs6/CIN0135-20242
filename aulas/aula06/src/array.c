#include <stdlib.h>
#include <stdio.h>


void fixed_size() {
    int arr[5] = {1,3,5,7,9};

    int *p = arr;

    //for (int i = 0; i < 5; i++) {
    //    arr[i] = (2 * i) + 1;
   // }
    
    for (int i = 0; i < 9; i++) {
        printf("%d ", p[i]);
    }

}

void  variable_size() {
    int *arr;

    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    arr = calloc(n,  sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = (2 * i) + 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
}


void fixed_size_matrix() {
    int arr[5][4];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i + j;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}

int main() {
    int **arr;
    int nrows, ncols;
    
    printf("Enter nb of rows:");
    scanf("%d", &nrows);
    arr = calloc(nrows, sizeof(int*));

    printf("Enter nb of columns:");
    scanf("%d", &ncols);
    for (int i = 0; i < nrows; i++) {
        arr[i] = malloc(ncols * sizeof(int));
    }

    for (int i = 0; i <nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            arr[i][j] = i + j;
        }
    }
    
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < nrows; i++) {
        free(arr[i]);
    }
    free(arr);
}