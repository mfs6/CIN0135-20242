#include "list.hpp"
// #include "arraylist.hpp" //* aula11

class fila
{
public:
    fila() = default;  //* Construtor (usa a construtor padrão da lista)
    ~fila() = default; //* Destrutor (usa a destrutor padrão da lista)
    int size()
    {
        return list.size();
    };
    void enqueue(int val)
    {
        list.append(val);
    }; //* Enfileirar (adicionar)
    int dequeue()
    {
        return list.remove(0);
    }; //* Tirar da fila
private:
    LinkedList list;
    // ArrayList list; //* aula11
};

void main()
{
    fila q;         //* Cria fila
    int n = 1 << 4; //* Left Shift (<<) = 16      10000
    // int n = 2 << 4; //* Left Shift (<<)= 32   100000
    for (int i = 0; i < n; i++)
    {
        q.enqueue(i);
    }

    int half = q.size() / 2;
    for (int i = 0; i < half; i++)
    {
        cout << "dequeue " << q.dequeue() << endl;
    }
}

//! Criar pilha