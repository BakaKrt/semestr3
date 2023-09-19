#include <iostream>
#include <map>
using namespace std;

int main() {
    setlocale(0, "");
    map<int, string> bd; int in;
    bd[228] = "Tarkov ERR";
    bd[1] = "Backend ERR";
    bd[69] = "Что-то пошло не так";
    bd[2] = "Что-то снова пошло не так";
    cout << "Введите код ошибки: ";
    cin >> in; bool finded = false;
    for (const auto& a : bd) {
        if (a.first == in){
            printf("Объяснение кода ошибки: %s", a.second.c_str());
            finded++;
        }
    }
    if (!finded) cout << "Неправильный код ошибки!";
}



