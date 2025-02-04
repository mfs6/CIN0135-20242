#include <cassert>
#include <iostream>

using namespace std;

class List
{
public:
	int size()
	{
		return sz;
	};
	virtual int get(int pos) = 0;
	virtual void insert(int pos, int val) = 0;
	void append(int val)
	{
		insert(size(), val);
	}
	void prepend(int val)
	{
		insert(0, val);
	}
	virtual int remove(int pos) = 0;
protected:
	int sz{0};
};



class LinkedList : public List
{
	struct Node {
		Node(int v,  Node *nxt = nullptr): val{v}, next{nxt} { }
		~Node()
		{
			cout << "deleting " << val << endl;
		}
		int val;
		Node *next;
	};

public:
	LinkedList()
	{
		head = new Node(-1);
		sz = 0;
	};
	~LinkedList();
	int get(int pos) override;
	void insert(int pos, int val) override;
	int remove(int pos) override;
private:
	Node *locate(int pos);
	Node *head;
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

LinkedList::Node *LinkedList::locate(int pos)
{
	Node *cur = head;
	for (int i = 0;  i < pos && cur->next != nullptr; i++) {
		cur = cur->next;
	}
	return cur;
}

int LinkedList::get(int pos)
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

class ArrayList : public List
{
	static const int DEFAULT_CAPACITY = 1;
public:
	ArrayList(int cap = ArrayList::DEFAULT_CAPACITY);
	~ArrayList();
	int get(int pos) override
	{
		return arr[pos];
	}
	void insert(int pos, int val) override;
	int remove(int pos) override;
private:
	int cap;
	int *arr;
	void check_and_double();
};


ArrayList::ArrayList(int initial_cap)
{
	cap = initial_cap;
	sz = 0;
	arr = new int[cap];
}

ArrayList::~ArrayList()
{
	delete[] arr;
}

void ArrayList::check_and_double()
{
	if (sz < cap) return;
	cout << "Doubling" << endl;
	int new_cap = 2 * cap;
	int *new_arr = new int[new_cap];
	for (int i = 0; i < sz; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	cap = new_cap;
}

void ArrayList::insert(int pos, int val)
{
	check_and_double();
	pos = (pos > sz) ? sz : pos;
	for (int i = sz; i > pos; i--) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = val;
	sz++;
}

int ArrayList::remove(int pos)
{
	if (pos >= sz) {
		cout << "Out of bounds" << endl;
		exit(1);
	}
	int ret = arr[pos];
	for (int i = pos; i < sz - 1; i++) {
		arr[i] = arr[i + 1];
	}
	sz--;
	return ret;
}


int sum(List *list)
{
	int s = 0;
	for (int i = 0; i < list->size(); i++)
		s += list->get(i);
	return s;
}


int main()
{
	LinkedList list;

	int n = 1 << 4;
	for (int i = 0; i < n; i++) {
		list.append(2 * i);
	}
	int half = n / 2;
	for (int i = 0; i < half; i++) {
		list.remove(i);
	}
	for (int i = 0; i < half; i++) {
		list.insert(2 * i, 4 * i);
	}

	int s = sum(&list);
	cout << "sum linkedlist = " << s;



	List *alist = new ArrayList(10);

	for (int i = 0; i < n; i++) {
		alist->insert(alist->size(), 2 * i);
	}
	for (int i = 0; i < half; i++) {
		alist->remove(i);
	}
	for (int i = 0; i < half; i++) {
		alist->insert(2 * i, 4 * i);
	}

	s = sum(alist);
	cout << "sum linkedalist = " << s;
}



