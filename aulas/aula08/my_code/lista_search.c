#include "lista_io.c"

//// Função que acha o valor de uma dada posição na lista
void find_val(No *lista, int pos)
{
    No *cursor = lista;

    while (cursor->index != pos && cursor->next != NULL)
    {
        cursor = cursor->next;
    }

    if (cursor->index != pos)
    {
        printf("\nNão existe nenhum valor na posição %d da lista\n", pos);
    }
    else
    {
        printf("\nNa posição %d\n está o valor %d\n", pos, cursor->valor);
    }
}

//// Função que acha a posição onde está um dado valor
void find_pos(No *lista, int valor)
{
    No *cursor = lista;

    while (cursor->valor != valor && cursor->next != NULL)
    {
        cursor = cursor->next;
    }

    if (cursor->valor != valor)
    {
        printf("\nO valor %d não existente na lista\n", valor);
    }
    else
    {
        printf("\nO valor %d está na posição %d\n", valor, cursor->index);
    }
}