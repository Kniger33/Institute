#include <windows.h>
#include <string>
#include <cstdio>
#include <TCHAR.h>

BOOL RegClass(WNDPROC, LPCTSTR, UINT);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndPopup(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;
char szMainClass[] = "MainClass";
char szPopupClass[] = "PopupClass";
char szTitle[] = "Test";
HWND child_window = nullptr;
HWND hwnd;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR IpszCmdLine,
	int nCmdShow)
{
	MSG msg;
	
	hInstance=hInst;
	if (!RegClass(WndProc, szMainClass, COLOR_WINDOW))
		return FALSE;
	if (!RegClass(WndPopup, szPopupClass, COLOR_BTNFACE))
		return FALSE;
	hwnd = CreateWindow(szMainClass, szTitle,
		WS_OVERLAPPEDWINDOW|WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		0, 0, hInstance, NULL);
	if (!hwnd) return FALSE;
	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
	return msg.wParam;
}

BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
{
	WNDCLASS wc;
	wc.style = wc.cbClsExtra=wc.cbWndExtra = 0;
	wc.lpfnWndProc = Proc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground=(HBRUSH)(brBackground + 1);
	wc.lpszMenuName = (LPCTSTR)NULL;
	wc.lpszClassName = szName;
	return (RegisterClass(&wc) !=0);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam,
	LPARAM lParam)
{
	int x, y, width, height;
POINT pt, ptt;
RECT client_rect;
//hwnd = (HWND) wParam;       // дескриптор окна с курсором 
x = LOWORD(lParam); //узнаём координаты
y = HIWORD(lParam);

GetCursorPos(&pt);
GetClientRect(hwnd,&client_rect);


	switch(msg){
		case WM_DESTROY: 
		{
			PostQuitMessage(0);
			return 0;
		}
		case WM_LBUTTONDOWN:

				{

					if (IsWindow(child_window))
						SendMessage(child_window,WM_CLOSE,0,0);

						child_window = CreateWindow(szPopupClass, "Coordinates", WS_CHILD|WS_SYSMENU|WS_CAPTION|WS_VISIBLE,

						x, y, 210, 100, hwnd, 0, hInstance, NULL);
						PAINTSTRUCT ps;
		            char buffer[64];
					sprintf(buffer, "Coordinates - X: %d, Y: %d\n",  x , y );
		            HDC hdc = BeginPaint(child_window, &ps);

		            TextOut(hdc, 10, 10, TEXT(buffer),strlen(buffer));

		            EndPaint(child_window, &ps);
		            ReleaseDC(child_window, hdc);

				break;
				}

				default:
					return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WndPopup(HWND hwnd, UINT msg, WPARAM wParam,
 LPARAM lParam)
{
	return DefWindowProc(hwnd, msg, wParam, lParam);
}