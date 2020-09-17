#pragma once

class fighter {
public:
	int hp = 100;
	int dmg_up = 0;	//upgradeable damage stat
	int reg_rate = 0;	//upgradeable regeneration rate
	int Qattack(fighter);
	int Nattack(fighter);
	int Hattack(fighter);
	int heal(fighter);
};