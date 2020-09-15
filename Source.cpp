#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class fighter {
public:
	int hp = 100;
	int Qattack(fighter);
	int Nattack(fighter);
	int Hattack(fighter);
	int heal(fighter);

};

int fighter::Qattack(fighter fighter)
{
	
	int hit;
	int dmg;
	srand(time(0));
	hit = 1 + rand() % 10;

	if (hit > 1) {
		dmg = (rand() % 3) + 3; 
		cout <<" ("<< dmg << " damage)!" << endl;
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
		dmg = (rand() % 7) + 6; 
		cout << " (" << dmg << " damage)!" << endl;
		return fighter.hp - dmg;
	}
	else {
		cout << " But he missed"<<endl;
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
		dmg = (rand() % 3) + 13; 
		cout << " (" << dmg << " damage)!" << endl;
		return fighter.hp - dmg;
	}
	else {
		cout << " But he missed"<<endl;
		return fighter.hp;
	}
}

int fighter::heal(fighter fighter)
{
	if (fighter.hp > 92)
		return fighter.hp;
	else
		return fighter.hp += 8;
}

int main()
{
	int enemy_move;
	int i = 0;
	fighter player, enemy;
	string player_name;
	string move;

	cout <<"enter player name" <<endl;
	cin >> player_name;

	cout <<"Okay "<<player_name<< " prepare to fight!!!\n" << endl;

	cout<<"INSTRUCTIONS\n1. Turn caps lock on\n2. Attacks(dmg,%): Q - quick(3-5 90%), N - normal(6-12 70%), H - heavy(13-15 50%), R - regenerate(+8hp)" << endl;
	cout << "3. The game ends when you or your enemy die" << endl;

	while (player.hp >= 0 && enemy.hp >= 0) {
		++i;
		srand(time(0));
		cout << endl;
		cout<<"------------------------------------"<<endl;
		cout << "Player Health:" << player.hp << "\t";
		cout << "Enemy Health:" << enemy.hp << "\n";
		cout << "------------------------------------" << endl;
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
		
		cout << "\n\n";
	}

	if (player.hp > enemy.hp)
		cout << "\n\n\n\n*********CONGRATULATIONS YOU WIN**********\n\n\n\n\n\n\n";
	else
		cout << "\n\n\n\n*********YOU ARE DEAD**********\n\n\n\n\n\n\n";
	return 0;
}



