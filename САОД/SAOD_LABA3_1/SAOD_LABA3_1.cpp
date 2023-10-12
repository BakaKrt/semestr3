#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

#include <random>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <mutex>

using namespace std;

const int N = 8; // Размер шахматной доски

typedef vector<pair<int, int>> pole;
pole hodi = { {1,-2},{-1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,-1},{-2,1} };
int VSE_HODI = 0;
vector<pole> all_path;
int GLOBAL_RESH = 0;

pole rand_vec() {
    //mutex mtx;
    //mtx.lock();
    srand(time(nullptr));
    pole a, hodi_ = hodi;
    for (int i = 0; i < 8; i++) {
        a.push_back(hodi_[rand()%hodi_.size()]);
        auto it = std::remove(hodi_.begin(), hodi_.end(), a.back());
        hodi_.erase(it, hodi_.end());
    }
    //mtx.unlock();
    return a;
}
pole rand_vec_() {
    //mutex mtx;
    //mtx.lock();
    srand(time(nullptr));
    pole a, hodi_ = hodi;
    for (int i = 0; i < 8; i++) {
        a.push_back(hodi_[rand() % hodi_.size()]);
        auto it = std::remove(hodi_.begin(), hodi_.end(), a.back());
        hodi_.erase(it, hodi_.end());
    }
    //mtx.unlock();
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


void print_doska(vector<vector<int>> &a, int pos_y = -10, int pos_x = -10, int prevY = -10, int prevX = -10) {
    int y = 0; string color = "\x1b[38;5;"; int k = 0; short a_size = a[0].size();
    //cout << "Это size: " << a_size << endl;
    for (const auto& a_ : a) {
        int x = 0;
        for (const auto& b_ : a_) {
            if (y == pos_y && x == pos_x) {
                cout << "\x1b[42m" << b_ << "\x1b[40m ";
            }
            else if (y == prevY && x == prevX) {
                cout << "\x1b[44m" << b_ << "\x1b[40m ";
            }
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

void print_path(vector<pair<int,int>> in) {
    for (const auto& a : in) {
        printf("%d %d\t", a.first,a.second);
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


void doska_resh(vector<vector<int>> &v, int &nachY, int &nachX, int &konY, int &konX) {
    int cant_go = 0, cant_go1 = 0; int TOTAL_ERRORS = 0; int in_vec_size = v.size();
    pole path, path1; int err_l = in_vec_size * in_vec_size * 200;
    vector<vector<int>> v_; copy(v.begin(), v.end(), back_inserter(v_));
    mutex mtx;

    print_doska(v_);
    for (int y = nachY, y1 = nachY; y <= in_vec_size, y1 <= in_vec_size;) {
        for (int x = nachX, x1 = nachX; x <= in_vec_size, x1 <= in_vec_size;) {
            while (TOTAL_ERRORS <= 900000) {
                thread p1([&]() {
                    //cout << "Поток 1{\n";
                    for (const auto& a : rand_vec()) {
                        if ((y + a.first >= 0 && y + a.first < in_vec_size && x + a.second >= 0 && x + a.second < in_vec_size) && v[y + a.first][x + a.second] != 1) {
                            cant_go = 0;
                            y += a.first;
                            x += a.second;
                            v[y][x] = 1;
                            mtx.lock();
                            path.push_back(a);
                            mtx.unlock();
                            //printf("Добавили в path , size(%d), a{%d,%d}\n", path.size(), a.first, a.second);
                            if (y == konY && x == konX) {
                                mtx.lock();
                                //printf("Текущий поток 1: %d, захватили mutex\n", this_thread::get_id());
                                if (all_path.size() == 0) {
                                    all_path.push_back(path);
                                    cout << "Доска 1:\n";
                                    print_doska(v, y, x, y - a.first, x - a.second);
                                    printf("Размер path: %d\nколичество комбинаций: %d\n", path.size(), all_path.size());
                                    path.clear();
                                    //printf("Текущий поток 1: %d, разблокирую mutex\n", this_thread::get_id());
                                }
                                else {
                                    //printf("Текущий поток 1: %d, захватили mutex\n", this_thread::get_id());
                                    if (path_exist(all_path, path) == 1) {
                                        all_path.push_back(path);
                                        cout << "Доска 1:\n";
                                        print_doska(v, y, x, y - a.first, x - a.second);
                                        printf("Размер path: %d\nколичество комбинаций: %d\n", path.size(), all_path.size());
                                        //cout << "Путь 1:\n";
                                        //print_path(path);
                                        path.clear();
                                        TOTAL_ERRORS = 0;
                                        clear_doska(v, nachY, nachX);
                                        x = nachX; y = nachY;
                                    }
                                }
                                //printf("Текущий поток 1: %d, разблокировал mutex\n", this_thread::get_id());
                                mtx.unlock();
                            }
                        }
                        else {
                            cant_go++;
                            if (cant_go > 9) {
                                //cout << "Путь 1: \n";
                                //print_path(path);
                                //printf("Очистили path\n");
                                path.clear();
                                clear_doska(v, nachY, nachX);
                                x = nachX; y = nachY;
                                cant_go = 0;
                                TOTAL_ERRORS++;
                                //continue;
                            }
                        }
                    }
                });
                thread p2([&]() {
                    for (const auto& a : rand_vec_()) {
                        if ((y1 + a.first >= 0 && y1 + a.first < in_vec_size && x1 + a.second >= 0 && x1 + a.second < in_vec_size) && v_[y1 + a.first][x1 + a.second] != 1) {
                            cant_go1 = 0;
                            y1 += a.first;
                            x1 += a.second;
                            v_[y1][x1] = 1;
                            mtx.lock();
                            path1.push_back(a);
                            mtx.unlock();
                            //printf("Добавили в path1, size(%d), a{%d,%d}\n", path1.size(), a.first, a.second);
                            if (y1 == konY && x1 == konX) {
                                mtx.lock();
                                //printf("Текущий поток 2: %d, захватили mutex\n", this_thread::get_id());
                                if (all_path.size() == 0) {
                                    all_path.push_back(path1);
                                    cout << "Доска 2:\n";
                                    print_doska(v_, y1, x1, y1 - a.first, x1 - a.second);
                                    printf("Размер path1: %d\nколичество комбинаций: %d\n", path1.size(), all_path.size());
                                    path1.clear();
                                    //printf("Текущий поток 2: %d, разблокирую mutex\n", this_thread::get_id());
                                }
                                else {
                                    //printf("Текущий поток 2: %d, захватили mutex\n", this_thread::get_id());
                                    if (path_exist(all_path, path1) == 1) {
                                        all_path.push_back(path1);
                                        cout << "Доска 2:\n";
                                        print_doska(v_, y1, x1, y1 - a.first, x1 - a.second);
                                        printf("Размер path1: %d\nколичество комбинаций: %d\n", path1.size(), all_path.size());
                                        //cout << "Путь 2:\n";
                                        //print_path(path1);
                                        path1.clear();
                                        TOTAL_ERRORS = 0;
                                        clear_doska(v_, nachY, nachX);
                                        x1 = nachX; y1 = nachY;
                                    }
                                }
                                mtx.unlock();
                                //printf("Текущий поток 2: %d, разблокировал mutex\n", this_thread::get_id());
                            }
                        }
                        else {
                            cant_go1++;
                            if (cant_go1 > 9) {
                                //cout << "Путь 2:\n";
                                //print_path(path1);
                                path1.clear();
                                //printf("Очистили path1\n");
                                clear_doska(v_, nachY, nachX);
                                x1 = nachX; y1 = nachY;
                                cant_go1 = 0;
                                TOTAL_ERRORS++;
                                //continue;
                            }
                        }
                    }
                    //cout << "}Поток 2\n";
                });
                p1.join();
                p2.join();

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

    printf("\nКоличество путей: %zd", all_path.size());
}