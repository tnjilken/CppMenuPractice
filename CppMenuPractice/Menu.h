#pragma once
#include <Windows.h>
#include "resource.h"

class Menu {
	static INT_PTR CALLBACK MenuProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	INT_PTR DialogBoxParam(_In_opt_ HWND hWndParent);
};
