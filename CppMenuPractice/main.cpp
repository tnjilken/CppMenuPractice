#pragma once
#include "Menu.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	Menu m;
	m.DialogBoxParam(nullptr);
	return 0;
}
