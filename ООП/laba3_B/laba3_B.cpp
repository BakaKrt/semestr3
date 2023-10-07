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
    vector<int> s = vec[0]; int buff = s[s.size()-1];
    for (int x = 0; x < vec.size(); x++) {
        if (x == 0) {
            for (int y = vec[x].size() - 1; y > 0; y--) {
                vec[x][y] = vec[x][y - 1];
            }
        }
    }
    s = vec[vec.size() - 1];
    int buff_ = s[s.size() - 1];
    for (int x = vec.size()-1; x > 1; x--) {
        vec[x][vec[x].size() - 1] = vec[x-1][vec[x].size() - 1];
    }
    vec[vec[vec.size()-1].size() - vec.size() + 2][vec[vec.size()-1].size() - 1] = buff;
    
    buff = buff_;

    print_vector(vec);
    printf("Это buff: %d\n", buff);
    vec[vec[vec.size() - 1].size()-2][vec[vec.size() - 1].size()-1] = buff;

    s = vec[vec.size() - 1];
    buff = s[0];


    for (int x = vec.size()-1; x > 0; x--) {
        for (int y = 1; y < vec[x].size()-1; y++) {
            vec[x][y-1] = vec[x][y];
        }
        break;
    }
    vec[vec[vec.size() - 1].size()][vec[vec.size() - 1].size()-2] = buff;


    for (int x = 0; x < vec.size()-1; x++) {
        vec[x][0] = vec[x+1][0];
    }

    vec[vec[vec.size() - 1].size()-1][0] = buff;
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
