#pragma once
#include <Windows.h>
#include <string>
#include "resource.h"
class Player
{
	std::string _name;
	int _hitPoint;
	int _magicPoint;
	int _attackPoint;
	int _defencePoint;
	static INT_PTR CALLBACK PlayerStatusDisplayProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	Player(std::string name, int hitPoint, int magicPoint, int attackPoint, int defencePoint);
	INT_PTR DialogBoxParam(_In_opt_ HWND hWndParent);
};

