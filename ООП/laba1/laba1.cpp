#include <iostream>
using namespace std;

typedef wchar_t rebkgke;

struct primer1 {
	int pole1 = 10;
	bool x = false;
	wchar_t abc = 'abc';
} pole;

struct PUST {
	int pole1; bool x; wchar_t abc;
} pust;

enum error{ERR_READ, ERR_WRITE, ERR_CONVERT};
enum error_{_ERR_READ = -1, _ERR_WRITE = -2, _ERR_CONVERT = 100};

void p1() {
	printf("Пункт #1\n");
	printf("Количество байт для основных типов: int %d, char %d, wchar_t %d, bool %d, float %d, double %d\n\n", \
		sizeof(int), sizeof(char), sizeof(wchar_t), sizeof(bool), sizeof(float), sizeof(double));
}

void p2() {
	typedef wchar_t WCH;
	typedef long double LLD;
	printf("Пункт #2\n");
	printf("Размер wchar_t до преобразования: %d; и после: %d\n", sizeof(wchar_t), sizeof(WCH));
	printf("Размер long double до преобразования: %d; и после: %d\n", sizeof(long double), sizeof(LLD));
}
	
int main()
{
	setlocale(0, "");
	p1();
	p2();
	int i;
	char c;
	wchar_t wch;
	bool b;
	float f;
	double d;

	printf("Количество байт для основных типов данных (без инициализации):\nint %d, char %d, wchar_t %d, bool %d, float %d, double %d, struct %d\n",
		sizeof(i), sizeof(c), sizeof(wch), sizeof(b), sizeof(f), sizeof(d), sizeof(pust));

	i = 10; c = '1'; wch = '100'; b = false; f = 3.14; d = 13.100012 + i + b;

	printf("Количество байт для основных типов данных (с инициализацией):\nint %d, char %d, wchar_t %d, bool %d, float %d, double %d, struct %d\n\n",
		sizeof(i), sizeof(c), sizeof(wch), sizeof(b), sizeof(f), sizeof(d), sizeof(pole));

	printf("typedef: вместо wchar_t используется rebkgke\n\n");

	error_ err_ = _ERR_WRITE;
	printf("Число байт для пустого enum %d и полного enum %d\n\n", sizeof(error), sizeof(error_));

	printf("Количество байт для хранения полей структуры: int %d, bool %d, wchar_t %d\n\n", sizeof(pust.pole1), sizeof(pust.x), sizeof(pust.abc));

	printf("Преобразовали double в int. Было %f; стало %d. Полученный тип данных: %s\n\n", d, int(d), typeid(int(d)).name());

	cout << "int + float + double + bool = " << typeid(i + f + d + b).name() << endl;
	cout << "int + char + wchar_t = " << typeid(i + c + wch).name() << endl;
	cout << "int + struct.int = " << typeid(i + pole.pole1).name() << endl;
	
	cout << "int + float + double = " << typeid(i + f + d).name() << endl;
}