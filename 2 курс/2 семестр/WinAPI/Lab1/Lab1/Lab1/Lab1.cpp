//gcc Lab1.cpp -o lab1 -lgdi32

#include "windows.h"
#include <tchar.h>
#include <string>
#include <cstdio>


BOOL RegClass(WNDPROC, LPCTSTR, UINT);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndPopup(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;

HWND childHWND;

char szMainClass[] = "MainClass";
char szPopupClass[] = "PopusClass";
char szTitle[] = "Lab1";

int xMouse, yMouse;

int WINAPI WinMain(HINSTANCE hInst,
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow)
{
	MSG msg;
	HWND hwnd;
	hInstance = hInst;

	if (!RegClass(WndProc, szMainClass, COLOR_WINDOW)) { return FALSE; }
	if (!RegClass(WndPopup, szPopupClass, COLOR_BTNFACE)) { return FALSE; }

	hwnd = CreateWindow(szMainClass,
						szTitle,
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

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{			
	int width, height;	

	int childWidth = 200;
	int childHeight = 200;

	RECT mainRect;	

	GetWindowRect(hwnd, &mainRect);
	width = mainRect.right - mainRect.left;
	height = mainRect.bottom - mainRect.top;

	switch (msg)
	{
		case WM_LBUTTONDOWN:
		{	
			xMouse = LOWORD(lParam);
			yMouse = HIWORD(lParam);
			
			if (IsWindow(childHWND))
			{				
				SendMessage(childHWND, WM_CLOSE, 0, 0);
			}
			
			childHWND = CreateWindow(szPopupClass,
									"Child Window",
									WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CHILD,
									xMouse,
									yMouse,
									childWidth,
									childHeight,
									hwnd,
									0,
									hInstance,
									NULL);
			
			return 0;
		}	

		case WM_RBUTTONDOWN: 
		{
			int childWidth, childHeight;
			
			RECT childRect;
			RECT newPos;

			childHWND = FindWindowEx( hwnd, NULL, szPopupClass, "Child Window");

			GetWindowRect(childHWND, &childRect);
			childWidth = childRect.right - childRect.left;
			childHeight = childRect.bottom - childRect.top;

			int newXPos = LOWORD(lParam);
			int newYPos = HIWORD(lParam);

			if (newXPos <= (width / 2) && newYPos <= (height / 2))
			{
				newPos.left = width / 2 + width / 4 - childWidth / 2;
				newPos.top = height / 2 + height / 4 - childHeight / 2;
			}
			else if (newXPos <= width / 2 && newYPos > height / 2)
			{
				newPos.left = width / 2 + width / 4 - childWidth / 2;
				newPos.top = height / 2 - height / 4 - childHeight / 2;
			}
			else if (newXPos > width / 2 && newYPos <= height / 2)
			{
				newPos.left = width / 2 - width / 4 - childWidth / 2;
				newPos.top = height / 2 + height / 4 - childHeight / 2;
			}
			else if (newXPos > width / 2 && newYPos > height / 2)
			{
				newPos.left = width / 2 - width / 4 - childWidth / 2;
				newPos.top = height / 2 - height / 4 - childHeight / 2;
			}
			else
			{
				newPos.left = width / 2 - childWidth / 2;
				newPos.top = height / 2 - childHeight / 2;
			}			
			
			MoveWindow(childHWND, newPos.left, newPos.top, childWidth, childHeight, SWP_NOSIZE);

			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}		
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK WndPopup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch (msg)
	{
		case WM_PAINT:
		{
			char str[64];
			sprintf(str, "X: %d, Y: %d", xMouse, yMouse);

			PAINTSTRUCT ps;

			HDC hdc = BeginPaint(hwnd, &ps);
			TextOutA(hdc, 50, 50, str, strlen(str));
			EndPaint(hwnd, &ps);
			
			return 0;
		}

		case WM_DESTROY: 
		{
			SendMessage(childHWND, WM_CLOSE, 0, 0);
			return 0;
		}	
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}



