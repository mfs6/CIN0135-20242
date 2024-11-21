#include <stdbool.h>
#include <stdio.h>


int main()
{

	bool b = true; // tipo booleano true/false. definido em <stdbool.h>

	char c = 'a';  // caractere

	int i = 1024;  // inteiro com sinal

	long l = 1024; // inteiro longo com sinal

	int ui = 1024;  // inteiro sem sinal

	long ul = 1024; // inteiro longo sem sinal sinal

	float f = 1.0 / 3; // ponto flutuante (precisao simples)

	double d = 1.0 / 3; // ponto flutuante (precisao dupla)


	// Operador sizeof retorna o tamanho, i.e.
	// o espaco na memoria ocupado por uma variavel em bytes

	printf("bool b = %b tamanho = %lu\n", b, sizeof(b));
	printf("char c = %c tamanho = %lu\n", c, sizeof(c));
	printf("int i = %d tamanho = %lu\n", i, sizeof(i));
	printf("long l = %ld tamanho = %lu\n", l, sizeof(l));
	printf("float f = %.20f tamanho = %lu\n", f, sizeof(f));
	printf("double d = %.20lf tamanho = %lu\n", d, sizeof(d));


	// cuidado com o overflow em tipos inteiros

	int max_int = (1 << ((8 * sizeof(int)) - 1)) - 1; //  maior valor de um int
	printf ("max_int = %d\t = %.32b\n", max_int, max_int);

	max_int += 1;
	printf ("max_int = %d\t = %.32b\n", max_int, max_int);
}
