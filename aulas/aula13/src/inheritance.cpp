#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "constructor Base" << endl;
	};
	~Base()
	{
		cout << "destructor Base" << endl;
	};
	int F();
	virtual int G(int v);
	int g{1};
private:
	int f{0};
};


int Base::F()
{
	return f;
}

int Base::G(int v)
{
	g += v;
	return g;
}

class Derived1: public Base
{
public:
	Derived1()
	{
		cout << "constructor Derived1" << endl;
	}
	~Derived1()
	{
		cout << "destructor Derived1" << endl;
	}
	int G(int v);
};

int Derived1::G(int v)
{
	g *= v;
	return g;
}



class Derived2: public Base
{
public:
	Derived2()
	{
		cout << "constructor Derived2" << endl;
	}
	~Derived2()
	{
		cout << "destructor Derived2" << endl;
	}
	int G(int v);
};


int Derived2::G(int v)
{
	g -= v;
	return g;
}



int main()
{
	Base b;
	cout << "Base " << b.F() << endl;
	cout << "Base " << b.G(10) << endl;

	Derived1 d1;
	cout << "Derived1 " << d1.F() << endl;
	cout << "Derived1 " << d1.G(10) << endl;

	Derived2 d2;
	cout << "Derived2 " << d2.F() << endl;
	cout << "Derived2 " << d2.G(10) << endl;
}
