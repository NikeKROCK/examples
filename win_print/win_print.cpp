#ifndef UNICODE 
#define UNICODE 
#endif // !

#include <Windows.h>

//CALLBACK - сам чистит стек
//HINSTANCE - указатель на модуль
//PWSTR - point to wide string - стандартные аргументы
//int nCmdShow - вывод окна

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow) 
{
	MSG msg{};//сообщение
	HWND hwnd{};//дискриптор окна
	WNDCLASSEX wc{sizeof(WNDCLASSEX)};//хар-ки окна
	//доп выделение памяти в классе окна
	wc.cbClsExtra = 0;//
	wc.cbWndExtra = 0;//
	//кисти дескриптор
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	//дескриптор курсора
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	//дескриптор иконки
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

	wc.hInstance = hInstance;
	//обработка сообщений из msg{} (работает в лямбде) (1-дескриптор окна,2-код сообщения,3,4- указатели), возвращает результат
	wc.lpfnWndProc = [](HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lparam)->LRESULT
	{
		switch (uMsg)
		{
		 case WM_CREATE:
		 {
			 MessageBox(hwnd, L"Message", L"OKey,sssssss", MB_ICONINFORMATION);
		 }
		 return 0;
		 case WM_DESTROY:
		 {
			 PostQuitMessage(EXIT_SUCCESS);
		 }
		 return 0;
		}
		return DefWindowProc(hwnd, uMsg, wParam, lparam);
	};
	//имя класса
	wc.lpszClassName = L"MyAppClass";
	//указатель на имя меню
	wc.lpszMenuName = nullptr;
	//стиль окна
	wc.style = CS_VREDRAW | CS_HREDRAW;
	//если не зарегистрированна, выйти с ошибкой
	if (!RegisterClassEx(&wc))
		return EXIT_FAILURE;//msdn
	//создать окно
	if (hwnd = CreateWindow(wc.lpszClassName, L"Заголовок", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, wc.hInstance, nullptr); hwnd == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		//расшифровать
		TranslateMessage(&msg);
		//перенести в процедуру на обработку
		DispatchMessage(&msg);

	}
	return static_cast<int>(msg.wParam);
}
int main() 
{
	return 0;
}