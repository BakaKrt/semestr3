#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	typedef wchar_t WCHR;
	typedef long double LDBL;

	int chislo;
	float desyat_chislo;
	char r;
	WCHR wchar;
	double double_chislo;
	LDBL long_chislo;
	bool istina;

	struct RAB_{
		char *Name;
		char *Dolzhnost;
		int Age;
		bool Pol;
		float Zarplata;
	} RAB; 

	//enum Months {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	enum Months_1 { JAN = 3, FEB = 12, MAR = 1, APR = 11, MAY = 2, JUN = 5, JUL = 8, AUG = 4, SEP = 10, OCT = 9, NOV = 7, DEC = 6 };

	cout << "ПУНКТ №1" << endl;

	cout << "Количество байт для типа int = " << sizeof(chislo) << endl;
	cout << "Количество байт для типа float = " << sizeof(desyat_chislo) << endl;
	cout << "Количество байт для типа char = " << sizeof(r) << endl;
	cout << "Количество байт для типа wchar_t = " << sizeof(wchar) << endl;
	cout << "Количество байт для типа double = " << sizeof(double_chislo) << endl;
	cout << "Количество байт для типа long double = " << sizeof(long_chislo) << endl;
	cout << "Количество байт для типа bool = " << sizeof(istina) << endl;
	cout << "Количество байт для типа struct = " << sizeof(RAB) << endl;
	cout << "Количество байт для типа enum = " << sizeof(Months_1) << endl << endl;

	cout << "ПУНКТ №2" << endl;

	cout << "Размер wchar_t до преобразования = " << sizeof(wchar_t) << ", и после преобразования = " << sizeof(WCHR) << endl;
	cout << "Размер long double до преобразования = " << sizeof(long double) << ", и после преобразования = " << sizeof(LDBL) << endl << endl;

	cout << "ПУНКТ №3" << endl;
	int summa = Months_1::FEB - Months_1::APR;
	cout << summa << endl << endl;

	cout << "ПУНКТ №4" << endl;

	cout << "Количество байт для хранения поля Name структуры = " << sizeof(RAB.Name) << ", " << "для поля Dolzhnost = " << sizeof(RAB.Dolzhnost) << ", " <<
		"для поля Age = " << sizeof(RAB.Age) << ", " << "для поля Pol = " << sizeof(RAB.Pol) << ", " << "для поля Zarplata = " << sizeof(RAB.Zarplata) << ". " << endl << endl;
	if ((sizeof(RAB.Name) + sizeof(RAB.Dolzhnost) + sizeof(RAB.Age) + sizeof(RAB.Pol) + sizeof(RAB.Zarplata)) == sizeof(RAB))
		cout << "Количество байт совпадает с пунктом №1" << endl;
	else
		cout << "Разница в значениях = " << (sizeof(RAB) - ((sizeof(RAB.Name) + sizeof(RAB.Dolzhnost) + sizeof(RAB.Age) + sizeof(RAB.Pol) + sizeof(RAB.Zarplata)))) << endl << endl;

	cout << "ПУНКТ №5" << endl;

	desyat_chislo = 13457.713;
	cout << desyat_chislo << endl;
	cout << (int)desyat_chislo << endl;

	chislo = 10;
	cout << chislo << endl;
	cout << (float)chislo << endl;

	double_chislo = 9.99;
	cout << double_chislo << endl;
	cout << (int)double_chislo << endl << endl;

	cout << "ПУНКТ №6" << endl;

	cout << "Находится ли chislo раньше, чем RAB.Pol? (1-Да, 0-Нет): " << typeid(chislo).before(typeid(RAB.Pol)) << endl;
	cout << "Находится ли istina раньше, чем r? (1-Да, 0-Нет): " << typeid(istina).before(typeid(r)) << endl << endl;
	cout << "Имя типа double_chislo = " << typeid(double_chislo).name() << endl << "для long_chislo = " << typeid(long_chislo).name() << endl
		<< "для chislo = " << typeid(chislo).name() << endl << "для desyat_chislo = " << typeid(desyat_chislo).name() << endl << "для r = "
		<< typeid(r).name() << endl << "для wchar = " << typeid(wchar).name() << endl << "для istina = " << typeid(istina).name() << endl;
}