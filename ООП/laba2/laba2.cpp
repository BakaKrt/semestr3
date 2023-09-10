#include <iostream>
#include <string>;

using namespace std;

int main()
{
    setlocale(0, "");
    double step = 0.01; double acc = 0.01;
    int xmin = -1; int xmax = 1;
    cout << "Введите шаг step/1000: ";
    string in;
    getline(cin, in);
    if (in != "") {
        step = stoi(in)/1000;
    }
    else printf("Используется значение по умолчанию = %f\n", step);

    cout << "Введите точность accuracy/1000: ";
    getline(cin, in);
    if (in != "") {
        acc = stoi(in)/1000;
    }
    else printf("Используется значение по умолчанию = %f\n", acc);

    printf("%f %f\n", step, acc);

    double res = 0;
    for (double x = xmin, n = 1; x < xmax; x += step, n++) {
        res += (pow(x,n)/n);
        cout << res << endl;
    }
    printf("Результат: %f", -res);

}
