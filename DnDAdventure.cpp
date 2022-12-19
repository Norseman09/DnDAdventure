// This is my source file for my functions
// Here is where I place my preprocessor directives
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <time.h>
#include <cstdlib>
#include <math.h>
// These are the header files that are included into this source file
#include "DnDAdventure.h"

// std is our standard library that allows us to print out to the screen, along with iostream.
using namespace std;
// this is the intro string that is called in the main function.
void intro(string name)
{
	//Here is where I declare the classes for use in the intro function. Aloows me to call the functions from the other source files.
	GameMechanics GameMech;
	Character myChar;
	Player_Class player;
	Skeleton_Class skel;
	string usr_in;
	char user_in;
	player.setInventory("Axe, Armor, Potion of Rage");
	player.setLives(1);
	cout << "\n";
	cout << "Hello " << name << " and welcome to my interactive D&D quick adventure.\n";
	cout << "This quick adventure will allow you to fight or flee from an enemy simply by typing commands.\n";
	cout << "Would you like to play?\n";
	retry:
	cout << "Please type 'y' for yes or 'n' for no.\n";
	cout << "\n";
	cin >> user_in;
		if (user_in == 'y')
		{
			player.Greeting();
			cout << "Your inventory is: " << player.getInventory() << "\n";
			cout << "Be weary " << name << ". You only have " << player.getLives() << " life. So, make it count.\n";
			cout << "As you approach the suspected layer of the moster. You notice a skeleton guarding the entrance.\n";
			cout << "\n";
			skel.Taunt();
			cout << "\n";
			retry2:
			cout << "Type 'fight' to fight the skeleton or 'flee' to run away\n";
			cin >> usr_in;
			if (usr_in == "fight")
			{
				cout << "You decide to practice your swordsmanship and move forward to fight it.\n";
				cout << "\n";
				cout << "Please type 'roll' to attack the target.\n";
			}
			else if (usr_in == "flee")
			{
				cout << "You decide to flee.\n";
				exit(0);
			}
			else
			{
				cout << "Please choose 'fight' or 'flee'\n";
				goto retry2;
			}

		}
		else if (user_in == 'n')
		{
			cout << "Very well. Goodbye.\n";
			exit(0);
		}
		else
		{
			cout << "Please enter 'y' or 'n'\n";
			goto retry;
		}
}

// these functions allow me to subtract health from the player or skeleton based off if the attack was successful.
int showEnemyHP(int rEHealth) 
{
	Character myChar;
	myChar.setCharAttack(10);
	rEHealth = rEHealth - myChar.getCharAttack();
	return rEHealth;

}
int showPlayerHP(int rPHealth) 
{
	Character myChar;
	myChar.setCharAttack(10);
	rPHealth = rPHealth - myChar.getCharAttack();
	return rPHealth;
}
// These functions allow me to instantly kill the player or skeleton if they roll a 20.
int playerCrit(int rPHealth) 
{
	Player_Class player;
	player.setPlayerAttack(100);
	rPHealth = rPHealth - player.getPlayerAttack();
	return 0;
}
int enemyCrit(int rEHealth) 
{
	Skeleton_Class skel;
	skel.setSkelAttack(100);
	rEHealth = rEHealth - skel.getSkelAttack();
	return 0;
}
