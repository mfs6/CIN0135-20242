#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//// Define o nó (a caixinha) da lista encadeada (semelhante a Java)
struct Node
{
    //// Atributos de cada nó (de cada caixinha)
    int index; //* Adicionado por mim
    int valor;

    //// Ponteiro para o próximo nó da lista encadeada
    struct Node *next;
    //! Lembrar que é um ponteiro do tipo Node (que é o próprio nó) --- (parece uma função recursiva)
};

//// Atribuindo o apelido "No" para a "struct Node", que é o nó da lista encadeada
typedef struct Node No;
//! Daqui em diante, sempre que for me referir a "struct Node", será por seu apelido "No"

//// Finalmente cria a lista que é composta pelos nós (por cada caixinha) da struct "Node"
No *create_list()
{
    //// Cria o ponteiro head (que representa o início da lista) e aloca a memória para ele
    No *head = malloc(sizeof(No));

    //! Inicializar a lista com os valores padrões dos atributos é redundante, pois na linha acima isso já é feito
    //// Define o valor guardado no endereço de memória em que head aponta (na prática cria a primeira caixinha da lista)
    (*head).index = 0; //* É o mesmo que head->index
    (*head).valor = 0; //* É o mesmo que head->valor

    //// Define a próxima caixinha como NULL, já que na criação (inicialização) da lista não tem próximos elementos
    (*head).next = NULL; //* É o mesmo que head->next

    //// Retorna o início da lista (a primeira caixinha). ou seja, na prática cria de fato a lista
    return head;
}

No *create_list2(int valor)
{
    No *head = create_node(valor);

    return head;
}

//! Lembrar que a lista encadeada é basicamente ponteiros para os nós

//// Define a função que insere elementos no "tail" (final) da lista
void append(No *lista, int valor)
{
    //// Define um cursor que vai começar a procurar o "tail" (final) da "lista", para inserir o "valor" nele.
    No *cursor = lista; //* cursor aponta pra lista

    int index = 0; //* Variável pra contar o index

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

//// Função que acha o valor de uma dada posição na lista
No *find_pos(No *head, size_t pos)
{
    No *cursor = head;

    size_t i = 0; //* Posição inicial

    while (i < pos && cursor->next != NULL)
    {
        cursor = cursor->next;
        i++;
    }
    return cursor;
}

No *find_val(No *head, int valor)
{
    No *cursor = head;

    while (cursor->next != NULL && cursor->next->valor != valor)
    {
        cursor = cursor->next;
    }
    return cursor;
}

No *insert(No *head, size_t pos, int valor)
{
    No *cursor = find_pos(head, pos);
    No *new = create_node(valor);
    new->next = cursor->next;
    cursor->next = new;
    return cursor;
}

No *create_node(int valor)
{
    No *head = malloc(sizeof(No));

    (*head).index = 0;     //* É o mesmo que head->index
    (*head).valor = valor; //* É o mesmo que head->valor

    (*head).next = NULL; //* É o mesmo que head->next

    return head;
}

No *remover(No *cursor)
{
    /* if (cursor->next==NULL)
    {
        return cursor;
    } */
    //* apagado do código "oficial"

    No *removed = cursor->next;

    cursor->next = removed->next; //*cursor.next.next
    free(removed);
    return cursor;

    // find_pos(cursor, pos);
}

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

void main()
{
    //// Começa criando a lista, chamando a função apropriada
    No *lista = create_list();
    //// Nesse momento a lista só tem a primeira caixinha, o head, por isso printa os valores iniciais
    // print_list(lista);

    printf("\n");

    //// Insere valores na lista, através da função append, que insere os valores no final da lista
    /* append(lista, 126);
    append(lista, 463);
    append(lista, 597);
    append(lista, 850);
    append(lista, 5650);
    append(lista, 8532);
    append(lista, 5850);
    append(lista, 12850);
    append(lista, 110);
    append(lista, 1360);
    append(lista, 189); */

    append(lista, 2);
    append(lista, 3);
    append(lista, 5);
    append(lista, 7);

    //// Printa a lista com os valores inseridos
    print_list(lista);

    No *node = NULL;
    size_t pos = 3;

    node = find_pos(lista, pos);

    if (node->next != NULL)
    {
        printf("\n\n\nLista[%d] = %d\n", pos, node->next->valor);
    }
    else
    {
        printf("\nFora da lista\n");
    }

    int valor = 2;
    node = find_val(lista, valor);

    if (node->next != NULL)
    {
        printf("\n\n\nValor do No = %d\n", node->next->valor);
    }
    else
    {
        printf("\nNot found\n");
    }

    pos = 2;
    valor = 4;
    node = insert(lista, pos, valor);
    if (node->next != NULL)
    {
        Printf("\n\n\nValor do No = %d\n", node->next->valor);
    }
    else
    {
        printf("\nNot found\n");
    }

    node = find_val(lista, 4);
    lista = remover(node);
    if (node->next != NULL)
    {
        printf("node val = %d", node->next->valor);
    }
    else
    {

        printf("\nNot found\n");
    }
}

//// Ilustração das caixinhas de uma lista encadeada
// Elemento 0 (Head) -> Primeiro da lista
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=0   |  Valor=0   |   para o    |
// |             |            |  próximo = 1|  Elemento, não index
// |             |            |             |
// ------------------------------------------

// Elemento 1
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=1   | valor=126  |   para o    |
// |             |            | próximo = 2 |  Elemento, não index
// |             |            |             |
// ------------------------------------------

// Elemento 2
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=2   | valor=463  |   para o    |
// |             |            | próximo = 3 |  Elemento, não index
// |             |            |             |
// ------------------------------------------

// Elemento 3
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=3   | valor=597  |   para o    |
// |             |            | próximo = 4 |  Elemento, não index
// |             |            |             |
// ------------------------------------------

// Elemento 4 (Tail) -> Último da lista, portanto aponta pra NULL
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=4   |  valor=850 |   para o    |
// |             |            |  próximo =  |
// |             |            |    NULL     |
// ------------------------------------------