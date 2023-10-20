#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct instruction {
    string MOVE_SYMBOL;
    int MOVE_TO;
};

struct commands { //структура, хранящее команды для инструкций
    string CUR_STATE;
    string CUR_SYMBOL;
    string TO_STATE;
    string TO_SYMBOL;
    string TO_MOVE;
};

class lenta {
public:
    lenta() {
        v.resize(21);
        for (int i = 0; i < v.size(); i++) {
            v[i] = "#";
        }
        CUR_SYMB = v[CUR_POS];
        //COMMS.push_back({ "q1","a","q1","a","1" });
        //COMMS.push_back({ "q1","#","q2","#","-1" });
        //COMMS.push_back({ "q2","a","q2","b","-1" });
        //COMMS.push_back({ "q2","b","q2","b","-1" });
        //COMMS.push_back({ "q2","#","q0","#","1" });
        //COMMS.push_back({ "q1","s","q0","s","0" });
        //COMMS.push_back({ "q2","b","q0","c","0" });
        //COMMS.push_back({ "q2","b","q0","c","0" }); //расскоментить если хочется добавить инструкции по умолчанию
    }

    void add_commads() { // функция добавления комманд в вектор комманд COMMS
        string in = "";
        while (in != "stop") {
            cout << " >"; cin >> in;
            if (in == "stop") {
                this->menu(); //вызываем снова меню при вводе == "menu"
            }
            in += " ";
            COMMS.push_back({ in.substr(0,2), in.substr(2,1), in.substr(3,2), in.substr(5,1), in.substr(6,2) });
        }
    }

    void process_coms() { // проводит вычисление заданной ленты при заданных инструкциях и состояниях
        while (CUR_SOST != "qo") {
            for (auto& c : COMMS) {
                if (CUR_SOST == c.CUR_STATE && v[CUR_POS] == c.CUR_SYMBOL) {
                    this->put_to_sight({ c.TO_SYMBOL, stoi(c.TO_MOVE) });
                    CUR_SOST = c.TO_STATE;
                    if (CUR_SOST == "q0") {
                        cout << "\nКонечное состояние!\n";
                        return;
                    }
                }
            }
        }
    }

    void put_to_sight(instruction inst) { // помещаем на ленту символы в соответствии с [символ][направление]
        if (CUR_POS + inst.MOVE_TO != 0 || CUR_POS + inst.MOVE_TO != v.size()) {
            v[CUR_POS] = inst.MOVE_SYMBOL;
            //printf("\nCUR_POS:%d\tv[CUR_POS]:%s\nCUR_SOST:%s\t{%s,%d}\n", CUR_POS+inst.MOVE_TO, v[CUR_POS].c_str(),CUR_SOST.c_str(), inst.MOVE_SYMBOL.c_str(), inst.MOVE_TO);
            CUR_POS += inst.MOVE_TO;
            print_lent(CUR_POS);
        }
        else {
            cout << "\nВышли за пределы ленты!\n\n";
        }
    }
    void print_lent(int C_POS=-1) {
        for (int i = 0; i < v.size(); i++) {
            if (i == C_POS) {
                cout << setw(7) << "\x1b[42m" << i << "\x1b[40m" << setw(4);
            }
            else
                cout << i << " " << setw(3);
        } cout << endl << setw(1);


        for (const auto& a : v) {
            cout << a << " " << setw(3);
        } cout << setw(1) << endl;
        if (end) cout << endl;
    }

    instruction get_com_from_input(string in) { //транслятор в вид [символ][направление]
        if (in.size() == 2) {
            return { string(1,in[0]), stoi(string(1,in[1])) };
        }
        else 
            return { string(1,in[0]), stoi(string(1,in[1]) + string(1,in[2])) };
    }

    void translate_to_command() { //получаем ввод от пользователя и добавляем в ленту символы
        string in;
        while (in != "#") {
            cout << " >"; cin >> in;
            if (in == "stop") {
                return;
            }

            this->put_to_sight(get_com_from_input(in));
            cout << endl;
        }
    }

    void save_comms_to_fs() { //сохраняем команды в файловую систему
        ofstream file;
        file.open("config.txt");
        if (file.is_open()) {
            cout << "Начал запись в файл инструкций!\n";
            for (const auto& a : COMMS) {
                file << a.CUR_STATE << a.CUR_SYMBOL << a.TO_STATE << a.TO_SYMBOL << a.TO_MOVE << endl;
            }
            cout << "Запись инструкций завершена.\n";
        }
        else {
            cout << "\nНе удалось открыть файл!\n";
        }
        file.close();
    }

    void load_from_fs() { //загружаем команды из файловой системы
        ifstream file; string in;
        file.open("config.txt");
        if (file.is_open()) {
            cout << "Открыл файл для чтения инструкций\n";
            while (getline(file, in)) {
                COMMS.push_back({ in.substr(0,2), in.substr(2,1), in.substr(3,2), in.substr(5,1), in.substr(6,2) });
            }
            cout << "Считал и записал инструкции!\n";
        }
    }

    void print_com() {
        for (auto& a : COMMS) {
            cout << a.CUR_STATE << a.CUR_SYMBOL << a.TO_STATE << a.TO_SYMBOL << a.TO_MOVE << endl;
        }
    }

    void menu() {
        printf("Доступные команды:\n1) add_lenta\n2) add_com\n3) load_com\n4) save_com\n5) print_com\n6) start\n7) leave\tНапишите stop в команде, чтобы выйти в меню\n >");
        string in;
        cin >> in;
        while (in != "leave") {
            if (in == "add_lenta" || in == "1") {
                printf("Синтаксис команды: [СИМВОЛ][НАПРАВЛЕНИЕ]. Пример: a-1\n");
                this->translate_to_command();
                cout << " >"; cin >> in;
            }
            else if (in == "stop") {
                printf("Доступные команды:\n1) add_lenta\n2) add_com\n3) load_com\n4) save_com\n5) print_com\n6) start\n7) leave\tНапишите stop в команде, чтобы выйти в меню\n >");
                cin >> in;
            }
            else if (in == "add_com" || in == "2") {
                printf("Синтаксис команды: [Текущее состояние][Символ a][Следующее состояние][Символ b][Направление движения{-1,0,1}]\nПример: q1cq2a-1\n");
                this->add_commads();
                cout << " >"; cin >> in;
            }
            else if (in == "load_com" || in == "3") {
                this->load_from_fs();
                cout << " >"; cin >> in;
            }
            else if (in == "save_com" || in == "4") {
                save_comms_to_fs();
                cout << " >"; cin >> in;
            }
            else if (in == "print_com" || in == "5") {
                this->print_com();
                cout << " >"; cin >> in;
            }
            else if (in == "start" || in == "6") {
                end = true;
                this->process_coms();
                cout << " >"; cin >> in;
            }
            else if (in == "leave" || in == "7") {
                in = "leave";
                return;
            }
            else {
                cout << "Неправильная команда, введи заново: ";
                cout << " >"; cin >> in;
            }
        }
    }

private:
    vector<string> v;
    vector<commands> COMMS;
    string CUR_SOST = "q1";
    int CUR_POS = 10;
    string CUR_SYMB;
    bool end = false;
};

int main() {
    setlocale(0, "");
    lenta l;

    l.menu();
    return 0;
}