#pragma once
#include<iostream>

using namespace std;
int fighter::Qattack(fighter fighter)
{
	int hit;
	int dmg;
	srand(time(0));
	hit = 1 + rand() % 10;

	if (hit > 1) {
		dmg = ((rand() % 3) + 3) + dmg_up; //% a + b => 3 is min, a - 1 is max
		cout << " (" << dmg << " damage)!" << endl;
		return fighter.hp - dmg;
	}
	else {
		cout << " But he missed" << endl;
		return fighter.hp;
	}
}

int fighter::Nattack(fighter fighter)
{
	int hit;
	int dmg;
	srand(time(0));
	hit = 1 + rand() % 10;

	if (hit > 2) {
		dmg = ((rand() % 7) + 6) + dmg_up; //% a + b => 3 is min, a - 1 is max
		cout << " (" << dmg << " damage)!" << endl;
		return fighter.hp - dmg;
	}
	else {
		cout << " But he missed" << endl;
		return fighter.hp;
	}
}

int fighter::Hattack(fighter fighter)
{
	int hit;
	int dmg;
	srand(time(0));
	hit = 1 + rand() % 10;

	if (hit > 5) {
		dmg = ((rand() % 3) + 13) + dmg_up; //% a + b => 3 is min, a - 1 is max
		cout << " (" << dmg << " damage)!" << endl;
		return fighter.hp - dmg;
	}
	else {
		cout << " But he missed" << endl;
		return fighter.hp;
	}
}

int fighter::heal(fighter fighter)
{
	if (fighter.hp > 92)
		return fighter.hp;
	else
		return fighter.hp += (8 + reg_rate);
}