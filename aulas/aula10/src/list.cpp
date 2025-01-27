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
		cout << "deleting " << val << endl;
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
	int size()
	{
		return sz;
	}
	int operator[](int pos);
	void insert(int pos, int val);
	void append(int val);
	void prepend(int val);
	int remove(int pos);
private:
	Node *locate(int pos);
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


Node *LinkedList::locate(int pos)
{
	Node *cur = head;
	int i = 0;
	while ( i < pos && cur->next != nullptr) {
		cur = cur->next;
		i++;
	}
	return cur;
}

int LinkedList::operator[](int pos)
{
	assert(pos < sz);
	return locate(pos)->next->val;
}


void LinkedList::insert(int pos, int val)
{
	assert(pos <= sz);
	Node *cur = locate(pos);
	Node *new_node = new Node(val);
	new_node->next = cur->next;
	cur->next = new_node;
	sz++;
}

void LinkedList::append(int val)
{
	return insert(sz, val);
}

void LinkedList::prepend(int val)
{
	return insert(0, val);
}


int LinkedList::remove(int pos)
{
	assert (pos < sz);
	Node *cur = locate(pos);
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

	size_t n = 1 << 4;
	for (int i = 0; i < n; i++) {
		list.append(2 * i);
	}
	for (int i = 0; i < list.size(); i++) {
		cout << "list[" << i << "]= " << list[i] << endl;
	}
	cout << endl;
	size_t half = n / 2;
	for (int i = 0; i < half; i++) {
		list.remove(i);
	}
	for (int i = 0; i < list.size(); i++) {
		cout << "list[" << i << "]= " << list[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < half; i++) {
		list.insert(2 * i, 4 * i);
	}
	for (int i = 0; i < list.size(); i++) {
		cout << "list[" << i << "]= " << list[i] << endl;
	}
	cout << endl;

	cout << "size = " << list.size();
}

