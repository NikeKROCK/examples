// placeholderi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define lin cin >>
#define k bind(
#include <algorithm>
#include <functional>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace placeholders;
struct object {
	int some_int,another_int;
	int function(int a) {
		cout << a << "+" << another_int << "=" << a + another_int << '\n';
		return some_int;
	}
};
int main()
{
	SetConsoleOutputCP(1251);
	object a;
	int t;
	lin t;
 	a.some_int = t;
	a.another_int = 2;
	auto f=k&object::function ,a,_1);//auto f=bind(&object::function, a,_1
	if (f(2)==4) {
		cout << "это ЧоТыРе";
	}
	else {
		cout << "это не чОтЫрЕ";
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
