#include "lista_def.c"

void insert(No *lista, int valor, int pos)
{
    No *cursor = lista;

    while (cursor->index != pos && cursor->next != NULL)
    {
        cursor = cursor->next;
    }

    No *new = create_node(valor);
    new->index = pos;
    new->next = cursor->next;
    cursor->next = new;

    while (cursor->next->next != NULL)
    {
        cursor->next->index++;
        cursor->next->valor = cursor->next->valor;
        cursor = cursor->next;
    }
}

//// Define a função que insere elementos no "tail" (final) da lista
void append(No *lista, int valor)
{
    //// Define um cursor que vai começar a procurar o "tail" (final) da "lista", para inserir o "valor" nele.
    No *cursor = lista; //* cursor aponta pra lista

    int index = cursor->index + 1; //* Variável pra contar o index

    //// O cursor itera até achar o ponteiro (*next) que é NULL e então adiciona o "valor" no lugar do NULL
    while (cursor->next != NULL)
    {
        //* O normal seria cursor.next, mas o vscode adota essa notação
        cursor = cursor->next; //* Passa para o próximo elemento da lista
        index++;               //* Incrementa o index pra ir contando a posição
    }

    //// Depois de achar onde é NULL, sai do while e começa a inserção do parâmetro "valor"

    //// Cria o ponteiro tail (que representa o final da lista) e aloca a memória para ele
    No *tail = malloc(sizeof(No));

    //// Altera os valores
    tail->index = index;
    tail->valor = valor;
    tail->next = NULL; //* Linha redundante já que tail->next já é NULL, pois acabou de ser inicializada

    cursor->next = tail; //* Devido a aritmética de ponteiros, assim que cursor.next recebe tail, lista.next também recebe, pois cursor aponta para lista
}

// No *remover(No *cursor)
// {
//     /* if (cursor->next==NULL)
//     {
//         return cursor;
//     } */
//     //* apagado do código "oficial"

//     No *removed = cursor->next;

//     cursor->next = removed->next; //*cursor.next.next
//     free(removed);
//     return cursor;

//     // find_pos(cursor, pos);
// }

void print_list(No *lista) //* Adicionado por mim
{
    No *cursor = lista;
    //// Iteração igual a de append(), só não tem o ->next pra conseguir printar o ultimo elemento da lista

    while (cursor != NULL)
    {
        printf("Posição: %d, ", cursor->index);
        printf("Valor: %d\n", cursor->valor);
        cursor = cursor->next; //* Passa para o próximo elemento da lista
    }
}