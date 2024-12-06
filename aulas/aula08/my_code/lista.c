#include <stdio.h>
#include <stdlib.h>

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

    //// Define o valor guardado no endereço de memória em que head aponta (na prática cria a primeira caixinha da lista)
    (*head).index = 0;    //* Adicionado por mim
    (*head).valor = 1652; //? Por que está (*head) como se fosse um cast?

    //// Define a próxima caixinha como NULL, já que na criação (inicialização) da lista não tem próximos elementos
    (*head).next = NULL;

    //// Retorna o início da lista (a primeira caixinha). ou seja, na prática cria de fato a lista
    return head;
}

//! Lembrar que a lista encadeada é basicamente ponteiros para os nós

//// Define a função que insere elementos no "tail" (final) da lista
void append(No *lista, int valor)
{
    //// Define um cursor que vai começar a procurar o "tail" (final) da "lista", para inserir o "valor" nele.
    No *cursor = lista;

    int index = 1; // * Variável pra contar o index

    //// O cursor itera até achar o ponteiro (*next) que é NULL e então adiciona o "valor" no lugar do NULL
    while (cursor->next != NULL)
    {
        cursor = cursor->next; /* O normal seria cursor.next, mas o vscode adota essa notação */
        index++;               //* Incrementa index pra ir contando a posição
    }

    //// Depois de achar onde é NULL, sai do while e começa a inserção do parâmetro "valor"

    //// Cria o ponteiro tail (que representa o final da lista) e aloca a memória para ele
    No *tail = malloc(sizeof(No));

    //// Altera os valores
    tail->index = index;
    tail->valor = valor;
    tail->next = NULL; //? DEBUG: Essa linha é redundante sempre?

    /* Posiciona o cursor já no "tail" que foi definido com NULL logo acima, pra não precisar iterar numa nova chamada da função append */
    cursor->next = tail;
    //? Pra que serve essa linha acima? DEBUG: após a execução dela que a lista de fato incorpora a valor da cauda (talvez por causa de No *cursor = lista;)?
}

void print_list(No *lista) //* Adicionado por mim
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
    //// Começa criando a lista, chamando a função apropriada
    No *lista = create_list(); //// Nesse momento a lista só tem a primeira caixinha, o head

    print_list(lista); //* Adicionado por mim

    printf("\n");

    //// Insere valores na lista, através da função append, que insere os valores no final da lista
    append(lista, 2);
    append(lista, 3);
    append(lista, 5);
    append(lista, 7);

    print_list(lista); //* Adicionado por mim
}

//// Ilustração das caixinhas de uma lista encadeada

// Elemento 0 (Head) -> Primeiro da lista
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=0   |  Valor=0   |   para o    |
// |             |            |  próximo = 1|
// |             |            |             |
// ------------------------------------------

// Elemento 1
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=1   |  valor=2   |   para o    |
// |             |            |  próximo=2  |
// |             |            |             |
// ------------------------------------------

// Elemento 2
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=2   |  valor=3   |   para o    |
// |             |            |  próximo=3  |
// |             |            |             |
// ------------------------------------------

// Elemento 3
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=3   |  valor=5   |   para o    |
// |             |            |  próximo=4  |
// |             |            |             |
// ------------------------------------------

// Elemento 4 (Tail) -> Último da lista, portanto aponta pra NULL
// ------------------------------------------
// |             |            |             |
// |             |            |  Ponteiro   |
// |   index=4   |  valor=7   |   para o    |
// |             |            |  próximo =  |
// |             |            |    NULL     |
// ------------------------------------------