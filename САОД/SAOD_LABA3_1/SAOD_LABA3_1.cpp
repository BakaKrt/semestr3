
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 8; // Размер шахматной доски

typedef vector<pair<int, int>> pole;
typedef vector<int> pole_;

int main() {
    //pole hodi = { {-2,1},{-2,-1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2} };
    pole hodi = { {1,-2},{-1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,-1},{1-2,1} };
    vector<vector<int>> DOSKA; DOSKA.resize(8, {0,0,0,0,0,0,0,0});
    pair<int, int> kin_pos = {4,4};
    DOSKA[4][0] = 1;
    int y = 0; int x = 0;
    for (const auto& a : DOSKA) {
        y++;
        for (const auto& b : a) {
            x++;
            cout << b << " ";
        }
        cout << endl;
    }

}