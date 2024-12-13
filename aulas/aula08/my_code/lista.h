#include <stdio.h>  // Print
#include <stdlib.h> // malloc

struct Node;
//// Atribuindo o apelido "No" para a "struct Node", que é o nó da lista encadeada
typedef struct Node No;
//! Daqui em diante, sempre que for me referir a "struct Node", será por seu apelido "No"

No *create_list();

No *create_list2(int valor);
No *create_node(int valor);

void find_pos(No *lista, int valor);
void find_val(No *lista, int pos);

void insert(No *lista, int valor, int pos); //? consertar index do insert
void append(No *lista, int valor);
// Remove

void print_list(No *lista); //? ou ver se é erro de print

// gcc lista.h lista.c lista_search.c -> compilou
// Search herda de io que herda de def que herda do header, assim como o main