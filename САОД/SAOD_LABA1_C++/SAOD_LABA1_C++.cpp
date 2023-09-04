#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;


#define debug(Expression)\
     std::cout << "\n{" #Expression "}: " << (Expression) << std::endl;

class stack {
    int stack_[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    public:
        int empty() {
            short k = 0;
            for (int i = 0; i < 10; i++) {
                if (stack_[i] != -1) return false;
                else continue;
            }
            return true;
        }
        void push(int x) {
            if (stack_[0] > -1) {
                for (int i = 8; i > -1; i--) {
                    //cout << i << "  " << stack_[i + 1] << " " << stack_[i] << endl;
                    stack_[i+1] = stack_[i];
                }
                //cout << "Записали " << x << endl;
                stack_[0] = x;
            }
            else {
                //printf("Записали в первый эл-т %d\n", x);
                stack_[0] = x;
            }
        }
        int pop() {
            int a = stack_[0];
            for (int i = 0; i < 9; i++) {
                stack_[i] = stack_[i + 1];
            }
            return a;
        }
        int stack_top() {
            return stack_[0];
        }
        void print() {
            for (int i = 0; i < 10; i++){
                printf("%d. %d\n", i , stack_[i]);
            }
            cout << endl;
        }
};

int uniq[10] = {-2}; //int uniq_calls = 0;
int uniqs[10] = {};
void get_uniq_rand() {
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        int random = rand() % 10;
        while (uniq[random] == random) {
            random = rand() % 10;
        }
        uniq[random] = random;
        printf("%d %d %d\n", i, uniq[random], random);
        uniqs[i] = random;
    }
}

int main()
{
    setlocale(0, "");

    stack a, b;
    get_uniq_rand();
    for (int i = 0; i < 10; i++) {
        if (i < 5)
            a.push(uniqs[i]);
        else
            b.push(uniqs[i]);
    }
    cout << "********** стэк а" << endl;
    a.print();
    b.print();
    cout << "********** стэк b" << endl;
    printf("Пустые ли стеки: %d %d\n", a.empty(), b.empty());

    while (!a.empty() || !b.empty()) {
        stack a_, b_, _a, _b;
        if ((a.stack_top() > b.stack_top()) || (a.stack_top() == 0)) {
            printf("Выйграла колода a\n");
            a_.push(b.stack_top()); b.pop();
            a_.push(a.stack_top()); a.pop();
            
            while(!(a.empty()))
                _a.push(a.pop());
            while (!(_a.empty()))
                a_.push(_a.pop());
            cout << "Рисуем a: \n";
            a_.print();
            a = a_;
            cout << "Рисуем b: \n";
            b.print();
        }

        if ((b.stack_top() > a.stack_top()) || (b.stack_top() == 0)) {
            printf("Выйграла колода b\n");
            b_.push(a.stack_top()); a.pop();
            b_.push(b.stack_top()); b.pop();

            while (!(b.empty()))
                _b.push(b.pop());
            while (!(_b.empty()))
                b_.push(_b.pop());
            cout << "Рисуем b: \n";
            b_.print();
            b = b_;
            cout << "Рисуем a: \n";
            a.print();
        }
        cout << "###############" << endl;
        if ((a.empty()) || (b.empty())) break;
    }
    cout << "\n***********\n";
    a.print();
    b.print();
    cout << "\n***********\n";

}