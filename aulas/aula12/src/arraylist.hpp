#include <cstddef>
#include <iostream>

using namespace std;

class ArrayList {
public:
    ArrayList();
    ~ArrayList();
    size_t size() {return sz;}
    int operator[](size_t pos) {return arr[pos];}
    void insert(size_t pos, int val);
    void append(int val);
    void prepend(int val) {
        insert(0, val);
    }
    int remove(size_t pos);
private:
    size_t sz;
    size_t cap;
    int *arr;
    void check_and_double();
};

ArrayList::ArrayList() {
    cap = 1;
    sz = 0;
    arr = new int[cap];
}

ArrayList::~ArrayList() {
    delete[] arr;
}

void ArrayList::check_and_double() {
    if (sz < cap) return;
    cout << "Doubling" << endl;
    size_t new_cap = 2 * cap;
    int *new_arr = new int[new_cap];
    for (size_t i = 0; i < sz; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}

void ArrayList::insert(size_t pos, int val) {
    check_and_double();
    pos = (pos > sz) ? sz : pos;
    for (size_t i = sz; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    sz++;
}

void ArrayList::append(int val) {
    insert(sz, val);
}

int ArrayList::remove(size_t pos) {
    if (pos >= sz) {
        cout << "Out of bounds" << endl;
        exit(1);
    }
    int ret = arr[pos];
    for (size_t i = pos; i < sz-1; i++) {
        arr[i] = arr[i+1];
    }
    sz--;
    return ret;
}
