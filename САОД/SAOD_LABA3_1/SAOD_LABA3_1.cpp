#include <iostream>
#include <vector>
#include <algorithm>

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
    for (const auto& a_ : a) {
        //cout << a_.first << " " << a_.second << endl;
    }
    //cin.get();
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

void print_doska(vector<vector<int>> a, int pos_y = -1, int pos_x = -1) {
    int y = 0;
    for (const auto& a_ : a) {
        int x = 0;
        for (const auto& b_ : a_) {
            if (y == pos_y && x == pos_x) {
                cout << "\x1b[42m" << b_ << "\x1b[40m ";
            }
            else cout << b_ << " ";
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

void doska_resh(vector<vector<int>> v, int nachY, int nachX, int konY, int konX) {
    int cant_go = 0; int TOTAL_ERRORS = 0;
    vector<pole> all_path; pole path;
    for (int y = nachY; y < v.size(); y++) {
        for (int x = nachX; x < v[y].size(); x++) {
            while (TOTAL_ERRORS < 100000) {
                for (const auto& a : rand_vec()) {
                    if (y + a.first >= 0 && x + a.second >= 0 && y + a.first < 8 && x + a.second < 8 && v[y + a.first][x + a.second] != 1) {
                        cant_go = 0;
                        y += a.first; x += a.second;
                        v[y][x] = 1; VSE_HODI++;
                        path.push_back(a);
                        if (y == konY && x == konX) {
                            if (all_path.size() == 0) {
                                all_path.push_back(path);
                                path.clear();
                            }
                            else {
                                if (path_exist(all_path, path) == 1) {
                                    all_path.push_back(path);
                                    print_doska(v, y, x);
                                    printf("Размер path: %d\n", path.size());
                                    path.clear();
                                    TOTAL_ERRORS = 0;
                                }
                            }
                        }
                    }
                    else {
                        cant_go++;
                        if (cant_go > 17) {
                            path.clear();
                            clear_doska(v, nachY, nachX);
                            cant_go = 0;
                            TOTAL_ERRORS++;
                            break;
                        }
                    }
                }
            }
            
        }
    }
    cout << endl << all_path.size() << endl;
}

int main() {
    //pole hodi = { {-2,1},{-2,-1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2} };
    setlocale(0, "");
    printf("Введите две пары чисел: {начY,начX} {конY,конX}: \n");
    int nachY, nachX, konY, konX;
    nachY = 3; nachX = 4; konY = 7; konX = 0;
    //cin >> nachY >> nachX >> konY >> konX; //не удалять

    
    vector<vector<int>> DOSKA(8, {0,0,0,0,0,0,0,0});
    pair<int, int> kin_pos = {nachY,nachX};
    DOSKA[kin_pos.first][kin_pos.second] = 1;

    print_doska(DOSKA);
    cout <<endl;

    doska_resh(DOSKA, nachY, nachX, konY, konX);
}