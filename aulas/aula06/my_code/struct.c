#include <stdbool.h>
#include <stdio.h>

// Início de Orientação a objetos
typedef struct
{
    int number;
    double balance;
    bool special;
} Account; /* Parece com uma classe de Java */

void printaccount(Account acc)
{
    printf("number = %d\n", acc.number);
    printf("balance = %.2lf\n", acc.balance);
    printf("special = %c\n", acc.special?'Y' : 'N');
}

int main()
{
    Account acc;

    acc.number = 123;
    acc.balance = 1412.00;
    acc.special = false;
    
    printaccount(acc);

    printf("\n");
    printf("sizeof int %ld\n", sizeof(acc.number));
    printf("sizeof double %ld\n", sizeof(acc.balance));
    printf("sizeof bool %ld\n", sizeof(acc.special));
    printf("sizeof Account %ld\n", sizeof(acc)); // c struct padding

    return 0;
}