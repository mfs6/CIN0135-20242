#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

using namespace std;

class Base
{
public:
    Base();  //* Construtor
    ~Base(); //* Destrutor

    int F();

    /* int F()
    {
        return f;
    } */

private:
    int f{0};
};

int Base::F()
{
    return f;
}

void main()
{
    Base b;
    int a = b.F();
    // cout << "a" << endl; //ver cout
    //printf("%d", a);
}
