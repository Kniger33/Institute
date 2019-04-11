//g++ lab2.cpp -o lab2 -lgdi32

#include "pch.h"
#include <iostream>
#include "windows.h"
#include <tchar.h>
#include <string>
#include <cstdio>


BOOL RegClass(WNDPROC, LPCTSTR, UINT);
BOOL RegChildClass(WNDPROC, LPCTSTR, UINT);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;

char szMainClass[] = "MainClass";

int WINAPI WinMain(HINSTANCE hInst,
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow)
{
	MSG msg;
	HWND hwnd;
	hInstance = hInst;

	if (!RegClass(WndProc, szMainClass, COLOR_WINDOW)) { return FALSE; }
	
	hwnd = CreateWindow(szMainClass,
						"Main Window",
						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						0,
						0,
						hInstance,
						NULL);

	if (!hwnd) { return FALSE; }

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
{
	WNDCLASS wc;
	wc.style = 0;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = Proc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(brBackground + 1);
	wc.lpszMenuName = (LPCTSTR)NULL;
	wc.lpszClassName = szName;
	return (RegisterClass(&wc) != 0);
}

BOOL RegChildClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
{
	WNDCLASS wc;
	wc.style = 0;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = Proc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(brBackground + 1);
	wc.lpszMenuName = (LPCTSTR)NULL;
	wc.lpszClassName = szName;
	return (RegisterClass(&wc) != 0);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{	
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		LPVOID errNationalLang;
		LPVOID errEngLang;
		char res[64];

		RegChildClass(WndProc, szMainClass, COLOR_WINDOW);
		DWORD firstErrorCode = GetLastError();

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL,
						firstErrorCode,
						MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
						(LPTSTR) &errNationalLang,
						0,
						NULL);
		sprintf(res, "Code: %d Desc: %s", firstErrorCode, errNationalLang);
		MessageBox(NULL, (LPCTSTR)res, "FirstErrNational", MB_OK);

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL,
						firstErrorCode,
						MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT),
						(LPTSTR) &errEngLang,
						0,
						NULL);
		sprintf(res, "Code: %d Desc: %s", firstErrorCode, errEngLang);
		MessageBox(NULL, (LPCTSTR)res, "FirstErrEng", MB_OK);

		LocalFree(errNationalLang);
		LocalFree(errEngLang);

		break;
	}

	case WM_RBUTTONDOWN:
	{
		HINSTANCE hInst;

		HWND cHWND;
		LPVOID errNationalLang;
		LPVOID errEngLang;
		char res[64];
		
		cHWND = CreateWindow(szMainClass, 0, 0, 0, 0, 0, 0, cHWND, 0, 0, NULL);
		DWORD secErrCode = GetLastError();

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL,
						secErrCode,
						MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
						(LPTSTR)&errNationalLang,
						0,
						NULL);
		sprintf(res, "Code: %d Desc: %s", secErrCode, errNationalLang);
		MessageBox(NULL, (LPCTSTR)res, "SecErrNational", MB_OK);

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL,
						secErrCode,
						MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT),
						(LPTSTR)&errEngLang,
						0,
						NULL);
		sprintf(res, "Code: %d Desc: %s", secErrCode, errEngLang);
		MessageBox(NULL, (LPCTSTR)res, "SecErrEng", MB_OK);

		LocalFree(errNationalLang);
		LocalFree(errEngLang);

		break;
	}

	case WM_MBUTTONDOWN:
	{
		LPVOID errNationalLang;
		LPVOID errEngLang;
		char res[64];
		
		MessageBeep(0);
		DWORD secErrCode = GetLastError();

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			secErrCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&errNationalLang,
			0,
			NULL);
		sprintf(res, "Code: %d Desc: %s", secErrCode, errNationalLang);
		MessageBox(NULL, (LPCTSTR)res, "SecErrNational", MB_OK);

		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			secErrCode,
			MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT),
			(LPTSTR)&errEngLang,
			0,
			NULL);
		sprintf(res, "Code: %d Desc: %s", secErrCode, errEngLang);
		MessageBox(NULL, (LPCTSTR)res, "SecErrEng", MB_OK);

		LocalFree(errNationalLang);
		LocalFree(errEngLang);

		break;
	}

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

