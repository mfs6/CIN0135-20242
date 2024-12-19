#include <iostream>

class Node {
    friend class LinkedList;
public:
    Node() {val = -1;}
    Node(int v);
private:
    int val;
    Node *next;
};

Node::Node(int v) {
    val = v;
    next = nullptr;
}


class LinkedList 
{
public:
    LinkedList() {
        head = new Node();
        sz = 0;
    };
    void append(int val);
    int size() {
        return sz;
    }
    int operator[](int pos);
private:
    Node *head;
    int sz;
};

void LinkedList::append(int val) {
    Node *cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;        
    }
    Node *tail = new Node(val);
    cur->next = tail;   
    sz++;
}

int LinkedList::operator[](int pos) {
    Node *cur = head;
    int i = 0;
    while( i < pos && cur->next != nullptr) {
        cur = cur->next;
        i++;
    }
    return cur->next->val;
}

using namespace std;

int main() {
    LinkedList list;
    list.append(2);
    list.append(3);
    list.append(5);
    list.append(7);

    for (int i = 0; i < list.size(); i++) {
        cout << "list[" << i << "] = " << list[i] << endl;
    }

}

/*

Node *create_list() {
    return create_node(-1);
}




Node *find_pos(Node *head, size_t pos) {
    Node *cur = head;
    size_t i = 0;
    while( i < pos && cur->next != NULL) {
        cur = cur->next;
        i++;
    }
    return cur;
}


Node *find_val(Node *head, int val) {
    Node *cur = head;
    while( cur->next != NULL && cur->next->val != val ) {
        cur = cur->next;
    }
    return cur;
}

Node *insert_at(Node *cur, int val) {
    Node *new_node = create_node(val);
    new_node->next = cur->next;
    cur->next = new_node;
    return cur;
}

Node *insert(Node *head, size_t pos, int val) {
    Node *cur = find_pos(head, pos);
    Node *new_node = create_node(val);
    new_node->next = cur->next;
    cur->next = new_node;
    return cur;
}


Node *delete(Node *cur) {
    Node *to_die = cur->next;
    cur->next = to_die->next;
    free(to_die);
    return cur;
}


int main() {
    Node *head = create_list();
    printf("%d\n", (*head).val);    
    append(head, 2);
    append(head, 3);
    append(head, 5);
    append(head, 7);



    size_t pos = 7;
    Node *node = NULL;
    node = find_pos(head, pos);
    if (node->next != NULL) {
        printf("list[%d] = %d\n", pos, node->next->val );
    } else {
        printf("Out of bounds\n");
    }
    
    int val = 9;
    node = find_val(head, val);
    if (node->next != NULL) {
        printf("node val = %d\n", node->next->val );
    } else {
        printf("not found\n");
    }

    pos = 2;
    val = 4;
    node = insert(head, pos, val);
    if (node->next != NULL) {
        printf("node val = %d\n", node->next->val );
    } else {
        printf("not found\n");
    }

    node = find_val(head, 4);
    node = delete(node);
    if (node->next != NULL) {
        printf("node val = %d\n", node->next->val );
    } else {
        printf("not found\n");
    }


}
*/