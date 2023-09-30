#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double factorial(double f) {
    double res = 1;
    for (int i = 1; i <= f; i++) {
        res *= i;
    }
    return res;
}

int main() {

    setlocale(0, "");
    long double x1, x2, dx;
    double eps = (1e-4);

    cin >> x1 >> x2 >> dx;

    cout << left << setw(25) << "    Значение x" << setw(24) << "Прибл-ое зн-ие" << setw(25) << "Настоящее зн-ие" << setw(25) << "Кол-во эл-тов\n";

    for (double x = x1; x <= x2; x += dx) {

        long double calc = 0;
        long double result = 0;
        int n = 0; bool skip = false;

        do {
            calc += result;
            result = pow(-1,n)*((pow(x,2*n)/(factorial(2*n + 1))));
            n++;
        } while (fabs(result) >= eps);

        if (x == x1) cout << "\n";
        cout << fixed << "     " << left << setw(23) << x << setw(24) << calc << setw(28) << sin(x)/x << setw(25) << n << endl;
    }
}


