#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


#define debug(Expression)\
     std::cout << "\n{" #Expression "}: " << (Expression) << std::endl;

class stack {
private:
    int k_number_of_stack = 0;
    string* STACK;
    int len;
public:
    void set_len(string input) {
        STACK = new string[input.size()];
        len = input.size();
    }
    int empty() {
        short k = 0;
        for (int i = 0; i < len; i++) {
            if (STACK[i] != "") return false;
            else continue;
        }
        return true;
    }
    void push(string x) {
        if (STACK[0].size() > 0) {
            for (int i = len-2; i > -1; i--) {
                STACK[i + 1] = STACK[i];
            }
            STACK[0] = x;
        }
        else {
            STACK[0] = x;
        }
    }
    string pop() {
        string a = STACK[0];
        for (int i = 0; i < len-1; i++) {
            STACK[i] = STACK[i + 1];
        }
        STACK[len-1] = "";
        return a;
    }
    string stack_top() {
        return STACK[0];
    }
    void print() {
        for (int i = 0; i < len; i++) {
            cout << i << ". " << STACK[i] << endl;
        }
        cout << endl;
    }
    void print_2stack(stack x, stack y) {
        for (int i = 0; i < len; i++) {
            printf("%d. %s\t\t%d. %s\n", i, x.STACK[i], i, y.STACK[i]);
        }
        cout << endl;
    }
    ~stack() {
        delete[] STACK;
    }
};

int main()
{
    setlocale(0, "");
    string input = "*–*–+ab*cde–fg+hi";
    stack a; a.set_len(input);
    stack b; b.set_len(input);
    cout << input << " " /* << input.size()*/ << endl;
    for (int i = 0; i < input.size(); i++) {
        string temp; temp += input[i];
        a.push(temp);
    }
    a.print();

    bool is_word = false;
    string temp; int k = 0;
    while (!a.empty()) {
        string a_ = a.pop();
        if (a_ >= "a" && a_ <= "z") {
            is_word = true;
        }
        else {
            temp += b.pop();
            temp += b.pop();
            temp += a_;
            cout << temp << endl;
            is_word = false;
            b.push(temp);
            temp.clear();
        }
        if (is_word) {
            b.push(a_);
        }
    }
    cout << "Ответ: " << b.stack_top();
}