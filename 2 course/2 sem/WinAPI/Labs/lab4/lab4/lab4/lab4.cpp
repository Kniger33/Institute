//g++ lab2.cpp -o lab2 -lgdi32

#include <windows.h>

#define ID_LINE_BUTTON 101
#define ID_SQUARE_BUTTON 102
#define ID_CIRCLE_BUTTON 103

#define ID_RED_BUTTON 104
#define ID_GREEN_BUTTON 105
#define ID_BLUE_BUTTON 106

BOOL RegClass(WNDPROC, LPCTSTR, UINT);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndPaintProc(HWND, UINT, WPARAM, LPARAM);

char szMainClass[] = "MainClass";
char szPaintClass[] = "PaintClass";
char text[1024];

bool isMousePressed = false;
int xMouse1, yMouse1;
int xMouse2, yMouse2;

bool isLine, isSquare, isCircle;
bool isRed, isGreen, isBlue;

HINSTANCE hInst;

HWND paintHwnd;
HWND btnLine, btnSquare, btnCircle;
HWND btnRed, btnGreen, btnBlue;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	
	MSG msg;
	HWND hwnd;

	hInst = hInstance;

	if (!RegClass(WndProc, szMainClass, COLOR_WINDOW)) { return FALSE; }
	if (!RegClass(WndPaintProc, szPaintClass, COLOR_WINDOW)) { return FALSE; }

	hwnd = CreateWindow(szMainClass,
		"Main Window",
		WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		0,
		0,
		hInst,
		NULL);

	if (!hwnd)
	{
		MessageBox(NULL, "Window Creation Failed.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}

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
	RECT mainRect;
	GetWindowRect(hWnd, &mainRect);

	int width = mainRect.right - mainRect.left;
	int height = mainRect.bottom - mainRect.top;

	switch (msg)
	{		
		case WM_CREATE:
		{			
			isLine = false;
			isSquare = false;
			isCircle = false;
			isRed = false;
			isGreen = false;
			isBlue = false;

			paintHwnd = CreateWindow(szPaintClass, "",
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				150, 0,
				width - 150, height,
				hWnd, 0, hInst, NULL);

			btnLine = CreateWindow("button", "Line",
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
				5, 10,
				70,	20,
				hWnd, (HMENU)ID_LINE_BUTTON, hInst,	NULL
			);

			btnSquare = CreateWindow("button", "Square",
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				5, 40,
				70, 20,
				hWnd, (HMENU)ID_SQUARE_BUTTON, hInst, NULL
			);

			btnCircle = CreateWindow("button", "Circle",
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				5, 70,
				70, 20,
				hWnd, (HMENU)ID_CIRCLE_BUTTON, hInst, NULL
			);

			btnRed = CreateWindow("button", "Red",
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
				5, 110,
				70, 20,
				hWnd, (HMENU)ID_RED_BUTTON, hInst, NULL
			);

			btnGreen = CreateWindow("button", "Green",
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				5, 140,
				70, 20,
				hWnd, (HMENU)ID_GREEN_BUTTON, hInst, NULL
			);

			btnBlue = CreateWindow("button", "Blue",
				WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
				5, 170,
				70, 20,
				hWnd, (HMENU)ID_BLUE_BUTTON, hInst, NULL
			);

			break;
		}		

		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case ID_LINE_BUTTON:
			{
				isLine = true;
				isSquare = false;
				isCircle = false;

				break;
			}
			case ID_SQUARE_BUTTON:
			{
				isLine = false;
				isSquare = true;
				isCircle = false;
				break;
			}
			case ID_CIRCLE_BUTTON:
			{
				isLine = false;
				isSquare = false;
				isCircle = true;
				break;
			}
			case ID_RED_BUTTON:
			{
				isRed = true;
				isGreen = false;
				isBlue = false;
				break;
			}
			case ID_GREEN_BUTTON:
			{
				isRed = false;
				isGreen = true;
				isBlue = false;
				break;
			}
			case ID_BLUE_BUTTON:
			{
				isRed = false;
				isGreen = false;
				isBlue = true;
				break;
			}
			default:
				break;
			}
			break;
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

typedef void(__cdecl *DrawLineType)(HDC, int, int, int, int);
typedef void(__cdecl *DrawCircleType)(HDC, int, int, int, int);

LRESULT CALLBACK WndPaintProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HINSTANCE hLib = NULL;
	hLib = ::LoadLibrary("myDLL.DLL");

	if (hLib == NULL)
	{
		MessageBox(NULL, "DLL Loading Failed.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}
	
	FARPROC DrawLine = GetProcAddress((HMODULE)hLib, "DrawLine");
	FARPROC DrawCircle = GetProcAddress((HMODULE)hLib, "DrawCircle");

	if (!DrawLine)
	{
		MessageBox(NULL, "DLL Load2 Failed.", "Error", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	switch (msg)
	{
		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);			
			EndPaint(hWnd, &ps);			
			break;
		}

		case WM_LBUTTONDOWN:
		{			
			xMouse1 = LOWORD(lParam);
			yMouse1 = HIWORD(lParam);
			isMousePressed = true;

			break;
		}

		case WM_LBUTTONUP:
		{
			if (isMousePressed)
			{
				xMouse2 = LOWORD(lParam);
				yMouse2 = HIWORD(lParam);
				
				hdc = GetDC(hWnd);							
				HPEN pen;
				
				if (isRed)
				{
					pen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
								
				}
				if (isGreen)
				{
					pen = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));										
				}
				if (isBlue)
				{
					pen = CreatePen(PS_SOLID, 0, RGB(0, 0, 255));					
				}

				SelectObject(hdc, pen);
				
				if (isLine)
				{					
					((DrawLineType)DrawLine)(hdc, xMouse1, yMouse1, xMouse2, yMouse2);
				}
				if (isSquare)
				{
					Rectangle(hdc, xMouse1, yMouse1, xMouse2, yMouse2);
				}
				if (isCircle)
				{
					((DrawCircleType)DrawCircle)(hdc, xMouse1, yMouse1, xMouse2, yMouse2);
				}

				ReleaseDC(hWnd, hdc);
				DeleteObject(pen);
				isMousePressed = false;
			}

			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		
	}
	FreeLibrary(hLib);
}


