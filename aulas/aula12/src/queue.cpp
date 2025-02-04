#include "list.hpp"


class Queue {
public:
    Queue() = default;
    ~Queue() = default;
    int size() {
        return list.size();
    }
    void enqueue(int val) {
        list.prepend(val);
    }
    int  dequeue() {
        return list.remove(0);
    }
private:
    //ArrayList list;
    LinkedList list;
};


int main() {
    Queue q;
    int n = 1 << 4;
    for (int i = 0; i < n; i++) {
       q.enqueue(i); 
    }
    int half = q.size() / 2;
    for (int i = 0; i < half; i++) {
        cout << "dequeue " << q.dequeue() << endl;
    }
}
    
