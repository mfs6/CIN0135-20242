#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void main()
{
    //// Começa criando a lista, chamando a função apropriada
    // No *lista = create_list(); //* Se quiser index = 0, valor = 0
    No *lista = create_list(1,59); //* Se quiser index = parâmetro, valor = parâmetro

    //// Insere valores na lista, através da função append, que insere os valores no final da lista
    append(lista, 126); // 1
    append(lista, 463); // 2
    append(lista, 597); // 3
    append(lista, 850); // 4
    insert(lista, 23513, 8);
    insert(lista, 4387, 10);
    append(lista, 12395);
    insert(lista, 23968, 6);
    insert(lista, 28, 2);

    //// Printa a lista com os valores inseridos
    print_list(lista);

    // find_pos(lista, 597);  //* Retorna a posição na lista onde está o valor dado no parâmetro
    // find_val(lista, 1265); //* Retorna o valor que está na posição dado no parâmetro
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