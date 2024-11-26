#include <stdio.h>

int quadrado(int v)
{
	return v * v;
}


int soma(int a, int b)
{
	int a2 = quadrado(a);
	int b2 = quadrado(b);
	return a2 + b2 ;
}


int fat(int x)
{
	if (x <= 2 ) return x;
	return x * fat(x - 1);
}


int main()
{

	int a, b;
	a = 20;
	b = 10;

	int c = soma(a, b);
	printf("%d^2 + %d^2 = %d\n", a, b, c);

	int f = fat(a / 5);
	printf("%d! = %d\n", a / 5, f);

}
