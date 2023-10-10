#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <random>
#include <ctime>
#include <cstdlib>
#include <thread>

using namespace std;

const int N = 8; // Размер шахматной доски

typedef vector<pair<int, int>> pole;
pole hodi = { {1,-2},{-1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,-1},{-2,1} };
int VSE_HODI = 0;
vector<pole> all_path;
int GLOBAL_RESH = 0;

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

//vector<int> create_color_path(vector<int> a) {

//}

void print_doska(vector<vector<int>> &a, int pos_y = -10, int pos_x = -10, int prevY = -10, int prevX = -10, vector<int> path_c = { -1 }) {
    int y = 0; string color = "\x1b[38;5;"; int k = 0; short a_size = a[0].size();
    cout << "Это size: " << a_size << endl;
    for (const auto& a_ : a) {
        int x = 0;
        for (const auto& b_ : a_) {
            short pos = x * a_size + y;
            if (pos <= path_c.size() && path_c.at(pos) != -1) {
                string color = "\x1b[38;5;" + to_string(path_c.at(pos)) + "m";
                cout << color << b_ << "\x1b[40m ";
            }
            /*
            if (y == pos_y && x == pos_x) {
                cout << "\x1b[42m" << b_ << "\x1b[40m ";
            }
            else if (y == prevY && x == prevX) {
                cout << "\x1b[44m" << b_ << "\x1b[40m ";
            }*/
            else cout << b_ << " ";
            
            x++;
            k++;
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
    int ser = (in.size()+1)/2;
    //printf("Это середина: %d %d\n", ser,in.size());

    std::thread t1([&](){
        for (auto& a_ : in) {
            for (int sc_0 = 0; sc_0 < ser; sc_0++) {
                if (a_ == in_)
                    k++;
            }
        }
    });

    std::vector<std::vector<std::pair<int, int>>> reversed_in = in;
    std::reverse(reversed_in.begin(), reversed_in.end());

    std::thread t2([&]() {
        for (const auto& a_ : reversed_in) {
            for (int sc_1 = 0; sc_1 < in.size() - ser; sc_1++) {
                if (a_ == in_)
                    k++;
            }
        }
        });

    t1.join();
    t2.join();
    if (k == 0)
        return 1;
    return 0;
}

vector<int> color_path(vector<pair<int, int>> &path, int &nachX, int &nachY, short size) {
    int cur_x = nachX; int cur_y = nachY; vector<int> c_path(size*size);
    int color = 1;
    printf("DEBUG:\npath size: %d\nnachX:%d\tnachY:%d\nsize:%d",path.size(),nachX,nachY,size);
    cin.get(); 
    for (auto& p : path) {
        cur_y += p.first;
        cur_x += p.second;
        printf("curX:%d\tcurY:%d\t:%d\n",cur_x, cur_y, (cur_x * size) + (cur_y));
        c_path[(cur_x * size) + (cur_y)] = color;
        color++;
    }
    int sc = 0;
    for (auto& p : c_path) {
        printf("%d: %d\n", sc,p);
        sc++;
    }
    return c_path;
}



void doska_resh(vector<vector<int>> &v, int &nachY, int &nachX, int &konY, int &konX) {
    int cant_go = 0; int TOTAL_ERRORS = 0; int in_vec_size = v.size();
    pole path; int err_l = in_vec_size * in_vec_size * 200;
    
    
    for (int y = nachY; in_vec_size;) {
        for (int x = nachX; x <= in_vec_size;) {
            while (TOTAL_ERRORS <= 900000) {
                for (const auto& a : rand_vec()) {
                    if ((y + a.first >= 0 && y + a.first < in_vec_size && x + a.second >= 0 && x + a.second < in_vec_size) && v[y + a.first][x + a.second] != 1) {
                        cant_go = 0;
                        y += a.first;
                        x += a.second;
                        v[y][x] = 1;
                        path.push_back(a);
                        if (y == konY && x == konX) {
                            if (all_path.size() == 0) {
                                all_path.push_back(path);
                                print_doska(v, y, x, y - a.first, x - a.second, color_path(path, nachX, nachY, in_vec_size));
                                printf("Размер path: %d\nколичество комбинаций: %d\n", path.size(), all_path.size());
                                path.clear();
                            }
                            else {
                                if (path_exist(all_path, path) == 1) {
                                    all_path.push_back(path);
                                    print_doska(v, y, x, y - a.first, x - a.second);
                                    printf("Размер path: %d\nколичество комбинаций: %d\n", path.size(),all_path.size());
                                    path.clear();
                                    TOTAL_ERRORS = 0;
                                    clear_doska(v, nachY, nachX);
                                    x = nachX; y = nachY;
                                    //cin.get();
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
            }
            return;
        }
    }
    return;
}

int main() {
    setlocale(0, "");
    printf("Введите две пары чисел: {начY,начX} {конY,конX}: \n");
    int nachY, nachX, konY, konX;
    nachY = 4; nachX = 4; konY = 0; konX = 0;
    //cin >> nachY >> nachX >> konY >> konX; //не удалять

    
    vector<vector<int>> DOSKA(5, { 0,0,0,0,0 });
    DOSKA[nachY][nachX] = 1;
    DOSKA[konY][konX] = 2;

    print_doska(DOSKA);
    cout <<endl;

    doska_resh(DOSKA, nachY, nachX, konY, konX);

    /*std::thread potok1([&]() {
        doska_resh(DOSKA, nachY, nachX, konY, konX);
    });
    std::thread potok2([&]() {
        doska_resh(DOSKA, nachY, nachX, konY, konX);
    });
    potok1.join();
    potok2.join();
    */
    //potok1.join();
    printf("\nКоличество путей: %d",all_path.size());
}