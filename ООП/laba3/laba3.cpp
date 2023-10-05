#include <iostream>
#include <iterator>
using namespace std;

int const SIZE = 100;

int main()
{   
    setlocale(0, "");
    double mas[SIZE] = {};
    for (double x = -40, i = 0; i < SIZE/2; x += 1.5, i++) {
        mas[int(i)] = x;
    }
    for (double x = 50, i = SIZE/2; i < SIZE; x -= 1.5, i++) {
        mas[int(i)] = x;
    }

    for (const auto& x : mas) {
        printf(" %.1f\n",x);
    }
    
    double A, B; int kol = 0;
    cout << "Введите диапазон от А до В: ";
    cin >> A >> B;
    for (const auto& x : mas) {
        if (x > A && x < B) kol++;
    }
    printf("Количество элементов массива лежащих в диапазоне от %f до %f: %d\n", A, B, kol);

    double sum = 0, max = 0;
    for (const auto& x : mas) {
        if (x > max) {
            max = x;
            sum = 0;
        }
        else sum += x;
    }
    printf("Сумма элементов массива, лежащих после максимального элемента: %f\n", sum);
    bool sorted = false;
    
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE - j -1; i++) {
            if (fabs(mas[i]) < fabs(mas[i + 1])) {
                double zn = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = zn;
            }
        }
    }

    //for (const auto& x : mas) {
    //    cout << x << endl;
    //}
}
