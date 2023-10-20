#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct instruction {
    string MOVE_SYMBOL;
    int MOVE_TO;
} INSTR;

struct commands {
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
        COMMS.push_back({ "q1","a","q1","a","1" });
        COMMS.push_back({ "q1","#","q2","#","-1" });
        COMMS.push_back({ "q2","a","q2","b","-1" });
        COMMS.push_back({ "q2","b","q2","b","-1" });
        COMMS.push_back({ "q2","#","q0","#","1" });
        COMMS.push_back({ "q1","s","q0","s","0" });
        //COMMS.push_back({ "q2","b","q0","c","0" });
        //COMMS.push_back({ "q2","b","q0","c","0" });
    }
    void print_cur_symbol() {
        cout << CUR_SYMB;
    }

    void process_coms() {
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

    void get_cur_inf() {
        printf("\nCUR_POS:%d\tv[CUR_POS]:%s\n", CUR_POS, v[CUR_POS].c_str());
    }

    void put_to_sight(instruction inst) {
        if (CUR_POS + inst.MOVE_TO != 0 || CUR_POS + inst.MOVE_TO != v.size()) {
            v[CUR_POS] = inst.MOVE_SYMBOL;
            printf("\nCUR_POS:%d\tv[CUR_POS]:%s\nCUR_SOST:%s\t{%s,%d}\n", CUR_POS+inst.MOVE_TO, v[CUR_POS].c_str(),CUR_SOST.c_str(), inst.MOVE_SYMBOL.c_str(), inst.MOVE_TO);
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
                //printf("%3d\x1b[40m", i);
                cout << setw(7) << "\x1b[42m" << i << "\x1b[40m" << setw(4);
            }
            else
                cout << i << " " << setw(3);
        } cout << endl << setw(1);


        for (const auto& a : v) {
            cout << a << " " << setw(3);
        } cout << setw(1) << endl;;
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
        bool is_print = false;
        while (in != "#") {
            cin >> in;
            if (in == "print") {
                is_print = true;
                cin >> in;
            }
            if (in == "stop") {
                break;
            }

            //if (in!="print")
            this->put_to_sight(get_com_from_input(in));
            //else
            
            //this->print_lent();
            cout << endl;
        }
    }

private:
    vector<string> v;
    vector<commands> COMMS;
    string CUR_SOST = "q1";
    int CUR_POS = 10;
    string CUR_SYMB;
};

int main() {
    setlocale(0, "");

    lenta l;
    l.get_cur_inf();
    l.translate_to_command();
    l.process_coms();
    l.print_lent();
    return 0;
}