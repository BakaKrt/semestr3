#include <iostream>
using namespace std;

typedef wchar_t WCH;

struct primer1 {
	int pole1 = 10;
	bool x = false;
	WCH abc = 'abc';
} pole;

struct PUST {
	int pole1; bool x; wchar_t abc;
} pust;

enum error {ERR_READ, ERR_WRITE, ERR_CONVERT};
enum error_{_ERR_READ = -1, _ERR_WRITE = -2, _ERR_CONVERT = 100 };

int main()
{
	setlocale(0, "");
	error oshibka = ERR_READ;
	int* pointer;
	printf("Количество байт для int64_t: %d\nКоличество байт для указателя на int %d\n", sizeof(int64_t), sizeof(pointer));
	int i;
	char c;
	WCH wch;
	bool b;
	float f;
	double d;

	printf("Количество байт для основных типов данных:\nint %d, char %d, wchar_t %d, bool %d, float %d, double %d, struct %d\n",
		sizeof(i), sizeof(c), sizeof(wch), sizeof(b), sizeof(f), sizeof(d), sizeof(pole));

	i = 10; c = '1'; wch = '100'; b = false; f = 3.14; d = 13.100012 + i + b;

	printf("typedef: вместо wchar_t используется WCH\n\n");

	error_ err_ = _ERR_WRITE;
	printf("Число байт для пустого enum %d и полного enum %d\n\n", sizeof(error), sizeof(error_));
	printf("ERR_CONVERT при перечислении (%d) и при задании нужного значения (%d)\n\n", ERR_CONVERT, _ERR_CONVERT);

	printf("Количество байт для хранения полей структуры: int %d, bool %d, wchar_t %d\n\n", sizeof(pust.pole1), sizeof(pust.x), sizeof(pust.abc));

	printf("Преобразовали double в int. Было %f; стало %d. Полученный тип данных: %s\n\n", d, int(d), typeid(int(d)).name());

	cout << "int + float + double + bool = " << typeid(i + f + d + b).name() << endl;
	cout << "int + char + wchar_t = " << typeid(i + c + wch).name() << endl;
	cout << "int + struct.int = " << typeid(i + pole.pole1).name() << endl;
	
	cout << "int + float + double = " << typeid(i + f + d).name() << endl;
}