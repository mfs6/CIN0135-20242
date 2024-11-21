#include <stdbool.h>
#include <stdio.h>

int main()
{
	int i = 1024;
	printf("valor de i = %d\n", i);
	printf("tamanho de i = %ld\n", sizeof(i));
	printf("endereço de i = %ld\n", &i);

	int *p;  // declara var ponteiro para int
	p = &i;
	printf("valor de p = %ld\n", p);
	printf("tamanho de p = %ld\n", sizeof(p));
	printf("endereço de p = %ld\n", &p);

	int j = -127;
	*p = j;
	printf("valor de i = %d\n", i);
	printf("tamanho de i = %ld\n", sizeof(i));
	printf("endereço de i = %ld\n", &i);
}
