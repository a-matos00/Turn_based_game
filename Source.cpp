#include<iostream>
#include<cstdlib>
#include<ctime>
#include "fighter.h"
#include "attacks.h"
#include "enemies.h"

using namespace std;

int main()
{
	int enemy_move;
	int i = 0, lvl = 1, n = 1;
	fighter player, enemy;
	string player_name;
	string move;
	string upgrade;
	enemy.hp = 10;
	cout <<"enter player name" <<endl;
	cin >> player_name;

	cout <<"Okay "<<player_name<< " prepare to fight!!!\n" << endl;

	cout<<"INSTRUCTIONS\n1. Turn caps lock on\n2. Attacks(dmg,%): Q - quick(3-5 90%), N - normal(6-12 70%), H - heavy(13-15 50%), R - regenerate(+8hp)" << endl;
	cout << "3. The game ends when you or your enemy die" << endl;

	while (player.hp > 0) {
		++i;
		srand(time(0));
		cout << endl;
		cout<<"------------------------------------------------"<<endl;
		cout << "Player Health:" << player.hp << "\t";
		cout << "Enemy Health:" << enemy.hp << "\n";
		cout << "----------------------------------------------" << endl;
		cout <<i<<".TURN "<< "Choose your next move:" << endl;
		cin >> move;
		while (move != "Q" && move != "N" && move != "H" && move != "R") {
			cout << "WRONG INPUT!!!" << endl;
			cout << "Attacks(dmg,%): Q - quick(3-5 90%), N - normal(6-12 70%, H - heavy(13-15 50%), R(+20hp) - regenerate" << endl;
			cin >> move;
		}
		if (move == "Q") {
			cout << player_name << " did a quick attack!";
			enemy.hp = player.Qattack(enemy);
		}

		if (move == "N") {
			cout << player_name << " did a normal attack!";
			enemy.hp = player.Nattack(enemy);
		}

		if (move == "H") {
			cout << player_name << " did a heavy attack!";
			enemy.hp = player.Hattack(enemy);
		}

		if (move == "R") {
			cout << player_name << " Regenereated HP!"<<endl;
			player.hp = player.heal(player);
		}

		if (enemy.hp > 0) {
			srand(time(0));
			enemy_move = ((rand() % 4) + 1);

			if (enemy_move == 1) {
				cout << "Enemy did a quick attack";
				player.hp = enemy.Qattack(player);
			}
			if (enemy_move == 2) {
				cout << "Enemy did a normal attack";
				player.hp = enemy.Nattack(player);

			}
			if (enemy_move == 3) {
				cout << "Enemy did a heavy attack";
				player.hp = enemy.Hattack(player);
			}
			if (enemy_move == 4) {
				cout << "Enemy regenerated HP";
				enemy.hp = enemy.heal(enemy);

			}
		}
		else {
			cout << "\n\n########################YOU HAVE DEFEATED THE " <<n<< ". ENEMY############################\n\n"<<endl;
			lvl++;
			n++;
			enemy.hp = 10 * lvl;
			enemy.dmg_up += 1;
			cout << "Choose upgrade: D for +1 dmg, H for +1 HP regeneration" << endl;
			cin >> upgrade;
			while (upgrade != "D" && upgrade != "H") {
				cout << "WRONG INPUT!!!!!!" << endl;
				cout << "Choose upgrade: D for +1 dmg, H for +1 to HP regeneration" << endl;
				cin >> upgrade;
			}
			if (upgrade == "D") {
				player.dmg_up += 1;
				cout << "Damage bonus: +" << player.dmg_up << endl;
			}
			if (upgrade == "H") {
				player.reg_rate += 1;
				cout << "Regeneration rate: +" << player.reg_rate + 8 << endl;
			}
		}
		cout << "\n\n";
	}

		cout << "\n\n\n\n*********YOU ARE DEAD ON THE "<< n <<". LEVEL**********\n\n\n\n\n\n\n";
	return 0;
}



