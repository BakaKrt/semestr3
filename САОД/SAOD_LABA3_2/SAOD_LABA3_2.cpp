#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

int get_gcd(int x1, int x2)
{
    if (!x2) return x1;
    return get_gcd(x2, x1 % x2);
}

int main(int argc, char** argv)
{
    unsigned found = 0;
    int N = 9;
    for (int den = 2; den != N + 1; den++) // 1 < знаменатель < N + 1
        for (int nom = 1; nom != den; nom++) // 0 < числитель < знаменатель 
            if (get_gcd(nom, den) == 1) // НОД
                printf("%4u.  %4d / %d\n", ++found, nom, den);

    return 0;
}