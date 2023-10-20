#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct instruction {
    string MOVE_SYMBOL;
    int MOVE_TO;
} INSTR;

class lenta {
public:
    lenta() {
        v.resize(21);
        for (int i = 0; i < v.size(); i++) {
            v[i] = "#";
        }
        CUR_SYMB = v[CUR_POS];
    }
    void print_cur_symbol() {
        cout << CUR_SYMB;
    }

    void get_cur_inf() {
        printf("\nCUR_POS:%d\tv[CUR_POS]:%s\n", CUR_POS, v[CUR_POS].c_str());
    }

    void put_to_sight(instruction inst) {
        if (CUR_POS + inst.MOVE_TO != 0 || CUR_POS + inst.MOVE_TO != v.size()) {
            v[CUR_POS] = inst.MOVE_SYMBOL;
            printf("\nCUR_POS:%d\tv[CUR_POS]:%s\t{%s,%d}\n", CUR_POS+inst.MOVE_TO, v[CUR_POS].c_str(), inst.MOVE_SYMBOL.c_str(), inst.MOVE_TO);
            CUR_POS += inst.MOVE_TO;
            //cout << v[CUR_POS] << endl;
        }
        else {
            cout << "\nВышли за пределы ленты!\n\n";
        }
    }
    void print_lent() {
        for (int i = 0; i < v.size(); i++) {
            cout << i << " " << setw(3);
        } cout << endl << setw(1);


        for (const auto& a : v) {
            cout << a << " " << setw(3);
        } cout << setw(1);
    }

    instruction get_com_from_input(string in) {
        if (in.size() == 2) {
            return { string(1,in[0]), stoi(string(1,in[1])) };
        }
        else 
            return { string(1,in[0]), stoi(string(1,in[1]) + string(1,in[2])) };
    }

    void translate_to_command() {
        string in;
        while (in != "#") {
            cin >> in;
            //if (in!="print")
            this->put_to_sight(get_com_from_input(in));
            //else
            this->print_lent();
            cout << endl;
        }
    }

private:
    vector<string> v;
    int CUR_POS = 10;
    string CUR_SYMB;
};

int main() {
    setlocale(0, "");
    lenta l;
    //l.print_cur_symbol();
    //l.put_to_sight({ "a", -1 });
    l.get_cur_inf();
    l.translate_to_command();
    l.print_lent();
    return 0;
}