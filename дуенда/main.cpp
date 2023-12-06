#include"resource.h"
#include <thread>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <inaddr.h>
#include <stdio.h>
#include "stdafx.h"
//#include <vector>
//#include<fstream>
//#include<cstdlib>
//#include<vector>
//#include <sstream>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "ws2_32.lib")

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{
	case WM_CTLCOLORSTATIC:
	{
		HDC hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(255, 255, 255));
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LONG)CreateSolidBrush(RGB(150, 0, 150));
	}
	case WM_CTLCOLORDLG:
	{
		return (LONG)CreateSolidBrush(RGB(30, 30, 30));
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HBITMAP hBitmap;
		BITMAP bm;
		HDC hDC;
		HDC hMemDC;

		hDC = GetDC(hwnd);
		hMemDC = CreateCompatibleDC(hDC);
		hBitmap = (HBITMAP)LoadImage(NULL, L"nf.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		GetObject(hBitmap, sizeof(BITMAP), &bm);
		SelectObject(hMemDC, hBitmap);
		BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);
		DeleteDC(hMemDC);
		ReleaseDC(hwnd, hDC);
		DeleteObject(hBitmap);
		ReleaseDC(hwnd, hDC);
		UpdateWindow(hwnd);
		break;
	}
	case WM_INITDIALOG:
	{
		SetWindowText(hwnd, L"gigaChat");
		return true;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		
		}
		return FALSE;
	case WM_CLOSE:
	{
		EndDialog(hwnd, 0);
		//delete[] IP;
		//delete[] PORT;
		//delete[] Nikname;
		return TRUE;
		break;
	}
	}
	return FALSE;
	}
	return FALSE;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
	int ret = DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
	return ret;
}