#include <stdio.h>
#include <math.h>

int ehPrimo(int n) {
    if (n <= 1) return 0; // Números menores ou iguais a 1 não são primos
    
    double k = sqrt(n);
    for (int i = 2; i <= k/*sqrt(n)*/; i++) { // Testa até a raiz quadrada de n
        if (n % i == 0) return 0; // Se for divisível, não é primo
    }
    return 1; // É primo
}

int main() {
    int numero = 29;

    if (ehPrimo(numero)) {
        printf("%d é primo.\n", numero);
    } else {
        printf("%d não é primo.\n", numero);
    }

    return 0;
}