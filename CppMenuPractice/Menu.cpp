#pragma once
#include "Menu.h"
#include "Play.h"

INT_PTR Menu::MenuProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_COMMAND:
		switch (wParam) {
		case IDC_BUTTON_START:
		{
			Play p(1, 2);
			p.DialogBoxParam(nullptr);
			return true;
		}
		case IDC_BUTTON_STOP:
		case IDCANCEL:
			EndDialog(hWnd, IDCANCEL);
			return true;
		default:
			return false;
		}
	default:
		return false;
	}
}

INT_PTR Menu::DialogBoxParam(HWND hWndParent)
{
	return ::DialogBoxParam(
		nullptr,
		MAKEINTRESOURCE(IDD_DIALOG_MENU),
		hWndParent,
		MenuProcedure,
		0);
}

