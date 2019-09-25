//g++ lab2.cpp -o lab2 -lgdi32

#include "windows.h"
#include <stdio.h>
#include <iostream>

char szMainClass[] = "Main Class";
char text[1024];

BOOL RegClass(WNDPROC, LPCTSTR, UINT);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInst;
HWND edit1;
HWND edit2;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	HWND hwnd;
	MSG msg;

	hInst = hInstance;

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
		hInst,
		NULL);

	ShowWindow(hwnd, SW_SHOWDEFAULT);

	if (!hwnd)
	{
		MessageBox(NULL, "Window Creation Failed.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	HACCEL hAccel = LoadAccelerators(hInst, MAKEINTRESOURCE(0));

	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccel, &msg))
		{
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_KEYDOWN)
		{
			SendMessage(hwnd, WM_CHAR, msg.wParam, msg.lParam);
		}
	}

	return msg.wParam;
}

BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = Proc;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(brBackground + 1);
	wc.lpszMenuName = (LPCTSTR)NULL;
	wc.lpszClassName = szName;
	return (RegisterClass(&wc) != 0);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			RECT mainRect;
			GetWindowRect(hWnd, &mainRect);

			int width = mainRect.right - mainRect.left;
			int height = mainRect.bottom - mainRect.top;

			edit1 = CreateWindow("Edit",
				"",
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
				0,
				0,
				width / 2,
				height,
				hWnd,
				0,
				hInst,
				NULL);

			if (!edit1)
			{
				MessageBox(NULL, "Edit1 Creation Failed.", "Error", MB_OK | MB_ICONERROR);
				return FALSE;
			}

			edit2 = CreateWindow("Edit",
				"",
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
				width / 2,
				0,
				width,
				height,
				hWnd,
				0,
				hInst,
				NULL);

			if (!edit2)
			{
				MessageBox(NULL, "Edit2 Creation Failed.", "Error", MB_OK | MB_ICONERROR);
				return FALSE;
			}		
				
			break;
		}
		
		case WM_CHAR:
		{
			int strLen = 0;			
			char s = (TCHAR)wParam;	
			char *str = (char*)malloc(sizeof(2));
			*(str) = s;
			*(str + 1) = '\0';			
		
			if (GetFocus() == edit1)
			{
				SendMessage(edit2, EM_REPLACESEL, (WPARAM)FALSE, (LPARAM)str);
				SendMessage(edit2, EM_SETSEL, (WPARAM)strLen, (LPARAM)strLen);
				SendMessage(edit2, EM_SETSEL, 0,-1);
				SendMessage(edit2, EM_SETSEL, -1, -1);
			}
			else
			{
				SendMessage(edit1, EM_REPLACESEL, (WPARAM)FALSE, (LPARAM)str);
				SendMessage(edit1, EM_SETSEL, (WPARAM)strLen, (LPARAM)strLen);
				SendMessage(edit1, EM_SETSEL, 0, -1);
				SendMessage(edit1, EM_SETSEL, -1, -1);
			}

			strLen += 1;

			return 0;
		}
		
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
}


