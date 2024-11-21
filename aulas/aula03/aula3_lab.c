#include <stdio.h>
#include <stdbool.h> // define o booleano

void main()
{
    char c = 'c';          // Para definir o char usar aspas simples -> ''
    printf("c = %c\n", c); // Marcador é %c

    bool b = true;           // Na verdade é um inteiro, sendo false = 0 e true=1
    printf("\nb = %d\n", b); // Usa o marcador %d que é de inteiro

    short s = 0b0111111111111111; // Um short pode armazernar no máximo um número de 16 bits ou 2 bytes
    // O bit mais signicativo (mais a esquerda) é o do sinal, sendo 0 para + e 1 para -
    // O maior short inteiro positivo escrito em binário equivale a 32767 = (2^15)-1
    // Para escrever um short em binário usa o 0b como em verilog
    printf("\ns = %d\n", s); // Usa o marcador %d que é de inteiro
    s++;                     // Caso some +1 ele "aumenta o número" mas o torna negativo, pois 1 = 1 em binário
    printf("s++ = %d\n", s);

    int n = 0b01111111111111111111111111111111; // Um int pode armazernar no máximo um número de 32 bits ou 4 bytes, ou seja o dobro de um short
    // O bit mais signicativo (mais a esquerda) é o do sinal, sendo 0 para + e 1 para -
    // O maior int inteiro positivo escrito em binário equivale a 2147483647 = (2^31)-1
    // Para escrever um int em binário usa o 0b como em verilog
    printf("\nn = %d\n", n); // Usa o marcador %d que é de fato dos inteiros
    n++;                     // Caso some +1 ele "aumenta o número" mas o torna negativo, pois 1 = 1 em binário
    printf("n++ = %d\n", n);

    long l = 0b0111111111111111111111111111111111111111111111111111111111111111; // Um long ou long int pode armazernar no máximo um número de 64 bits ou 8 bytes, ou seja o dobro de um int
    // O bit mais signicativo (mais a esquerda) é o do sinal, sendo 0 para + e 1 para -
    // O maior inteiro positivo escrito em binário equivale a 9223372036854775807 = (2^63)-1
    // Para escrever um long em binário usa o 0b como em verilog

    printf("\nl = %d\n", l); /* Dá um warning que avisa que o número l pode não caber num int que tem a marcação %d, aparentemente resulta em -1 sempre que não couber*/
    // Claro que nesse exemplo não cabe porque l é o maior long possível
    printf("l = %ld\n", l); // O ideal é usar a marcação %ld

    float f = 3.14;
    printf("\nf = %f\n", f); // Marcador é %f

    int i = 1024;
    printf("\nValor de i = %d\n", i);
    printf("Tamanho de i = %ld\n", sizeof(i)); // Exemplo do sizeof() que retorna o máximo de bytes que o tipo da variável do parametro pode conter
    printf("Endereço de i = %ld\n", &i);       // Exemplo de como encontrar o endereço da memória que contem o valor da variável (usar a marcação &)

    /*-------------------------PONTEIROS-------------------------*/
    int *p = &i; // Declaração de um ponteiro p para o int i porque usa o "tipo" int*
    // O ponteiro (que é p) armazena o endereço da memória onde está o valor da variável, não o próprio valor dela, porque usa o &
    // Porém o ponteiro p armazena também um *p que é o valor da variável ao qual p aponta

    printf("\nValor de p = %ld\n", p);        // Printa o endereço de memória da variável que p aponta (no debugger apareçe em hexadecimal)
    printf("Tamanho de p = %ld\n", sizeof(p)); // sizeof = 8 bytes = 64 bits -> tamanho da memoria para cada "bloco de dados"
    printf("Endereço de p = %ld\n", &p);      // O ponteiro também tem o seu endereço na memória

    int k = 1953;
    *p = k; // Coloca o valor de k na variável que o ponteiro p aponta (no caso o i) e não no ponteiro p em si

    printf("\nValor de i = %d\n", i); // Print do i modificado pelo *p = k

    printf("\nValor de k = %d\n", k);
    printf("Tamanho de k = %ld\n", sizeof(k));
    printf("Endereço de k = %ld\n", &k); // Endereço na memória de k, porque usa o &

    printf("\nValor de *p = %ld\n", *p); // O valor de *p mudou para o valor de k, antes *p tinha o valor de i
    printf("Endereço de p = %ld\n", &p); // O ponteiro também tem o seu endereço na memória e ele não mudou
}