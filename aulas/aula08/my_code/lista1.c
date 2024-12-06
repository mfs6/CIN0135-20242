#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int index;
    int valor;

    struct Node *next;
};

typedef struct Node No;

No *create_list()
{

    No *head = malloc(sizeof(No));

    (*head).index = 0;
    (*head).valor = 1652;

    (*head).next = NULL;

    return head;
}

void append(No *lista, int valor)
{

    No *cursor = lista;

    int index = 1;

    while (cursor->next != NULL)
    {
        cursor = cursor->next;
        index++;
    }

    No *tail = malloc(sizeof(No));

    tail->index = index;
    tail->valor = valor;
    tail->next = NULL;

    cursor->next = tail;
}

void print_list(No *lista)
{
    No *cursor = lista;

    while (cursor != NULL)
    {
        printf("Posição: %d, ", cursor->index);
        printf("Valor: %d\n", cursor->valor);
        cursor = cursor->next;
    }
}

void main()
{

    No *lista = create_list();

    print_list(lista);

    printf("\n");

    append(lista, 2);
    append(lista, 3);
    append(lista, 5);
    append(lista, 7);

    print_list(lista);
}
