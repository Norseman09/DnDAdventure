#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <vector>
using namespace std;
#ifndef DnDAdventure_H
#define DnDAdventure_H

//This is my header file where I place all my prototype functions for use.
// this allows me to declare a global variable as external so the other cource files can use the values, prevents compile error.
extern int PLAYER_MAX_HP;
extern int ENEMY_MAX_HP;
using namespace std;
// Here are all my different fucntion prototypes. These allow the control over the combat of my interactive game.
int roll(); //player dice roll
int enemyRoll();//enemy dice roll
int score();//number shown on dice for combat
int enemyScore();//enemy's number shown for combat
int showEnemyHP(int enemyHP, int playerAttack); //allows me to take away health during attacks
int showPlayerHP(int playerHP, int enemyAttack);//same as above against the player
int playerCrit(int playerHP);
int enemyCrit(int enemyHP);

class GameStructure {
public:

protected:

private:

};

class Character : GameStructure {
public:
	string name;
protected:

private:

};


class Player_Class : Character
{
public:
	int m_PLAYER_MAX_HEALTH;
	// These are my pointers that point to the players current health when typed. 
	const int* pPHealth = &PLAYER_MAX_HP;
	const int* pEHealth = &ENEMY_MAX_HP;
	// This is the function prototype for greeting the player. 
	void Greeting() 
	{

		cout << "You are an adventurer eagerly searching for the lost treasure of the Dragon Lich.\n";
		cout << "Your health is at " << *pPHealth << "HP and you only have ONE life. So make it count.\n"; // This line has dereferenced pointers declared in the header file.
		cout << "As you approach the suspected layer of the moster. You notice a skeleton guarding the entrance.\n";
		cout << "You decide to practice your swordsmanship and move forward to fight it.\n";
	}
};
class Skeleton_Class : Character
{
public:
	int m_ENEMY_MAX_HEALTH;
	// This is the function prototype for greeting the player.
	void Taunt() {

		cout << "Human! You have no chance against me! My health is " << m_ENEMY_MAX_HEALTH << "HP.\n";
	}
};


#endif