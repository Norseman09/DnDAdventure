#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <vector>
using namespace std;
#ifndef DnDAdventure_H
#define DnDAdventure_H

//This is my header file where I place all my prototype functions for use.
// this allows me to declare a global variable as external so the other cource files can use the values, prevents compile error.
using namespace std;

// Here are all my different fucntion prototypes. These allow the control over the combat of my interactive game.
void intro(string name); //allows the user to input their chosen name
int showEnemyHP(int enemyHP); //allows me to take away health during attacks
int showPlayerHP(int playerHP);//same as above against the player
int playerCrit(int playerHP);
int enemyCrit(int enemyHP);

class GameMechanics {
public:
	int PLAYER_MAX_HP = 50;
	int ENEMY_MAX_HP = 75;
	
	
	// This is my roll of the dice function.
	int roll() {
		int r_num = rand(); //this generates the random number
		int die = (r_num % 20) + 1; // gets number between 1 and 20
		cout << "You rolled a " << die << endl;
		return die;

	}
	// This is my roll of the dice function for enemy.
	int enemyRoll() {
		int r_num = rand(); //this generates the random number
		int die = (r_num % 20) + 1; // gets number between 1 and 20
		cout << "The enemy rolled a " << die << endl;
		return die;
	}

protected:


private:

};

class Character : GameMechanics {
public:
	int& rPHealth = PLAYER_MAX_HP;
	int& rEHealth = ENEMY_MAX_HP;
	// These are my pointers that point to the players current health when typed. 
	const int* pPHealth = &PLAYER_MAX_HP;
	const int* pEHealth = &ENEMY_MAX_HP;


	void setCharAttack(int a)
	{
		char_attack = a;
	}

	int getCharAttack()
	{
		return char_attack;
	}

	// this tells the user to input the number shown for the enemy to attack or miss completely.
	void score()
	{
		int score;
		cout << "Please enter the number shown." << endl;
		cin >> score;
		if (score == 20) {
			cout << "You scored a critical hit!" << endl;
			rEHealth = enemyCrit(rEHealth);
			cout << "You have killed the enemy!" << endl;
			exit(0);

		}

		else if (score >= 13 && score < 20) {
			cout << "You hit the target!" << endl;
			rEHealth = showEnemyHP(rEHealth);
			cout << "The enemy's health is now: " << rEHealth << "\n" << endl;
		}
		else {
			cout << "You missed the target." << endl;
		}
		cout << "Prepare to defend yourself. Type 'defend' when ready." << endl;

	}

	void enemyScore()
	{
		int score;
		cout << "Please enter the number shown." << endl;
		cin >> score;
		if (score == 20) {
			cout << "They scored a critical hit!" << endl;
			rPHealth = playerCrit(rPHealth);
			cout << "You have died" << endl;
			exit(0);


		}
		else if (score >= 13 && score < 20) {
			cout << "They hit the you!" << endl;
			rPHealth = showPlayerHP(rPHealth);
			cout << "Your heatlh is now: " << rPHealth << "\n\n";
		}
		else {
			cout << "They missed the you." << endl;
		}
		cout << "Prepare to attack. Type 'roll' when ready." << endl;

	}



protected:

private:

	int char_attack;

};

class Player_Class : Character
{
public:

	void setPlayerAttack(int a)
	{
		player_attack = a;
	}
	void setInventory(string s)
	{
		inventory = s;
	}
	void setLives(int l)
	{
		lives = l;
	}
	int getLives()
	{
		return lives;
	}
	int getPlayerAttack()
	{
		return player_attack;
	}
	string getInventory()
	{
		return inventory;
	}
	// This is the function prototype for greeting the player. 
	void Greeting() 
	{

		cout << "You are an adventurer eagerly searching for the lost treasure of the Dragon Lich.\n";
		cout << "Your health is at " << *pPHealth << "HP.\n"; // This line has dereferenced pointers declared in the header file.
		
	}
protected:

private:

	int player_attack;
	int lives;
	string inventory;


	

};

class Skeleton_Class : Character
{
public:

	void setSkelAttack(int a)
	{
		skel_attack = a;
	}

	int getSkelAttack()
	{
		return skel_attack;
	}

	// This is the function prototype for greeting the player.
	void Taunt()
	{

		cout << "Human! You have no chance against me! My health is " << *pEHealth << "HP.\n";
	}

protected:

private:

	int skel_attack;

};

#endif