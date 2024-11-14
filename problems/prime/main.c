#include <stdio.h>
#include "prime.h"

int main() {

	int N;
	
	printf("Insert Number\n");
	scanf("%d", &N);

	printf("%d\n", is_prime(N));

	return 0;
}


