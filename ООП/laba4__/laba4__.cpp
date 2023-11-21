#include <iostream>
#include <string>

using namespace std;

class my_class {
public:
	int a = 10;
	void set_a() {
		cin >> a;
	}
	void print() {
		cout << a;
	}
};

int main()
{
	my_class my, *myptr = &my;
	my_class(*ptr)() = (my_class::print);

	void *void_ptr;
	void_ptr = myptr;
	static_cast<my_class*>(void_ptr)->print();
	((my_class*)void_ptr)->print();

}
