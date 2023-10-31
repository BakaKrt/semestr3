#include <iostream>
#include <vector>

using namespace std;

enum bimbim {BIMBIM = 0, BAMBAM = -1};
typedef bimbim *bim;
typedef wchar_t WCH;

struct primer1 {
    int pole1 = 10;
    bool x = false;
    WCH abc = 'abc';
} pole;

int main()
{
    //ЗАДАНИЕ 1
    int* pint;
    & pint = 15;
    float* pfloat; *pfloat = 3.14;
    double* pdouble; *pdouble = 18095.513951860;
    char* pchar; *pchar = 'a';
    WCH* pwchar_t; *pwchar_t = L'abcd';
    bool* pbool; *pbool = false;
    

    //ЗАДАНИЕ 2
    auto a = BAMBAM;
    cout << a;

    primer1* pr_;
    printf("Значения всех полей структуры: %d\t%d\t%s", pr_->pole1, pr_->x, pr_->abc);
    cout << pr_->abc;
}
