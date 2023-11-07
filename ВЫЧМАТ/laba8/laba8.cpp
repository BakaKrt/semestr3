#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    float x[12] = { 0.15, 0.16, 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26 };
    float y[12] = { 4.4817, 4.9530, 5.4739, 6.0496, 6.6859, 7.3891, 8.1662, 9.0250, 9.9742, 11.0232, 12.1825, 13.4637 };
    float dy1[12]{};
    float dy2[12]{};
    float dy3[12]{};
    float x1;
    for (int i = 0; i < 11; i++) {
        dy1[i] = y[i + 1] - y[i];

    }
    for (int i = 0; i < 10; i++) {
        dy2[i] = dy1[i + 1] - dy1[i];

    }
    for (int i = 0; i < 9; i++) {
        dy3[i] = dy2[i + 1] - dy2[i];

    }
    cout << setw(12) << "x" << setw(12) << "y" << setw(12) << "dy1" << setw(12) << "dy2" << setw(12) << "dy3" << endl;
    for (int i = 0; i < 12; i++) {
        cout << fixed << setprecision(6) << setw(12) << x[i] << setw(12) << y[i] << setw(12) << dy1[i] << setw(12) << dy2[i] << setw(12) << dy3[i] << endl;
    }
    cout << "Enter x: " << endl;
    cin >> x1;
    int k = 0;
    float q;
    float yx;

    for (int i = 0; i < 13; i++) {
        if (x1 > x[i]) {
            k++;
        }

    }
    if (k / 6 == 0) {
        q = (x1 - x[0]) / 0.01;
        cout << "yx = y[0] + dy1[0] * q + (q * (q - 1) * dy2[0]) / 2 + (q * (q - 1) * (q - 2) * dy3[0]) / 6" << endl;
        yx = y[0] + dy1[0] * q + (q * (q - 1) * dy2[0]) / 2 + (q * (q - 1) * (q - 2) * dy3[0]) / 6;
    }
    else {
        q = (x1 - x[11]) / 0.01;
        cout << "yx = y[11] + q* dy1[10] + (q * (q + 1) * dy2[9]) / 2 + (q * (q + 1) * (q + 2) * dy3[8]) / 6" << endl;
        yx = y[11] + q * dy1[10] + (q * (q + 1) * dy2[9]) / 2 + (q * (q + 1) * (q + 2) * dy3[8]) / 6;
    }

    cout << "yx = " << yx << endl;
}