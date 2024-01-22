#pragma once
#include "Menu.h"
#include "Play.h"
#include "windowsx.h"

INT_PTR Menu::MenuProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_COMMAND:
		switch (wParam) {
		case IDC_BUTTON_START:
		{
			Button_Enable(GetDlgItem(hWnd, IDC_BUTTON_START), FALSE);
			Button_Enable(GetDlgItem(hWnd, IDC_BUTTON_STOP), FALSE);

			Play p(1, 2);
			p.DialogBoxParam(nullptr);

			Button_Enable(GetDlgItem(hWnd, IDC_BUTTON_START), TRUE);
			Button_Enable(GetDlgItem(hWnd, IDC_BUTTON_STOP), TRUE);

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

