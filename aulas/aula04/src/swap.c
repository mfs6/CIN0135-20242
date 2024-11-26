#include <stdio.h>


void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int main()
{

	int a, b;
	a = 20;
	b = 10;

	printf("antes a=%d b=%d\n", a, b );

	swap(&a, &b);

	printf("depois a=%d b=%d\n", a, b );

}
