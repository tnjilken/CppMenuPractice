#pragma once
#include "Play.h"
#include "Player.h"

INT_PTR Play::PlayProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG: {
		SetWindowLongPtr(hWnd, GWLP_USERDATA, lParam);
		Play* p = reinterpret_cast<Play*> (GetWindowLongPtr(hWnd, GWLP_USERDATA));
		SetDlgItemInt(hWnd, IDC_EDIT_X_POSITION, p->_xPosition, true);
		SetDlgItemInt(hWnd, IDC_EDIT_Y_POSITION, p->_yPosition, true);
		return true;
	}
	case WM_COMMAND:
		switch (wParam) {
		case IDC_BUTTON_UP:
		{
			Play* p = reinterpret_cast<Play*> (GetWindowLongPtr(hWnd, GWLP_USERDATA));
			p->_yPosition++;
			SetDlgItemInt(hWnd, IDC_EDIT_Y_POSITION, p->_yPosition, true);
			break;
		}
		case IDC_BUTTON_DOWN:
		{
			Play* p = reinterpret_cast<Play*> (GetWindowLongPtr(hWnd, GWLP_USERDATA));
			p->_yPosition--;
			SetDlgItemInt(hWnd, IDC_EDIT_Y_POSITION, p->_yPosition, true);
			break;
		}
		case IDC_BUTTON_RIGHT:
		{
			Play* p = reinterpret_cast<Play*> (GetWindowLongPtr(hWnd, GWLP_USERDATA));
			p->_xPosition++;
			SetDlgItemInt(hWnd, IDC_EDIT_X_POSITION, p->_xPosition, true);
			break;
		}
		case IDC_BUTTON_LEFT:
		{
			Play* p = reinterpret_cast<Play*> (GetWindowLongPtr(hWnd, GWLP_USERDATA));
			p->_xPosition--;
			SetDlgItemInt(hWnd, IDC_EDIT_X_POSITION, p->_xPosition, true);
			break;
		}
		case IDC_BUTTON_PLAY_STOP:
			EndDialog(hWnd, IDC_BUTTON_PLAY_STOP);
			return true;
		case IDC_BUTTON_PLAY_STATUS:
		{
			Player player("Player", 100, 110, 120, 130);
			player.DialogBoxParamW(hWnd);
			return true;
		}
		default:
			return false;
		}
	default:
		return false;
	}
}

Play::Play(int xPosition, int yPosition)
{
	_xPosition = xPosition;
	_yPosition = yPosition;
}

INT_PTR Play::DialogBoxParam(HWND hWndParent)
{
	return ::DialogBoxParam(
		nullptr,
		MAKEINTRESOURCE(IDD_DIALOG_PLAY),
		hWndParent,
		PlayProcedure,
		LPARAM(this));
}
