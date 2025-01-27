## Aula 07,  10-12-2024 

## Listas Encadeadas II

(Parte I [aqui](../aula08/aula08.md))


#### Acesso por posição

1. Cria um cursor `cur` indicador da posição corrente apontando para o nó sentinela
2. Inicializa o índice de posição corrente `i=0`
3. Enquanto a posição corrente for menor do que a posição desejada `pos`:

    3.1. Avança o cursor para o próximo elemento
    3.2. Incrementa o índice da posição corrente
4. Retorna o cursor na posição atual

```C
Node *find_pos(Node *head, size_t pos) {
    Node *cur = head;
    size_t i = 0;
    while( i < pos && cur->next != NULL) {
        cur = cur->next;
        i++;
    }
    return cur;
}
```

**IMPORTANTE:**
* Nesta representação, uma referência "**lógica**" para um elemento/nó é dada por um ponteiro "**físico**" para o nó imediatamente anterior.
* Desta forma, o primeiro elemento, de índice `[0]`) é representado por um ponteiro para o nó sentinela (i.e. com o mesmo valor de `head`).
* Sabemos que uma referência `cur` é válida, i.e. se referencia um elemento dentro dos limites do tamanho da lista, se `cur->next != NULL`.


#### Busca por valor 

Ideia semelhante à busca por posição, varrendo a lista um Nó de cada vez até encontrar o valor procurado ou atingir o último elemento da lista (**cauda**).

1. Cria um cursor `cur` indicador da posição corrente apontando para o nó sentinela
2. Enquanto o valor do elemento corrente (que é o do nó seguinte ao cursor) for diferente do valor procurado, ou chegou à cauda da lista:
    2.1. Avança o cursor para o próximo elemento
    2.2. Incrementa o índice da posição corrente
4. Retorna o cursor na posição atual

```C
Node *find_val(Node *head, int val) {
    Node *cur = head;
    while( cur->next != NULL && cur->next->val != val ) {
        cur = cur->next;
    }
    return cur;
}
```

#### Inserção

Para inserir um novo nó na posição dada por um cursor `cur`:

```
Passo 1) cria novo nó com valor desejado

          +---+---+                      +---+---+    
 ...  --->| X |  -|--------------------->| Z |  -|--- ...
          +---+---+                      +---+---+  
            ^  
            |            +---+---+
           cur           |val|   |
                         +---+---+
                           ^
                           |
                     (1) new_node


Passo 2) ajusta o sucessor (next) do novo nó

          +---+---+                      +---+---+    
 ...  --->| X |  -|--------------------->| Z |  -|--- ...
          +---+---+                  +-->+---+---+  
            ^                        |
            |            +---+---+   |
           cur           |val|  -|---+ (2)
                         +---+---+
                           ^
                           |
                        new_node

Passo 3) ajusta o sucessor do cursor

          +---+---+                      +---+---+    
 ...  --->| X |  -|--+  \  ---       +-->| Z |  -|--- ...
          +---+---+  |               |   +---+---+  
            ^        |               |
            |    (3) |   +---+---+   |
           cur       +-->|val|  -|---+ 
                         +---+---+
                           ^
                           |
                        new_node
```

```C
Node *insert_cur(Node *cur, int val) {
    Node *new_node = create_node(val);
    new_node->next = cur->next;
    cur->next = new_node;
    return cur;
}
```
**NOTA:** O cursor agora representa uma referência lógica para o novo nó que foi inserido.


Podemos combinar essa função com a localização por posição para inserir um nó numa dada posição `pos` da lista.

```C
Node *insert_at(Node *head, size_t pos, int val) {
    Node *cur = find_pos(head, pos);
    Node *new_node = create_node(val);
    new_node->next = cur->next;
    cur->next = new_node;
    return cur;
}
```

**NOTA**: Se a lista tem tamanho (lógico) `n` (`n+1` nós, incluindo o sentinela):
* Inserir no início da lista: `insert_cur(head, val) == insert_at(head, 0, val)`
* Inserir no final da lista: `insert_at(head, n-1, val) == append(head, val)`

#### Remoção

Para remover um nó válido da posição corrente referenciado por um cursor `cur` (pré-condição: `cur->next != NULL`)

```
Passo 1) cria ponteiro para nó a ser removido 

          +---+---+       +---+---+        +---+---+    
 ...  --->| X |  -|------>| Y |  -|------->| Z |  -|--- ...
          +---+---+       +---+---+        +---+---+  
            ^               ^ 
            |               |
           cur         (1) to_die
                       

Passo 2) ajusta o sucessor do cursor  (bypass)

                        (2)
                     +-----------------+
                     |                 |
          +---+---+  |    +---+---+   +--->+---+---+    
 ...  --->| X |  -|--+ \  | Y |  -|------->| Z |  -|--- ...
          +---+---+       +---+---+        +---+---+  
            ^               ^ 
            |               |
           cur             to_die
                       

Passo 3) apaga o nó pretendido da memória
                        

                     +-----------------+
                     |                 |
          +---+---+  |    /////////    |    +---+---+    
 ...  --->| X |  -|--+    /////////    +--->| Z |  -|--- ...
          +---+---+       /////////         +---+---+  
            ^               ^ 
            |               |
           cur             to_die (3)
                       

```

```C
Node *delete(Node *cur) {
    assert(cur->next);
    Node *to_die = cur->next;
    cur->next = to_die->next;
    free(to_die);
    return cur;
}
```


<a name="referencias"></a>
### Referências

[1] [Clifford Shaffer. Data structures and algorithm analysis in C++](http://people.cs.vt.edu/~shaffer/Book/)
