#include <cassert>
#include <iostream>

using namespace std;


class Node
{
	friend class LinkedList;
public:
	Node()
	{
		val = -1;
		next = nullptr;
	}
	Node(int v)
	{
		val = v;
		next = nullptr;
	}
	~Node()
	{
		//    cout << "deleting " << val << endl;
	}
private:
	int val;
	Node *next;
};


class LinkedList
{
public:
	LinkedList()
	{
		head = new Node();
		sz = 0;
	};
	~LinkedList();
	void append(int val);
	int size()
	{
		return sz;
	}
	int operator[](int pos);
	int remove(int pos);
private:
	Node *head;
	int sz;
};

LinkedList::~LinkedList()
{
	Node *cur = head;
	while (cur != nullptr) {
		Node *next = cur->next;
		delete cur;
		cur = next;
	}
}

void LinkedList::append(int val)
{
	Node *cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	Node *tail = new Node(val);
	cur->next = tail;
	sz++;
}

int LinkedList::operator[](int pos)
{
	Node *cur = head;
	int i = 0;
	while ( i < pos && cur->next != nullptr) {
		cur = cur->next;
		i++;
	}
	return cur->next->val;
}


int LinkedList::remove(int pos)
{
	Node *cur = head;
	int i = 0;
	while ( i < pos && cur->next != nullptr) {
		cur = cur->next;
		i++;
	}
	Node *to_die = cur->next;
	cur->next = to_die->next;
	int ret = to_die->val;
	delete to_die;
	sz--;
	return ret;
}




int main()
{
	LinkedList list;

	size_t n = 1 << 16;
	for (int i = 1; i <= n; i++) {
		list.append(2 * i);
	}

	cout << "size = " << list.size();
}

