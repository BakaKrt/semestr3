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
    

    //ЗАДАНИЕ 2
    auto a = BAMBAM;


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

    //cout << *pint << " " << *pfloat << " " << *pdouble << " " << *pchar << " " << WCH(*pwchar_t) << " " << bool(*pbool) << endl;

    //ЗАДАНИЕ 5
    int in[6][5];
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 5; x++) {
            in[y][x] = (y*x)%4 + 3*(y-x) + (x%6+y/2)*(x/2-1) ;
        }
    }
    print_mas(in);
    zadanie_5(in); cout << endl;
    print_mas(in);
}
