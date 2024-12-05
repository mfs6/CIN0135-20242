#include <stdio.h>
#include <stdlib.h>

struct Node /* Lista */
{
    int val;
    struct Node *next;
};

typedef struct Node Node; /* Apelido da lista */

Node *create_list() /* Cria a lista definida acima */
{
    Node *head = malloc(sizeof(Node)); /* Aloca a memória para o ponteiro head */
    (*head).val = 165;                 /* Define o valor guardado no endereço de memória em head aponta */
    (*head).next = NULL;               /* Define o próximo com NULL, já que não tem próximos elementos */
    return head;
}

// Define a função que coloca no final da lista um dado valor
void append(Node *head, int valor) /* Recebe a "cabeça" da lista */
{
    // Define onde começa a procura, inicializado como a "cabeça" da lista
    Node *cursor = head; // Dessa forma o head não muda durante a função, quem muda é o cursor para iterar na lista

    while (cursor->next != NULL) /* Até achar o valor que é NULL e então adicionar o valor no lugar do NULL */
    {
        cursor = cursor->next;
    }
    Node *tail = malloc(sizeof(int));
    tail->val = valor;
    tail->next = NULL;
    cursor->next = tail;
}

void main()
{
    // Exemplo 1 (mais direto ao ponto)
    // Node first;
    // Node second;
    // Node third;
    // Node four;

    // first.val = 2;
    // first.next = &second; /* & que faz referencia ao endereço de memoria ao qual Node *next aponta */

    // second.val = 3;
    // second.next = &third;

    // third.val = 5;
    // third.next = &four;

    // four.val = 7;
    // four.next = NULL;

    // Exemplo 2 (via create_list)
    Node *head = create_list();

    printf("%d\n", (*head)); /* Printa o valor apontado pelo ponteiro head definido em create_list */

    /* Coloca no final da lista um dado valor */
    append(head, 2);
    append(head, 3);
    append(head, 5);
    append(head, 7);

    // Debugar melhor em casa
}