// This is my source file for my functions
// Here is where I place my preprocessor directives
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <math.h>
// These are the header files that are included into this source file
#include "DnDAdventure.h"
// These are my global variables used with references that are utilized in other functions.
int PLAYER_MAX_HP = 50;
int& rPHealth = PLAYER_MAX_HP;
int ENEMY_MAX_HP = 75;
int& rEHealth = ENEMY_MAX_HP;

// these declerations allow us to which elements from the namespace std we want local to our program.
// std is our standard library that allows us to print out to the screen, along with iostream.
using namespace std;
// this is the intro string that is called in the main function.
void intro(string name) {
	//Here is where I declare the classes for use in the intro function. Aloows me to call the functions from the other source files.
	Skeleton_Class skel;
	Player_Class user;
	skel.m_ENEMY_MAX_HEALTH = ENEMY_MAX_HP;
	user.m_PLAYER_MAX_HEALTH = PLAYER_MAX_HP;
	cout << "\n";
	cout << "Hello " << name << " and welcome to my interactive D&D quick adventure.\n";
	cout << "\n";
	user.Greeting();
	cout << "\n";
	skel.Taunt();
	cout << "\n";
	cout << "\n";
	cout << "Please type 'roll' to attack the target.\n";


}
// This is my roll of the dice function.
int roll() {
	char usr_in;
	int r_num = rand(); //this generates the random number
	int die = (r_num % 20) + 1; // gets number between 1 and 20
	cout << "You rolled a " << die << endl;
	return 0;

}

// this tells the user to input the number shown to attack or miss completely.
int score() {
	int playerAttack = 10, enemyAttack = 10;
	int hitEnemy;
	int score;
	cout << "Please enter the number shown." << endl;
	cin >> score;
	if (score == 20) {
		cout << "You scored a critical hit!" << endl;
		rEHealth = enemyCrit(rEHealth);
		cout << "You have killed the enemy!" << endl;
	}

	else if (score >= 13 && score < 20) {
		cout << "You hit the target!" << endl;
		rEHealth = showEnemyHP(rEHealth, playerAttack);
		cout << "The enemy's health is now: " << rEHealth << "\n" << endl;
	}
	else {
		cout << "You missed the target." << endl;
	}
	cout << "Prepare to defend yourself. Type 'defend' when ready." << endl;
	return 0;
}
int enemyRoll() {
	char usr_in;
	int r_num = rand(); //this generates the random number
	int die = (r_num % 20) + 1; // gets number between 1 and 20
	cout << "The enemy rolled a " << die << endl;
	return 0;
}
// this tells the user to input the number shown for the enemy to attack or miss completely.
int enemyScore() {
	int playerAttack = 10, enemyAttack = 10;
	int hitEnemy;
	int score;
	cout << "Please enter the number shown." << endl;
	cin >> score;
	if (score == 20) {
		cout << "They scored a critical hit!" << endl;
		rPHealth = playerCrit(rPHealth);
		cout << "You have died" << endl;

	}
	else if (score >= 13 && score < 20) {
		cout << "They hit the you!" << endl;
		rPHealth = showPlayerHP(rPHealth, enemyAttack);
		cout << "Your heatlh is now: " << rPHealth << "\n\n";
	}
	else {
		cout << "They missed the you." << endl;
	}
	cout << "Prepare to attack. Type 'roll' when ready." << endl;
	return 0;
}
// these functions allow me to subtract health from the player or skeleton based off if the attack was successful.
int showEnemyHP(int rEHealth, int playerAttack) {
	rEHealth = rEHealth - playerAttack;
	return rEHealth;

}
int showPlayerHP(int rPHealth, int enemyAttack) {
	rPHealth = rPHealth - enemyAttack;
	return rPHealth;
}
// These functions allow me to instantly kill the player or skeleton if they roll a 20.
int playerCrit(int rPHealth) {
	rPHealth = rPHealth - 100;
	return rPHealth;
}
int enemyCrit(int rEHealth) {
	rEHealth = rEHealth - 100;
	return rEHealth;
}