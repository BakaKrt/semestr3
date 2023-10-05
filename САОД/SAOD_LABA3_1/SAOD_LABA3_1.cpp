#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 8; // Размер шахматной доски

typedef vector<pair<int, int>> pole;
pole hodi = { {1,-2},{-1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,-1},{-2,1} };
int VSE_HODI = 0;

pole rand_vec() {
    srand(time(nullptr));
    pole a, hodi_ = hodi;
    for (int i = 0; i < 8; i++) {
        a.push_back(hodi_[rand()%hodi_.size()]);
        auto it = std::remove(hodi_.begin(), hodi_.end(), a.back());
        hodi_.erase(it, hodi_.end());
    }
    return a;
}

int vec_sum(vector<vector<int>> &a) {
    int k = 0;
    for (const auto& a_ : a) {
        for (const auto& b_ : a_) {
            k += b_;
        }
    }
    return k;
}

void print_doska(vector<vector<int>> a, int pos_y = -10, int pos_x = -10, int prevY = -10, int prevX = -10) {
    int y = 0;
    for (const auto& a_ : a) {
        int x = 0;
        for (const auto& b_ : a_) {
            if (y == pos_y && x == pos_x) {
                cout << "\x1b[42m" << b_ << "\x1b[40m ";
            }
            else if (y == prevY && x == prevX) {
                cout << "\x1b[44m" << b_ << "\x1b[40m ";
            }
            else
                cout << b_ << " ";
            x++;
        }
        cout << endl;
        y++;
    }
    cout << vec_sum(a)<<endl;
}

void clear_doska(vector<vector<int>> &a, int pos_y=0, int pos_x=0) {
    int y = 0;
    for (auto& a_ : a) {
        int x = 0;
        for (auto& b : a_) {
            if (x == pos_x && y == pos_y) {
                b = 1;
            }
            else b = 0;
            x++;
        }
        y++;
    }
}

void print_path(vector<vector<pair<int,int>>> in) {
    for (const auto& a : in) {
        for (const auto& b : a) {
            printf("%d\t%d\n", b.first,b.second);
        }
        cout << endl;
    }
    cout << endl;
}

int path_exist(vector<vector<pair<int, int>>> &in, vector<pair<int,int>> &in_) {
    int k = 0;
    for (auto& a_ : in) {
        if (a_ == in_) {
            k++;
        }
    }
    if (k == 0)
        return 1;
    return 0;
}

int doska_resh(vector<vector<int>> &v, int &nachY, int &nachX, int &konY, int &konX) {
    int cant_go = 0; int TOTAL_ERRORS = 0; int in_vec_size = v.size();
    vector<pole> all_path; pole path; int err_l = in_vec_size * in_vec_size * 200;
    
    
    for (int y = nachY; y <= v.size();) {
        for (int x = nachX; x <= v[y].size();) {
            while (TOTAL_ERRORS < 100000) {
                for (const auto& a : rand_vec()) {
                    if ((y + a.first >= 0 && y + a.first < in_vec_size && x + a.second >= 0 && x + a.second < in_vec_size) && v[y + a.first][x + a.second] != 1) {
                        cant_go = 0;
                        //printf("до: \t %d %d\n", y,x);
                        y += a.first;
                        x += a.second;
                        //printf("после: \t %d %d\n", y, x);
                        v[y][x] = 1;
                        path.push_back(a);
                        //print_doska(v, y, x);
                        //printf("y%d x%d %d %d y_n%d x_n%d\n",y,x,a.first,a.second,nachY, nachY);
                        if (y == konY && x == konX) {
                            if (all_path.size() == 0) {
                                all_path.push_back(path);
                                print_doska(v, y, x, y-a.first,x-a.second);
                                printf("Размер path: %d\nколичество комбинаций: %d\n", path.size(), all_path.size());
                                path.clear();
                            }
                            else {
                                if (path_exist(all_path, path) == 1) {
                                    all_path.push_back(path);
                                    print_doska(v, y, x, y - a.first, x - a.second);
                                    printf("Размер path: %d\nколичество комбинаций: %d\n", path.size(),all_path.size());
                                    for (auto& a_ : path) {
                                        //printf("Путь: %d %d\n",a_.first, a_.second);
                                    }
                                    //cin.get();
                                    path.clear();
                                    TOTAL_ERRORS = 0;
                                    clear_doska(v, nachY, nachX);
                                    x = nachX; y = nachY;
                                }
                            }
                        }
                    }
                    else {
                        cant_go++;
                        if (cant_go > 17) {
                            path.clear();
                            clear_doska(v, nachY, nachX);
                            x = nachX; y = nachY;
                            cant_go = 0;
                            TOTAL_ERRORS++;
                            continue;
                        }
                    }
                }
                //cout << endl << all_path.size() << endl;
            }
            return all_path.size();
        }
    }
    cout << endl << all_path.size() << endl;
    return all_path.size();
}

int main() {
    setlocale(0, "");
    printf("Введите две пары чисел: {начY,начX} {конY,конX}: \n");
    int nachY, nachX, konY, konX;
    nachY = 3; nachX = 3; konY = 0; konX = 0;
    //cin >> nachY >> nachX >> konY >> konX; //не удалять

    
    vector<vector<int>> DOSKA(4, { 0,0,0,0 });
    DOSKA[nachY][nachX] = 1;
    DOSKA[konY][konX] = 2;

    print_doska(DOSKA);
    cout <<endl;

    printf("\nКоличество путей: %d",doska_resh(DOSKA, nachY, nachX, konY, konX));
}