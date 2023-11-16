#include <iostream>
#include <iomanip>
using namespace std;

double factorial(double f) {
    double res = 1;
    for (int i = 1; i <= f; i++) {
        res *= i;
    }
    return res;
}

void zadanie_1(long double x1, long double x2, long double eps) {
    long double dx = 0.05;
    cout << left << setw(25) << "    Значение x" << setw(24) << "Прибл-ое зн-ие" << setw(25) << "Настоящее зн-ие" << setw(25) << "Кол-во эл-тов\n";
    for (double x = x1; x <= x2; x += dx) {
        double calc = 0;
        double result = 0;
        int n = 0;
        do {
            calc += result;
            result = pow(-1, n) * ((pow(x, 2 * n) / (factorial(2 * n + 1))));
            n++;
        } while (fabs(result) >= eps);
        if (x == x1) cout << "\n";
        cout << fixed << "     " << left << setw(23) << x << setw(24) << calc << setw(28) << sin(x) / x << setw(25) << n << endl;
    }
}

void zadanie_2(void(*ptr_zad_2)(long double, long double, long double), long double x1, long double x2, long double eps) {
    ptr_zad_2(x1,x2,eps);
}

void zadanie_3_print(double mas[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        printf("%2.1f ", mas[i]);
    }
}

void zadanie_3_print(int mas[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        printf("%2.1d ", mas[i]);
    }
}


int zadanie_3_0(double mas[], const int SIZE, double A, double B) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        if (mas[i] > A && mas[i] < B) k++;
    }
    return k;
}

int zadanie_3_0(int mas[], const int SIZE, int A, int B) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        if (mas[i] > A && mas[i] < B) k++;
    }
    return k;
}

double zadanie_3_1(double mas[], const int SIZE) {
    double sum = 0, max = 0;
    for (int i = 0; i < SIZE; i++) {
        if (mas[i] > max) {
            max = mas[i];
            sum = 0;
        }
        else sum += mas[i];
    }
    return sum;
}

int zadanie_3_1(int mas[], const int SIZE) {
    int sum = 0, max = 0;
    for (int i = 0; i < SIZE; i++) {
        if (mas[i] > max) {
            max = mas[i];
            sum = 0;
        }
        else sum += mas[i];
    }
    return sum;
}

double* zadanie_3_2(double mas[], const int SIZE) {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE - j - 1; i++) {
            if (fabs(mas[i]) < fabs(mas[i + 1])) {
                double zn = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = zn;
            }
        }
    }
    zadanie_3_print(mas, SIZE);
    return mas;
}

int* zadanie_3_2(int mas[], const int SIZE) {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE - j - 1; i++) {
            if (fabs(mas[i]) < fabs(mas[i + 1])) {
                int zn = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = zn;
            }
        }
    }
    zadanie_3_print(mas, SIZE);
    return mas;
}


int zadanie_4(string a) {
    int k = 0;
    for (const auto& b : a) {
        if (b > 0 || b < 9) {
            k++;
        }
    }
    return k;
}

void zadanie_5_print(int in[6][5]) {
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            cout << setw(2) << in[y][x] << setw(4) << " ";
        }
        cout << endl << setw(1);
    }
}

void zadanie_5(int in[6][5], int p) {
    for (int i = 0; i < p; i++) {
        int a1 = in[0][4];  int a2 = in[5][0];
        for (int x = 0, rx = 5 - x - 1; x < 5, rx > 0; x++, rx--) {
            in[5][x] = in[5][x + 1];
            in[0][rx] = in[0][rx - 1];
        }
        for (int y = 0, ry = 6 - y - 1; y < 6, ry>0; y++, ry--) {
            in[y][0] = in[y + 1][0];
            in[ry][4] = in[ry - 1][4];
        }
        in[1][4] = a1;  in[4][0] = a2;
    }
    printf("Перемещение на %d вправо вниз\n", p);
}

struct zadanie_6_struct {
    int ERR_NUMBER;
    string ERR_INFO;
};

void zadanie_6(zadanie_6_struct s) {
    printf("Поля структуры: %d, %s", s.ERR_NUMBER, s.ERR_INFO.c_str());
}

int *zadanie_7(int a[], int size) {
    if (size <= 1) {
        return a;
    }
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
    zadanie_7(a, size - 1);
}

void zadanie_7_print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d \t", a[i]);
    }
}

