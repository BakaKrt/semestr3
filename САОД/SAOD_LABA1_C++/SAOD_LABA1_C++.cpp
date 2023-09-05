#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;


#define debug(Expression)\
     std::cout << "\n{" #Expression "}: " << (Expression) << std::endl;

class stack {
    
    private:
        int k_number_of_stack = 0;
    public:
        int stack_[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
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
        void print_2stack(stack x, stack y) {
            for (int i = 0; i < 10; i++) {
                printf("%d. %d\t\t%d. %d\n", i, x.stack_[i], i, y.stack_[i]);
            }
            cout << endl;
        }
};

int uniq[10] = {-2}; //int uniq_calls = 0;
int uniqs[10] = {}; //массив с уникальными случайными значениями
void get_uniq_rand() {
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        int random = rand() % 10;
        while (uniq[random] == random) {
            random = rand() % 10;
        }
        uniq[random] = random;
        uniqs[i] = random;
    }
}

int main()
{
    setlocale(0, "");
    int choose;
    stack a, b;
    printf("Выберите способ ввода колоды:\n1) Случайное распределение\n2) Ручной ввод\n");
    cin >> choose;
    system("cls");
    if (choose == 1) {
        get_uniq_rand();
        for (int i = 0; i < 10; i++) {
            if (i < 5)
                a.push(uniqs[i]);
            else
                b.push(uniqs[i]);
        }
        cout << "Начальное положение колод\nСтек А: \t Стек B:\n";
        a.print_2stack(a,b);
        cout << "===========================\n";
    }
    else if (choose == 2) {
        cout << "Ввод в обратном порядке(с конца до начала)\n";
        int s = -1;
        for (int i = 0; i < 5; i++) {
            cout << "Введите значение карты колоды A: ";
            cin >> s;
            while (s > 10 || s < 0) {
                cin >> s;
            }
            a.push(s);
        }
        for (int i = 0; i < 5; i++) {
            cout << "Введите значение карты колоды B: ";
            cin >> s;
            while (s > 10 || s < 0) {
                cin >> s;
            }
            b.push(s);
        }
        a.print();
        b.print();
    }
    else {
        cout << "Неправильный ввод! Попробуй снова: ";
        cin >> choose;
    }

    while (!a.empty() || !b.empty()) {
        stack a_, b_, _a, _b;
        if ((a.stack_top() > b.stack_top()) || (a.stack_top() == 0 && b.stack_top() == 9)) {
            printf("Выйграла колода A\n");
            a_.push(b.stack_top()); b.pop();
            a_.push(a.stack_top()); a.pop();
            
            while(!(a.empty()))
                _a.push(a.pop());
            while (!(_a.empty()))
                a_.push(_a.pop());
            cout << "Стек А: \t Стек B:\n";
            a = a_;
            a.print_2stack(a, b);
        }
        else if ((b.stack_top() > a.stack_top()) || (b.stack_top() == 0 && a.stack_top() == 9)) {
            printf("Выйграла колода B\n");
            b_.push(a.stack_top()); a.pop();
            b_.push(b.stack_top()); b.pop();

            while (!(b.empty()))
                _b.push(b.pop());
            while (!(_b.empty()))
                b_.push(_b.pop());
            cout << "Стек А: \t Стек B:\n";
            b = b_;
            a.print_2stack(a, b);
        }
        cout << "###############" << endl;
        if ((a.empty()) || (b.empty())) break;
    }
    cout << "Конечный результат\n";
    cout << "======================\n\n";
    cout << "Стек A\t\tСтек B\n";
    a.print_2stack(a, b);
    cout << "======================\n";

}