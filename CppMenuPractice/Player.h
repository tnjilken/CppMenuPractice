#pragma once
#include <string>
class Player
{
	std::string _name;
	int _hitPoint;
	int _magicPoint;
	int _attackPoint;
	int _defencePoint;
public:
	Player(int name, int hitPoint, int magicPoint, int attackPoint, int defencePoint);
};

