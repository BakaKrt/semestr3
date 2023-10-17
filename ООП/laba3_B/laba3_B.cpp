#include <iostream>y
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

void fill_rand(vector<vector<int>> &vec) {
    srand(time(nullptr));
    for (auto& y : vec) {
        for (auto& x : y) {
            x = rand() % 20;
        }
    }
}

void print_vector(vector<vector<int>>& vec) {
    for (auto& x : vec) {
        for (auto& y : x) {
            cout << y << "\t";
        }
        cout << endl;
    }
}

void func(vector<vector<int>>& vec) {
    vector<int> s = vec[0]; short vs = vec.size(), vss = vec[0].size();
    vector<int> buf(2);
    buf[0] = vec[0][vec.size() - 2];
    buf[1] = vec[vec.size() - 1][0];

    for (int i = 0, ri = vs - 2 - i; i < vs - 1, ri > 0; i++, ri--) {
        vec[0][ri] = vec[0][ri - 1];
        vec[vs - 1][i] = vec[vs - 1][i + 1];
    }
    for (int j = 0, rj = vss - j; j < vss, rj > 0; j++, rj--) {
        vec[rj][vss - 1] = vec[rj - 1][vss - 1];
        vec[j][0] = vec[j + 1][0];
    }
    vec[1][vss - 1] = buf[0];
    vec[vs - 2][0] = buf[1];
    }



int main()
{
    setlocale(0, "");
    vector<vector<int>> vec(6, {0,0,0,0,0});
    
    fill_rand(vec);
    printf("Исходная случайная матрица 6*5:\n");
    print_vector(vec);
    cout << endl;
    int kol;
    cout << "Введите количество перемещений: ";
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        func(vec);
    }
    cout << endl;
    print_vector(vec);
}
