#include <iostream>
using namespace std;

int func(int x) {
    return x * x;
}

int (*my_ptr)(int) = &func;

int main() {
    cout << func(2) << endl;
    cout << my_ptr(2);
}
