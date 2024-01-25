#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;



int main() {
	long double sum = 0;
	for (long double i = 0; i <= 100; i += 0.1) {
		sum += (4/(i*pow(log(i), 3)));
		cout << sum << endl;
	}
	cout << sum;
}