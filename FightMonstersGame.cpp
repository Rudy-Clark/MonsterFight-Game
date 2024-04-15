// FightMonstersGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author Rudy Clark

#include <iostream>
#include "Player.h"
#include "Monster.h"

int main()
{
	/*Creature player{ "orc", 'player', 4, 2, 10 };
	player.addGold(5);
	player.reduceHealth(1);
	std::cout << "The " << player.getName() << " has " << player.getHealth() << " health and is carrying " << player.getGold() << " gold.\n";*/

	/*std::string playerName{};
	std::cout << "Enter your name: ";
	std::cin >> playerName;
	std::cout << '\n';

	Player player{ playerName };
	std::cout << "The " << player.getName() << " has " << player.getHealth() << " health and is carrying " << player.getGold() << " gold.\n";*/
	
	Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	
}
