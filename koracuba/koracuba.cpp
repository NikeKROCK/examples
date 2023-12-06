// koracuba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<chrono>
#include<time.h>
#include <iostream>

int main()
{
   
    setlocale(LC_ALL, "rus");
    int fir, sec,ans;
    std::cin >> fir >> sec;
    int a, b, c, d, ac, bd, pr;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        a = fir / 100;
        b = fir % 100;
        c = sec / 100;
        d = sec % 100;
        ac = a * c;
        bd = b * d;
        pr = ((a + b) * (c + d)) - ac - bd;
        ans = ac * 10000 + pr * 100 + bd;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "корацуба" << duration.count() << " с " << ans << '\n';
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        ans = fir * sec;
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "классика" << duration.count() << " с " << ans << '\n';
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
