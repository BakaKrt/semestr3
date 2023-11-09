#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;

void print_table(vector<ld>& q, vector<ld>& w, vector<ld>& e, vector<ld>& r, vector<ld>& t ) {
    cout << setw(9) << "x" << setw(12) << "y" << setw(13) << "dy1" << setw(12) << "dy2" << setw(12) << "dy3" << endl;
    for (int i = 0; i < q.size(); i++) {
        cout << fixed << setprecision(6) << setw(12) << q[i] << setw(12) << w[i] << setw(12) << e[i] << setw(12) << r[i] << setw(12) << t[i] << endl;
    }
}

int main()
{
    setlocale(0, "");
    vector<ld> x = { 0.15, 0.16, 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26 };
    vector<ld> y = { 4.4817, 4.9530, 5.4739, 6.0496, 6.6859, 7.3891, 8.1662, 9.0250, 9.9742, 11.0232, 12.1825, 13.4637 };
    vector<ld> dy1 (12,0), dy2(12,0), dy3(12,0);
    for (int i = 0, x = 0; i < y.size() - 1; i++, x++) {
        dy1[x] = y[i+1]-y[i];
    }
    for (int i = 0, x = 0; i < y.size() - 2; i++, x++) {
        dy2[x] = dy1[i+1] - dy1[i];
    }
    for (int i = 0, x = 0; i < y.size() - 3; i++, x++) {
        dy3[x] = dy2[i+1] - dy2[i];
    }

    print_table(x,y,dy1,dy2,dy3);

    cout << "Введите число: ";
    ld input = 1;
    cin >> input;
    ld niz_pr = x.front(), ver_pr = x.back();
    int kount = 0;
    
    if (input < x.front()) {
        ver_pr = x.front();
    }
    else if (input > x.back()) {
        niz_pr = x.back();
        kount = x.size() - 1;
    }
    else {
        for (const auto& a : x) {
            if (input > a) {
                ver_pr = a;
                kount++;
            }
        }
        niz_pr = ver_pr + 0.01;
    }
    //cout << ver_pr << " " << niz_pr << " " << kount << endl;

    ld res_n = 0;
    if (input < x[0] + (x.back() - x.front()) / 2) {
        //cout << "Мы в верхней половине\n";
        ld q = (input-ver_pr) / 0.01;
        if (kount > 0) kount--;
        printf("\nq = (%1f - %f) / 0.01 = %f\n", input, ver_pr, q);
        printf("\nКак выглядит сумма: %f + (%1f * %f) + \n(%f * %+f * %f)/2 + (%f * %f * %f * %f)/6\n = ", y[kount], q, dy1[kount], q, q - 1, dy2[kount], q, q - 1, q - 2, dy3[kount]);
        res_n = y[kount] + q * (dy1[kount]) + dy2[kount] * (q * (q - 1)) / 2 + dy3[kount] * (q * (q - 1) * (q - 2)) / 6;
    }
    else {
        //cout << "Мы во второй половине\n";
        ld q = (input-niz_pr) / 0.01;
        printf("\nq = (%1f - %f) / 0.01 = %f\n", input, niz_pr, q);
        printf("\nКак выглядит сумма: %f + (%1f * %f) + \n(%f * %f * %f)/2 + (%f * %f * %f * %f)/6\n = ", y[kount], q, dy1[kount - 1], q, q+1, dy2[kount-2], q,q+1,q+2,dy3[kount-3]);
        res_n = y[kount] + q * (dy1[kount - 1]) + dy2[kount-2]*(q * (q + 1)) / 2 + dy3[kount-3]*(q * (q + 1) * (q + 2)) / 6;
    }

    cout << res_n;

    ld res_l = 0;
    for (int i = 0; i < x.size(); i++) {
        ld Pr = 1;
        for (int k = 0; k < x.size(); k++) {
            if (k != i) {
                Pr *= ((input - x[k]) / (x[i] - x[k]));
            }
        }
        res_l += Pr * y[i];
    }
    cout << "\nОтветы:\n\tпо Ньютону: " << "\x1b[38;5;196m\t" << res_n << "\x1b[38;5;255m\n\tпо Лагранжу: " << "\x1b[38;5;196m\t" << res_l<<"\x1b[38;5;255m";
    cout << "\n\tДельта методов: " << "\x1b[38;5;10m" << fabs(res_n - res_l) << "\x1b[38;5;255m";
}