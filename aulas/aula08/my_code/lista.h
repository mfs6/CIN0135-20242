#include <stdio.h>  // Print
#include <stdlib.h> // malloc

struct Node;
//// Atribuindo o apelido "No" para a "struct Node", que é o nó da lista encadeada
typedef struct Node No;
//! Daqui em diante, sempre que for me referir a "struct Node", será por seu apelido "No"

No *create_list();
//? verificar se pode ter duas funções com o mesmo nome, mas que uma tem parâmetros e a outra não
No *create_list(int index, int valor);
No *create_node(int index, int valor);

void find_pos(No *lista, int valor);
void find_val(No *lista, int pos);

// TODO consertar index de inserção e deslocamento dos demais nós da lista
void insert(No *lista, int valor, int pos);
void append(No *lista, int valor);
// Remove //TODO adicionar função remover

// TODO fazer printar em ordem crescente, ainda que pule os index sem valor
void print_list(No *lista);

// gcc lista.h lista.c lista_search.c -> compilou
// Search herda de io que herda de def que herda do header, assim como o main