template <class type>
void zadanie_9(type in[6][5], int p) {
    for (int i = 0; i < p; i++) {
        type a1 = in[0][4];  type a2 = in[5][0];
        for (int x = 0, rx = 5 - x - 1; x < 5, rx > 0; x++, rx--) {
            in[5][x] = in[5][x + 1];
            in[0][rx] = in[0][rx - 1];
        }
        for (int y = 0, ry = 6 - y - 1; y < 6, ry>0; y++, ry--) {
            in[y][0] = in[y + 1][0];
            in[ry][4] = in[ry - 1][4];
        }
        in[1][4] = a1;  in[4][0] = a2;
    }
    printf("Перемещение на %d вправо вниз\n", p);
}

template <class type>
void zadanie_9_print(type in[6][5]) {
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            cout << setprecision(2) <<setw(5) << in[y][x] << setw(5) << " ";
        }
        cout << endl << setw(0);
    }
}

int main()
{
    setlocale(0, "");
    printf("###### ЗАДАНИЕ 1 ######\n");
    printf("Передача в функцию параметров стандартных типов:\n");
    zadanie_1(-1, 0, 0.05);

    printf("\n###### ЗАДАНИЕ 2 ######\n");
    zadanie_2(zadanie_1, -0.5, 0, 0.1);

    printf("\n###### ЗАДАНИЕ 3 ######\n");
    double mas[100] = {}; const int SIZE = 100;
    for (double x = -40, i = 0; i < SIZE / 2; x += 1.5, i++) {
        mas[int(i)] = x;
    }
    for (double x = 50, i = SIZE / 2; i < SIZE; x -= 1.5, i++) {
        mas[int(i)] = x;
    }
    zadanie_3_print(mas, SIZE); cout << endl;
    printf("Количество элементов, лежащих в диапазоне от -1 до 45: %d\n", zadanie_3_0(mas, SIZE, -1, 45));
    printf("Сумма элементов массива, лежащих после максимального элемента: %f\n", zadanie_3_1(mas, SIZE));
    printf("Упорядоченные элементы массива по убыванию модулей элементов: ");
    zadanie_3_2(mas, SIZE);

    printf("\n\n###### ЗАДАНИЕ 4 ######\n");
    string zd_4 = "43t6yu h8io99 u9ijmu9ij0` niefhlbr132";
    printf("Исходная строка: %s\n", zd_4.c_str());
    printf("Количество цифр в ней: %d\n", zadanie_4(zd_4));

    printf("\n\n###### ЗАДАНИЕ 5 ######\n");
    int in[6][5] = {};
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            in[y][x] = (y * x) % 4 + 3 * (y - x) + (x % 6 + y / 2) * (x / 2 - 1);
        }
    }
    int perem = 1;
    zadanie_5(in, perem);
    zadanie_5_print(in);

    printf("\n\n###### ЗАДАНИЕ 6 ######\n");
    zadanie_6_struct structure_0{-1, "aaaa"};
    zadanie_6(structure_0);

    printf("\n\n###### ЗАДАНИЕ 7 ######\n");
    const int SIZE_0 = SIZE / 10;
    int massiv[SIZE_0] = {};
    for (int i = 0, k = 10; i < SIZE_0; i++, k--) {
        massiv[i] = k;
    }
    printf("Массив до упорядочивания: \n"); zadanie_7_print(massiv, SIZE_0);
    printf("\nУпорядоченный массив по возрастанию с помощью рекурсии:\n");
    zadanie_7_print(zadanie_7(massiv, SIZE_0), SIZE_0);

    printf("\n\n###### ЗАДАНИЕ 8 ######\n");
    int mas_[100] = {}; const int SIZE_1 = 100;
    for (int x = -40, i = 0; i < SIZE_1 / 2; x += 1, i++) {
        mas_[i] = x;
    }
    for (int x = 50, i = SIZE / 2; i < SIZE_1; x -= 1, i++) {
        mas_[i] = x;
    }
    zadanie_3_print(mas_, SIZE_1);
    printf("Количество элементов, лежащих в диапазоне от -1 до 45: %d\n", zadanie_3_0(mas_, SIZE_1, -45, -30));
    printf("Сумма элементов массива, лежащих после максимального элемента: %d\n", zadanie_3_1(mas_, SIZE_1));
    printf("Упорядоченные элементы массива по убыванию модулей элементов: ");
    zadanie_3_2(mas_, SIZE_1);

    printf("\n\n###### ЗАДАНИЕ 9 ######\n");

    float out[6][5] = {};
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            out[y][x] = (y * x) % 4 + 3 * (y - x) + (x % 6 + y / 2) * (x / 2 - 1);
        }
    }
    zadanie_9_print(out);
    zadanie_9(out, 2);
    zadanie_9_print(out);
}
