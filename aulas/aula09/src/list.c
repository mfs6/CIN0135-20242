#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct Node {
    int val;
    struct Node *next;
};

typedef struct Node Node;


Node *create_node(int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}


Node *create_list() {
    return create_node(-1);
}


void append(Node *head, int val) {
    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;        
    }
    Node *tail = create_node(val);
    cur->next = tail;   
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