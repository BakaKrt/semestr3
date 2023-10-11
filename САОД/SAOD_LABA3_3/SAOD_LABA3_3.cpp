#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <iomanip>

using namespace std;

void get_random_vector(vector<vector<int>> &a) {
    srand(time(nullptr));
    for (auto &x : a) {
        for (auto &y : x) {
            y = rand() % 100;
        }
    }
}

void print_vector(vector<vector<int>>& a) {
    for (auto &x : a) {
        for (auto &y : x) {
            cout << setw(3) << y << " ";
        }
        cout << endl;
    }
}

int len_of_path(vector<vector<int>>& in) {
    int cur_x = 0, cur_y = 0, in_size = in.size() - 1;
    int sum = in[cur_y][cur_x];
    vector<int> path = { in[cur_y][cur_x] };
    while (cur_x != in_size && cur_y != in_size) {
        if (in[cur_y][cur_x + 1] < in[cur_y + 1][cur_x]) {
            sum += in[cur_y][cur_x + 1];
            path.push_back(in[cur_y][cur_x + 1]);
            cur_x++;
        }
        else {
            sum += in[cur_y+1][cur_x];
            path.push_back(in[cur_y + 1][cur_x]);
            cur_y++;
        }
    }
    for (const auto& p : path) {
        cout << p << " ";
    } cout << endl;
    return sum;
}

int main() {
    setlocale(0, "");
    vector<vector<int>> pole(10, {0,0,0,0,0,0,0,0,0,0});
    get_random_vector(pole);
    print_vector(pole);
    printf("Ответ: %d", len_of_path(pole));
}
