#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Order {
    double penalty; // штраф
    double deadline; // срок выполнения
};

bool compareOrders(Order a, Order b) {
    return (a.deadline < b.deadline);
}

double calculatePenalty(vector<Order> orders) {
    sort(orders.begin(), orders.end(), compareOrders);

    double totalPenalty = 0.0;
    for (int i = 0; i < orders.size(); i++) {
        totalPenalty += orders[i].penalty;
    }

    return totalPenalty;

}

int main() {
    setlocale(0, "");
    vector<Order> orders;

    Order first;
    first.deadline = 10; first.penalty = 5;
    orders.push_back(first);
    //calculatePenalty(orders);

    cout << "Минимальная сумма штрафов равна: " << calculatePenalty(orders) << endl;

    return 0;

}
