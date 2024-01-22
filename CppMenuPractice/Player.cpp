#include "Player.h"

INT_PTR Player::PlayerStatusDisplayProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
	{
		SetWindowLongPtr(hWnd, GWLP_USERDATA, lParam);
		Player* player = reinterpret_cast<Player*> (GetWindowLongPtr(hWnd, GWLP_USERDATA));
		SetDlgItemInt(hWnd, IDC_EDIT_PLAYER_HITPOINT, player->_hitPoint, false);
		SetDlgItemInt(hWnd, IDC_EDIT_PLAYER_MAGICPOINT, player->_magicPoint, false);
		SetDlgItemInt(hWnd, IDC_EDIT_PLAYER_ATTACKPOINT, player->_attackPoint, false);
		SetDlgItemInt(hWnd, IDC_EDIT_PLAYER_DEFENCEPOINT, player->_defencePoint, false);
	}
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
		PlayerStatusDisplayProcedure,
		LPARAM(this));
}