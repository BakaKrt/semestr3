#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

ld fx(ld x) {
    return x * x;
}

void check_valid(int &n) {
    if (n % 2 == 1)
        n = n + 1;
}

ld func_str(int n, ld a, ld b) {
    check_valid(n);
    vector<ld> xi; ld h = (b - a) / n;
    for (a = 0; a <= b; a += h) {
        xi.push_back(a);
    }

    ld Str = 0, sumSTR = 0;
    for (int i = 0; i <= n - 1; i++) {
        Str += (h * (fx(xi[i]) + fx(xi[i + 1])) / 2);
    }
    return Str;
}

ld func_spr(int n, ld a, ld b) {
    check_valid(n);
    vector<ld> xi; ld h = (b - a) / n;
    for (a = 0; a <= b; a += h) {
        xi.push_back(a);
    }
    ld Spr = 0;
    for (int j = 1; j <= n; j++) {
        Spr += fx(xi[j - 1] + h / 2) * h;
    }
    return Spr;
}

ld func_ssimpson(int n, ld a, ld b) {
    check_valid(n);
    vector<ld> xi; ld h = (b - a) / n;
    for (a = 0; a <= b; a += h) {
        xi.push_back(a);
    }

    ld temp_sum_0 = 0, temp_sum_1 = 0;
    for (int i = 1; i < n; i += 2) {
        temp_sum_0 += fx(xi[i]);
    }
    for (int j = 2; j < n - 1; j += 2) {
        temp_sum_1 += fx(xi[j]);
    }

    return (h / 3) * (fx(xi.front()) + fx(xi.back()) + 4 * (temp_sum_0)+2 * (temp_sum_1));
}

int main()
{
    setlocale(0, "");
    int n = 10;
    ld a = 0, b = 1, h = (b - a)/n, EPS = pow(10,-4);
    //Формула f(x) = x^2
    vector<ld> xi;
    for (ld i = a; i < b; i += h) {
        xi.push_back(i);
    }

    cout << func_str(n, a ,b) << endl;
    cout << func_spr(n, a, b) << endl;
    cout << func_ssimpson(n, a, b) << endl;

    
    for (int i = 4; ; i *= 2) {
        ld runge = abs(func_spr(i, a, b) - func_spr(i / 2, a, b)) / (pow(2, 2) - 1);
        cout << runge << endl;
        if (runge < EPS) {
            cout << "Для метода прямоугольников достаточно " << i << " итераций\n";
            cout << "Конечный результат по методу прямоугольников: " << func_spr(i,a,b) << endl;
            break;
        }
    }


    /*
    ld Str = 0, sumSTR=0;
    for (int i = 1; i <= n; i++) {
        Str = h * (fx(xi[i-1]) + fx(xi[i]) )/2;
        sumSTR += Str;
    } cout << sumSTR << endl;

    ld Spr = 0, sumSPR = 0;
    for (int i = 1; i <= n; i++) {
        Spr = fx(xi[i - 1] + h / 2) * h;
        sumSPR += Spr;
    } cout << sumSTR << endl;

    ld Ssimp = 0, sumSIMP = 0;
    ld temp_sum_0 = 0, temp_sum_1 = 0;
    for (int i = 1; i < n; i += 2) {
        temp_sum_0 += fx(xi[i]);
    }

    for (int j = 2; j < n - 1; j += 2) {
        temp_sum_1 += fx(xi[j]);
    }

    Ssimp = (h / 3) * (fx(xi.front())+fx(xi.back())+4*(temp_sum_0) + 2 * (temp_sum_1));
    cout << Ssimp;
    */
    
    ld runge = 0; int i_res = 0;
    for (int i = 2; i < 100000; i *= 2) {
        runge = abs(func_spr(i, a ,b) - func_spr(i * 2, a, b)) / (pow(2, 2) - 1);
        if (runge < EPS) {
            break;
        }
        //i *= 2;
        i_res = 2*i;
    }
    cout << endl;
    cout << i_res;
    
}
