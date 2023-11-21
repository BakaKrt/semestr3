#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


mutex mtx;
bool f = false;

long long x_3(long long x) {
    return x * x * x;
}

void th1(long long x) {
    for (long long i = 1; i <= x / 2; i++) {
        for (long long j = 1; j <= x / 2; j++) {
            if (x_3(i) + x_3(j) == x) {
                if (f == true) return;
                f = true;
                cout << "YES\n";
                return;
            }
        }
    }
}

void th2(long long x) {
    for (long long i = x/2; i < x; i++) {
        if (i == 0) continue;
        for (long long j = x/2; j < x; j++) {
            if (j == 0) continue;
            if (x_3(i) + x_3(j) == x) {
                if (f == true) return;
                f = true;
                cout << "YES\n";
                return;
            }
        }
    }
}

int main()
{
    long long x;
    int kolvo = 0;
    cin >> kolvo;
    for (int a = 0; a < kolvo; a++) {
        cin >> x;
        thread p1(th1, x);
        thread p2(th2, x);
        p1.join();
        p2.join();
        if (!f) {
            cout << "No\n";
            f = false;
        }
        f = false;
    }
}
