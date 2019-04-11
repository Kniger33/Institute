// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <windows.h>
#include <cmath>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

EXPORT void DrawLine(HDC hdc, int left, int top, int right, int bottom)
{
	MoveToEx(hdc, left, top, NULL);
	LineTo(hdc, right, bottom);
}

EXPORT void DrawCircle(HDC hdc, int x1, int y1, int x2, int y2)
{
	int left = 0, top = 0, right = 0, bottom = 0;
	int longSide = 0, shortSide = 0;

	if (abs(x1 - x2) > abs(y1 - y2))
	{
		longSide = abs(x1 - x2);
		shortSide = abs(y1 - y2);
		int r = shortSide / 2;
		int delta = ((longSide / 2) - r);

		if (x1 > x2)
		{
			if (y1 > y2)
			{
				top = y2;
				bottom = y1;
			}
			else if (y2 >= y1)
			{
				top = y1;
				bottom = y2;
			}
			left = x2 + delta;
			right = x1 - delta;
		}
		else if (x2 >= x1)
		{
			if (y1 > y2)
			{
				top = y2;
				bottom = y1;
			}
			else if (y2 >= y1)
			{
				top = y1;
				bottom = y2;
			}
			left = x1 + delta;
			right = x2 - delta;
		}
	}
	else
	{
		longSide = abs(y1 - y2);
		shortSide = abs(x1 - x2);
		float r = shortSide / 2;
		float delta = ((longSide / 2) - r);

		if (x1 > x2)
		{
			if (y1 > y2)
			{
				left = x2;
				right = x1;
				top = y2 + delta;
				bottom = y1 - delta;
			}
			else if (y2 >= y1)
			{
				left = x1;
				right = x2;
				top = y1 + delta;
				bottom = y2 - delta;
			}

		}
		else if (x2 > x1)
		{
			if (y1 > y2)
			{
				top = y2 + delta;
				bottom = y1 - delta;
			}
			else if (y2 >= y1)
			{
				top = y1 + delta;
				bottom = y2 - delta;
			}
			left = x1;
			right = x2;
		}
	}

	Ellipse(hdc, left, top, right, bottom);
}

