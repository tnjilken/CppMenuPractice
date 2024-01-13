#pragma once
#include "Menu.h"

INT_PTR Menu::MenuProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_COMMAND:
		switch (wParam) {
		case IDC_BUTTON_START:
			EndDialog(hWnd, IDC_BUTTON_START);
			return true;
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
	return ::DialogBoxParamW(
					nullptr,
					MAKEINTRESOURCE(IDD_DIALOG_MENU),
					hWndParent,
					MenuProcedure,
					0);
}

