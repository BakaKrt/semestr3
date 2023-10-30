#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <iomanip>

using namespace std;

void get_random_vector(vector<vector<pair<int,int>>> &a) {
    srand(time(nullptr));
    for (auto &x : a) {
        for (auto &y : x) {
            y.first = rand() % 100;
        }
    }
}

void print_vector(vector<vector<pair<int,int>>> &a) {
    for (auto &x : a) {
        for (auto &y : x) {
            if (y.second) {
                cout << "\x1b[38;5;196m" << y.first << "\x1b[38;5;255m\t";
            }
            else
                cout << y.first << "\t";
        }
        cout << endl << endl;
    }
}

int len_of_path(vector<vector<pair<int,int>>>& in) {
    int cur_x = 0, cur_y = 0, in_size = in.size()-1;
    int sum = in[cur_y][cur_x].first;
    vector<int> path = { in[cur_y][cur_x].first };
    in[cur_y][cur_x].second = 1;
    while (cur_x != in_size || cur_y != in_size) {
        while (cur_y == in_size && cur_x != in_size) {
            in[cur_y][cur_x + 1].second = 1;
            sum += in[cur_y][cur_x + 1].first;
            path.push_back(in[cur_y][cur_x + 1].first);
            cur_x++;
        }
        while (cur_x == in_size && cur_y != in_size) {
            in[cur_y + 1][cur_x].second = 1;
            sum += in[cur_y + 1][cur_x].first;
            path.push_back(in[cur_y + 1][cur_x].first);
            cur_y++;
        }
        if (cur_x == in_size && cur_y == in_size)
            break;
        if (in[cur_y][cur_x + 1] < in[cur_y + 1][cur_x]) {
            in[cur_y][cur_x + 1].second = 1;
            sum += in[cur_y][cur_x + 1].first;
            path.push_back(in[cur_y][cur_x + 1].first);
            cur_x++;
        }
        else {
            in[cur_y + 1][cur_x].second = 1;
            sum += in[cur_y+1][cur_x].first;
            path.push_back(in[cur_y + 1][cur_x].first);
            cur_y++;
        }
    }
    print_vector(in);
    printf("Путь: ");
    for (const auto& p : path) {
        if (p != path.back())
            cout << p << "->";
        else
            cout << p;
    } cout << endl;
    return sum;
}

int main() {
    setlocale(0, "");
    vector<vector<pair<int,int>>> pole(10, { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}});
    get_random_vector(pole);
    printf("Ответ: %d", len_of_path(pole));
    //print_vector(pole);
}
