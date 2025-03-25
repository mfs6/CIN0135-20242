#pragma once

#include <cassert>
#include <iostream>

// -----------------------------------------------------------------
// DECLARACOES DOS TAD
// -----------------------------------------------------------------

//
// Classe abstrata/Interface para listas
//
template <typename T>
class List
{
public:
	virtual ~List() {};
	int size() const;						 // retorna o tamanho da lista
	virtual T &operator[](int pos) = 0;		 // retorna o elemento da posicao pos
	virtual void insert(int pos, T val) = 0; // insere val na posicao pos
	void append(T val);						 // adiciona ao final
	void prepend(T val);					 // adiciona no inicio
	virtual T remove(int pos) = 0;			 // remove e retorna o elemento da posicao pos
protected:
	int sz{0}; // tamanho da lista
};

//
// Lista encadeada
//
template <typename T>
class LinkedList : public List<T>
{
	// Tipo no da lista encadeada
	struct Node
	{
		explicit Node(T v, Node *nxt = nullptr) : val{v}, next{nxt} {}
		explicit Node(Node *nxt = nullptr) : next{nxt} {}
		~Node() {}

		// ADD CODE HERE
		// atributos
		T val;		// Valor do nó
		Node *next; // Ponteiro para o próximo nó
	};

public:
	LinkedList();
	~LinkedList();
	// metodos da interface List
	T &operator[](int pos) override;
	void insert(int pos, T val) override;
	T remove(int pos) override;

public:
	// Metodos adicionais

	// Concatena a lista other ao final desta lista
	// Os elementos devem ser removidos de other
	// mas a lista other nao deve ser destruida
	void merge(LinkedList<T> *other);

	// Divide a lista de duas metades.
	// Esta lista fica com os primeiros floor(n/2) elementos.
	// Os restantes elementos sao colocados numa nova lista
	// retornada pelo metodo.
	LinkedList<T> *split();

private:
	Node *locate(int pos); // localiza o no da posicao pos

	// ADD CODE HERE
	// atributos
	Node *head; // Ponteiro para o primeiro nó
	Node *tail; // Ponteiro para o último nó
};

//
// Tipos de SQ
//
enum TYPE
{
	STACK = 0, // Pilha
	QUEUE = 1  // FIla
};

//
// Classe para representar objetos que podem ser pilha ou fila
//
template <typename T>
class SQ
{
public:
	TYPE Type() const; // retorna o tipo da SQ (vide enum TYPE)
	SQ(TYPE t);		   // recebe o tipo do SQ na construcao
	int size() const;  // retorna o numero de elementos na SQ
	const T &peek();   // retorna uma referencia para o elemento no topo/frente da pilha/fila
	void push(T val);  // empilha/enfileira
	T pop();		   // desempilha/desenfileira
	void transform();  // transforma de pilha para fila ou vice versa
	// Divide como no enunciado:
	// os primeiros floor(n/2) elementos permanecesm nesta SQ
	// e os demais sao retornados numa nova SQ
	SQ<T> *split();
	// Combina como enunciado:
	// os elementos de other sao transferidos para esta SQ,
	// de forma que other fica vazia, mas nao eh destruida
	void merge(SQ<T> *other);

private:
	TYPE type; // tipo da SQ

	// ADD CODE HERE
	// Lembre da composicao
	LinkedList<T> list; // Instância da Lista encadeada
};

// -----------------------------------------------------------------
// IMPLEMENTACOES DOS TAD
// -----------------------------------------------------------------

template <typename T>
int List<T>::size() const
{
	return this->sz;
}

// ADD CODE HERE
// Definicoes dos metodos

// Lista abstrata

