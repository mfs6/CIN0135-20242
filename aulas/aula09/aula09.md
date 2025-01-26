## Aula 07,  10-12-2024 

## Listas Encadeadas II

(Parte I [aqui](../aula08/aula08.md))

### Definição

* ED linear homogênea dinâmica
    - "linear": elementos em sequência, identificados por posição
    - "homogêna": elementos do mesmo tipo
    - "dinâmica": quantidade variável de elementos e memória

### Representação

* Cada elemento armazenado num "**Nó**"
* Além do valor do elemento (`val`), cada nó possui uma *referência* (ponteiro) para o próximo nó (`next`)

```
Linked List Node

+-------+--------+
|  val  |  next -|--->
+-------+--------+

```
Em C

```C
struct Node {
    int val;
    struct Node *next;
};
typedef struct Node Node;
```


* Guardamos uma referência especial para o primeiro Nó da lista, chamado **cabeça** (*head*).
* Além disso, usamos a representação de [[1]]() em que sempre temos um nó inicial chamado **sentinela**, cujo valor não faz parte **logicamente** da lista. O nó sentinela serve apenas para demarcar **fisicamente** o início da lista.

### Exemplos

A) Lista Vazia

```
          +---+---+  
head ---->| \ |  -|---+
          +---+---+   |
                      | 
                     ===
```

Repare que a lista vazia tem pelo menos o nó sentinela, ou seja `head` é sempre um ponteiro para um nó válido.


B) Lista com os 4 primeiros primos

```
Índices "lógicos" 
dos elementos:            [0]          [1]          [2]          [3]

          +---+---+    +---+---+    +---+---+    +---+---+    +---+---+   
head ---->| \ |  -|--->| 2 |  -|--->| 3 |  -|--->| 5 |  -|--->| 7 |  -|---+
          +---+---+    +---+---+    +---+---+    +---+---+    +---+---+   |
                                                                          | 
                                                                         ===
```

### Operações básicas

0) Inicialização de uma Lista vazia
1) Acesso por posição
2) Busca por valor
3) Inserção
4) Remoção


#### Inicialização de uma Lista vazia

```C
Node *create_list() {
    Node *head = malloc(sizeof(Node));
    (*head).val = -1;
    (*head).next = NULL;
    return head;
}

int main() {
    ...
    Node *head = create_list();
    ...
}
```

#### Acesso por posição

1. Cria um cursor `cur` apontando para o nó sentinela
2. Inicializa um contador de posição corrente `i=0`

```C

```


<a name="referencias"></a>
### Referências

[1] [Clifford Shaffer. Data structures and algorithm analysis in C++](http://people.cs.vt.edu/~shaffer/Book/)
