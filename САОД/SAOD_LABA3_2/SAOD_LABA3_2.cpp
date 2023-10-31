#include <iostream>

int get_gcd(int x1, int x2)
{
    if (!x2) return x1;
    return get_gcd(x2, x1 % x2);
}

int main(int argc, char** argv)
{
    unsigned found = 0;
    int N = 9;
    for (int den = 2; den != N + 1; den++)
        for (int nom = 1; nom != den; nom++)
            if (get_gcd(nom, den) == 1) 
                printf("%4u.  %4d / %d\n", ++found, nom, den);

    return 0;
}