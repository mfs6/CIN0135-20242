#include <stdbool.h>
#include <math.h>
#include "prime.h"

bool is_prime(int a)
{
    if (a <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return 1;
}