#include "Player.h"

INT_PTR Player::PlayerStatusProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
		// SetDlgItemInt(hWnd, IDC_EDIT_PLAYER_NAME, _name, true);
	case WM_COMMAND:
		switch (wParam) {
		case IDC_BUTTON_PLAYER_CLOSE:
			EndDialog(hWnd, IDC_BUTTON_PLAYER_CLOSE);
			return true;
		default:
			return false;
		}
	default:
		return false;
	}
}

Player::Player(std::string name, int hitPoint, int magicPoint, int attackPoint, int defencePoint)
{
	_name = name;
	_hitPoint = hitPoint;
	_magicPoint = magicPoint;
	_attackPoint = attackPoint;
	_defencePoint = defencePoint;
}

INT_PTR Player::DialogBoxParam(HWND hWndParent)
{
	return ::DialogBoxParam(
		nullptr,
		MAKEINTRESOURCE(IDD_DIALOG_STATUS),
		hWndParent,
		PlayerStatusProcedure,
		LPARAM(this));
}
