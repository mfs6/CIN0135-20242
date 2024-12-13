#include "lista.h"

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

//! Lembrar que a lista encadeada é basicamente ponteiros para os nós

//// Cria uma lista passando um valor pra o ser armazenado no index 0
No *create_list2(int valor)
{
    No *head = create_node(valor);

    return head;
}

//// Basicamente divide a criação da lista em dois metodos, um pro nó e outro pra pegar o nó criado
No *create_node(int valor)
{
    No *head = malloc(sizeof(No));

    (*head).index = 0;     //* É o mesmo que head->index
    (*head).valor = valor; //* É o mesmo que head->valor

    (*head).next = NULL; //* É o mesmo que head->next

    return head;
}