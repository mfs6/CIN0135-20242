#include <iostream>

using namespace std;

template <typename T>
class Box
{
public:
	T value;
};

template <typename T>
void store(Box<T> &ref, T v)
{
	ref.value = v;
}

int main()
{
	Box<double> myobj;
	myobj.value = 10; // pelo identificador
	cout << myobj.value << endl;

	Box<double> *myptr = &myobj;
	myptr->value = 20; // pelo ponteiro
	cout << myobj.value << endl;
	cout << myptr->value << endl;

	Box<char> myobj2;
	myobj2.value = 'A';

	Box<double> &myref = myobj;
	myref.value = 50; // pela referencia
	cout << myref.value << endl;
	store(myobj, 60.0);
	cout << myref.value << endl;
}
