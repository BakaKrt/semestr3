#include <iostream>
using namespace std;

class dog {
private:
    bool happy = false;
public:
    void bark() {
        cout << "bark";
    }
    
    bool is_happy() {
        return happy;
    }

    void print_happy() {
        if (happy) {
            cout << "\nHappy";
        }
        else cout << "\nNot happy";
    }

    void set_happy(bool set) {
        happy = set;
    }
};

struct str {
    string a = "abcd";
    bool happy = false;
};

typedef void(dog::* nazvanie)();

int test_f(int x) {
    return x * x;
}

int (*ptr_test)(int) = &test_f;

int main()
{
    cout << test_f(2);
    cout << ptr_test(2);
    int* a = new int (13);
    double* b;
    void* void_ptr = new str;
    auto* auto_ptr = static_cast<str*>(void_ptr);
    cout << auto_ptr->a << endl;

    cout << (static_cast<str*>(void_ptr))->a << " ";
    cout << (static_cast<str*>(void_ptr))->happy;

    cout << endl;
    b = new double(static_cast<double>(*a));
    cout << *b << endl;


    dog *pDOG = new dog();
    //pDOG->bark();
    //pDOG->print_happy();

    void (dog:: * setHappinnes)(bool) = &dog::set_happy;
    setHappinnes = 0;

    void (dog:: * prhap)() = &dog::print_happy;
    (pDOG->*prhap)();

    bool (dog:: *get_happy)(void) = &dog::is_happy;
    
    auto g = get_happy;
    cout << g;
    //pDOG->is_happy();
    delete pDOG;
}
