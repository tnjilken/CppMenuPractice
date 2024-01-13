#pragma once
#include <Windows.h>
#include "resource.h"
class Play
{
	int _xPosition;
	int _yPosition;
	static INT_PTR CALLBACK PlayProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	Play(int xPotision, int yPosition);
	INT_PTR DialogBoxParam(_In_opt_ HWND hWndParent);
};