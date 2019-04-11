#ifndef _DLLTEST_H_
#define _DLLTEST_H_ 

#include <stdio.h>
#include <windows.h> 

extern "C" __declspec(dllexport) void CALLBACK DrawLine(HDC, int, int, int, int);

#endif