template <typename T>
void List<T>::append(T val) // Adiciona um nó no final
{
	Node *newNode = new Node(val);
	if (tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	this->sz++; // Como adicionou, incrementa o tamanho da lista
}

template <typename T>
void List<T>::prepend(T val) // Adiciona um nó no início
{
	Node *newNode = new Node(val);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	this->sz++; // Como adicionou, incrementa o tamanho da lista
}

// Lista encadeada

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() // Destrutor
{
	Node *current = head;
	while (current != nullptr) // Enquanto o nó atual não for nulo
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
}

template <typename T>
T &LinkedList<T>::operator[](int pos) // Retorna o valor do nó na posição passada
{
	Node *current = locate(pos); // Localiza o nó na posição passada, chamando o método locate
	assert(current != nullptr);	 // Verifica se o nó foi encontrado, ou seja, se a posição passada é válida
	return current->val;		 // Se sim, retorna o valor do nó
}

template <typename T>					   // Rever os comentários pra fixar melhor
void LinkedList<T>::insert(int pos, T val) // Insere um valor na posição passada (valor este que tem um tipo abstrato)
{
	if (pos == 0)
	{
		prepend(val);
	}
	else
	{
		Node *prev = locate(pos - 1); // Localiza o nó anterior ao nó que será inserido, chamando o método locate
		assert(prev != nullptr);
		prev->next = new Node(val, prev->next); // Cria um novo nó com o valor passado e o próximo nó sendo o nó que estava na posição passada
		if (prev->next->next == nullptr)		// Se o próximo nó do que foi inserido for nulo, então, ele é o último
		{
			tail = prev->next; // Portanto a cauda passa a apontar para o nó inserido
		}
		{
			tail = prev->next; // Se não, a cauda continua apontando para o último nó, que não foi alterado
		}
		this->sz++; // Como adicionou, incrementa o tamanho da lista
	}
}

template <typename T>
T LinkedList<T>::remove(int pos) // Remove um nó da posição passada
{
	assert(pos >= 0 && pos < this->sz);
	Node *prev = nullptr;
	Node *current = head;
	for (int i = 0; i < pos; ++i)
	{
		prev = current;
		current = current->next;
	}
	if (prev == nullptr)
	{
		head = current->next;
	}
	else
	{
		prev->next = current->next;
	}
	if (current->next == nullptr)
	{
		tail = prev;
	}
	T val = current->val;
	delete current;
	this->sz--;
	return val;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::locate(int pos) // Localiza o nó na posição passada
{
	assert(pos >= 0 && pos < this->sz);
	Node *current = head;
	for (int i = 0; i < pos; ++i)
	{
		current = current->next;
	}
	return current;
}

template <typename T>
void LinkedList<T>::merge(LinkedList<T> *other)
{
	if (other->head == nullptr)
		return; // Se a outra lista estiver vazia, não faz nada

	if (this->tail != nullptr)
	{
		this->tail->next = other->head; // Conecta o final desta lista ao início da outra lista
	}
	else
	{
		this->head = other->head; // Se esta lista estiver vazia, a cabeça passa a ser a cabeça da outra lista
	}
	this->tail = other->tail; // A cauda passa a ser a cauda da outra lista
	this->sz += other->sz;	  // Atualiza o tamanho da lista

	// Limpa a outra lista
	other->head = nullptr;
	other->tail = nullptr;
	other->sz = 0;
}

template <typename T>
LinkedList<T> *LinkedList<T>::split()
{
	LinkedList<T> *newList = new LinkedList<T>();
	int mid = this->sz / 2;
	if (mid == 0)
		return newList; // Se a lista tiver tamanho 0 ou 1, a nova lista será vazia

	Node *current = this->head;
	for (int i = 0; i < mid - 1; ++i)
	{
		current = current->next;
	}

	newList->head = current->next;
	newList->tail = this->tail;
	newList->sz = this->sz - mid;

	this->tail = current;
	this->tail->next = nullptr;
	this->sz = mid;

	return newList;
}

// Pilha/Fila

template <typename T>
SQ<T>::SQ(TYPE t) : type(t) {}

template <typename T>
TYPE SQ<T>::Type() const
{
	return type;
}

template <typename T>
int SQ<T>::size() const
{
	return list.size();
}

template <typename T>
const T &SQ<T>::peek()
{
	if (type == STACK)
	{
		return list[list.size() - 1]; // topo da pilha
	}
	else
	{
		return list[0]; // frente da fila
	}
}

template <typename T>
void SQ<T>::push(T val)
{
	if (type == STACK)
	{
		list.append(val); // empilha
	}
	else
	{
		list.append(val); // enfileira
	}
}

template <typename T>
T SQ<T>::pop()
{
	if (type == STACK)
	{
		return list.remove(list.size() - 1); // desempilha
	}
	else
	{
		return list.remove(0); // desenfileira
	}
}

template <typename T>
void SQ<T>::transform()
{
	if (type == STACK)
	{
		type = QUEUE;
	}
	else
	{
		type = STACK;
	}
}

template <typename T>
SQ<T> *SQ<T>::split()
{
	SQ<T> *newSQ = new SQ<T>(type);
	int mid = size() / 2;
	for (int i = mid; i < size(); ++i)
	{
		newSQ->push(pop());
	}
	return newSQ;
}

template <typename T>
void SQ<T>::merge(SQ<T> *other)
{
	while (other->size() > 0)
	{
		push(other->pop());
	}
}