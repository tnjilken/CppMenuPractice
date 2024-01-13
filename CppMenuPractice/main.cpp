#pragma once
#include "Menu.h"
#include "Play.h"

int main() {
	Menu m;
	const auto menuResult = m.DialogBoxParam(nullptr);
	switch (menuResult) {
		case IDC_BUTTON_START:
		{
			Play p(1,2);
			p.DialogBoxParam(nullptr);
			break;
		}
		default:
			break;
	}
	return 0;
}