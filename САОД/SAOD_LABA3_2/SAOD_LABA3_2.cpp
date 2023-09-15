#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

/* Найти все простые несократимые дроби, заключенные между 0 и 1, знаменатели
   которых не превышают 7 (дробь задается 2 натуральными числами - числителем
   и знаменателем) */

#define N 9 // максимальное значение знаменателя

   // поиск НОДа
int get_gcd(int x1, int x2)
{
    if (!x2) return x1;
    return get_gcd(x2, x1 % x2);
}

int main(int argc, char** argv)
{
    unsigned found = 0;

    for (int den = 2; den != N + 1; den++) // 1 < знаменатель < N + 1
        for (int nom = 1; nom != den; nom++) // 0 < числитель < знаменатель 
            if (get_gcd(nom, den) == 1) // НОД
                printf("%4u.  %4d / %d\n", ++found, nom, den);

    printf("\n >> press any key to exit...");; // ожидание клавиши

    return 0;
}