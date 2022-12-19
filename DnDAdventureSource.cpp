// Interactive Story
// This is my main source file that calls functions from my header and header source files. 
// Here is where I place my preprocessor directives
#include <iostream>
#include <string>
#include <time.h>
#include <thread>
#include <cstdlib>
#include <math.h>
#include <vector>
#include "DnDAdventure.h"
// these declerations allow us to which elements from the namespace std we want local to our program.
// std is our standard library that allows us to print out to the screen, along with iostream.
using namespace std;
void combatLoop()
{
	GameMechanics GameMech;
	Character Character;
	Player_Class player;
	Skeleton_Class skel;
	// this is my combat while loop. Continues until comabt is resolved.
	while (Character.rPHealth > 0 && Character.rEHealth > 0) {
		string usr_in_char;
		cin >> usr_in_char;

		// dice based combat, with a random number generator.
		if (usr_in_char == "roll") {
			GameMech.roll();
		}
		else
		{
			cout << "Please type 'Roll' to roll for attack\n" << endl;
		}
		Character.score();
		// allows for the player to defend against the enemy roll
		string usr_in_char2;
		cin >> usr_in_char2;
		if (usr_in_char2 == "defend") {
			GameMech.enemyRoll();

		}
		else {
			cout << "Please type 'defend' to roll for defense.\n" << endl;
		}
		Character.enemyScore();

	}
}

// This is the main function for the entire program. Allows me to call other functions from my source files.
int main()
{
	
	// This seeds the random number generator
	// The srand seeds the random number generator
	// The static_cast converts it to an unsigned int
	srand(static_cast<unsigned int> (time(0)));
	string usr_in;
		// this allows the user to input their name and see it in the intro text.
		cout << "Please enter your name" << endl;
		cin >> usr_in;
		intro( usr_in);
		thread t(combatLoop);
		t.join();
		
	
}
