#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

enum bimbim {BIMBIM = 0, BAMBAM = -1};
typedef bimbim *bim;
typedef wchar_t WCH;

struct primer1 {
    int pole1 = 10;
    bool x = false;
    WCH abc = 'abc';
} pole;

void print_mas(int in[6][5]) {
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            cout << setw(2) << in[y][x] << setw(4) << " ";
        }
        cout << endl << setw(1);
    }
}

void zadanie_5(int in[6][5]) { 
    int a1 = in[0][4];  int a2 = in[5][0];
    for (int x = 0, rx = 5 - x - 1; x < 5, rx > 0; x++, rx--) {
        in[5][x]  = in[5][x + 1];
        in[0][rx] = in[0][rx - 1];
    }
    for (int y = 0, ry = 6 - y - 1; y < 6, ry>0; y++, ry--) {
        in[y][0] = in[y+1][0];
        in[ry][4] = in[ry-1][4];
    }
    in[1][4] = a1;  in[4][0] = a2;
}

int** create_mas(int y, int x) {
    int** mas;
    mas = new int* [y];
    for (int i = 0; i < x; i++) {
        mas[i] = new int[x];
    }
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 6; x++) {
            mas[y][x] = (y * x) % 4 + 3 * (y - x) + (x % 6 + y / 2) * (x / 2 - 1);
        }
    }
    return mas;
}

void zadanie6() {
    int** in = create_mas(5, 6);
    int a1 = in[0][5];  int a2 = in[4][0];

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 6; x++) {
            cout << setw(3) << in[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int x = 0, rx = 6 - x - 1; x < 6, rx > 0; x++, rx--) {
        in[4][x] = in[4][x + 1];
        in[0][rx] = in[0][rx - 1];
    }
    for (int y = 0, ry = 5 - y - 1; y < 5, ry > 0; y++, ry--) {
        in[y][0] = in[y + 1][0];
        in[ry][5] = in[ry - 1][5];
    }

    in[1][5] = a1;  in[3][0] = a2;

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 6; x++) {
            cout << setw(3) << in[y][x] << " ";
        }
        cout << endl;
        delete[] in[y];
    }
}

void zadanie7(double mas[10]) {
    double A = -3, B = 4; int kol = 0;
    cout << "Введите диапазон от А до В: ";
    //cin >> A >> B;
    for (int i = 0; i < 10; i++) {
        if (mas[i] > A && mas[i] < B)
            kol++;
    }
    printf("Количество элементов массива лежащих в диапазоне от %f до %f: %d\n", A, B, kol);
}

double zadanie8_0(double mas[10]) {
    double sum = 0, max = 0;
    for (int i = 0; i < 10;i++) {
        if (mas[i] > max) {
            max = mas[i];
            sum = 0;
        }
        else sum += mas[i];
    }
    
    return sum;
}

typedef double(*ZD8)(double[]);

void zadanie8_1(ZD8 resh, double mas[10]) {
    cout << "Задание 8 через указатель на функцию: ";
    printf("Сумма элементов массива, лежащих после максимального элемента: %f\n", resh(mas));
}

int main()
{
    setlocale(0, "");
    //ЗАДАНИЕ 1
    int* pint = new int;            *pint = 15;
    float* pfloat = new float;      *pfloat = 3.14;
    double* pdouble = new double;   *pdouble = 18095.513951860;
    char* pchar = new char;         *pchar = 'a';
    WCH* pwchar_t =  new WCH;       *pwchar_t = 'abcd';
    bool* pbool = new bool;         *pbool = false;

    cout << "Задание 1: \n";
    cout << *pint << " " << *pfloat << " " << *pdouble << " " << *pchar << " " << *pwchar_t << " " << *pbool << endl;

    //ЗАДАНИЕ 2
    auto a = BAMBAM;
    cout << a << " " << &a << endl;


    //ЗАДАНИЕ 3
    primer1* pr_ = new primer1;
    *pr_ = pole;
    cout << "Значения полей в pole:" <<
        pr_->pole1 << " " << pr_->x << " " << pr_->abc << endl;

    //ЗАДАНИЕ 4
    *pint = -10;
    *pfloat = int(*pint);
    *pdouble = 2 * (*pfloat) + 0.19412;
    *pchar = 'b';
    *pwchar_t = 'dcba';
    *pbool++;

    cout << "\nЗадание 4:\n";
    cout << *pint << " " << *pfloat << " " << *pdouble << " " << *pchar << " " << WCH(*pwchar_t) << " " << bool(*pbool) << endl;

    //ЗАДАНИЕ 5
    int in[6][5];
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            in[y][x] = (y*x)%4 + 3*(y-x) + (x%6+y/2)*(x/2-1) ;
        }
    }
    print_mas(in);
    cout << "Введите количество циклов сдвига: ";
    int k = 1;
    cin >> k;
    for (int i = 0; i < k; i++)
        zadanie_5(in);
    cout << endl;
    print_mas(in);

    //ЗАДАНИЕ 6
    zadanie6();

    //ЗАДАНИЕ 7
    double* zad7 = new double[10];
    cout << "Элементы одномерного массива задания 7: ";
    for (int i = 0; i < 10; i++) {
        zad7[i] = 5 - i + 1;
        cout << zad7[i] << " ";
    }
    cout << endl;
    zadanie7(zad7);
    
    //ЗАДАНИЕ 8
    zadanie8_1(zadanie8_0, zad7);
    delete[] zad7;

    //ЗАДАНИЕ 9

    primer1 zd9;
    primer1* mas9;
    mas9 = &zd9;
    cout << "\nЗначения полей через указатель: ";
    cout << mas9->abc << " " << mas9->pole1 << " " << mas9->x << endl;
    void* void_ptr;
    cout << "Значения полей через void_ptr: ";  void_ptr = mas9;
    cout << static_cast<primer1*> (void_ptr)->abc << " " << static_cast<primer1*> (void_ptr)->pole1 << " " << static_cast<primer1*> (void_ptr)->x;
}
