// FightMonstersGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author Rudy Clark

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Random.h"
#include <numbers>

inline bool isFight(char c) { return (c == 'f' || c == 'F'); }
inline bool isRun(char c) { return (c == 'r' || c == 'R'); }
inline bool isEscaped() { return Random::get(0, 100) >= 50; }

char getUserAction() {
	while (true) {
		char action{};
		std::cin >> action;

		if (isRun(action) || isFight(action)) {
			return action;
		}
		else
		{
			if (std::cin.eof()) // if the stream was closed
			{
				exit(0); // shut down the program now
			}
			std::cout << "Wrong character, please enter 'r' or 'f'!\n";
			// yep, so let's handle the failure
			std::cin.clear();
		}
	}
}

void attackMonster(const Player& player, Monster& monster)
{
	monster.reduceHealth(player.getDamage());
}
void attackPlayer(const Monster& monster, Player& player)
{
	player.reduceHealth(monster.getDamage());
}

void fightMonster(Player& player, Monster& monster) 
{
	while (!monster.isDead() && !player.isDead()) {
		std::cout << "(R)un or (F)ight:";

		if (isFight(getUserAction()))
		{
			attackMonster(player, monster);
			std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
		}
		else
		{
			if (isEscaped()) {
				std::cout << "You succefully fled!\n";
				break;
			}
		}

		if (!monster.isDead()) 
		{
			attackPlayer(monster, player);
			std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
		}
		else
		{
			player.levelUp();
			player.addGold(monster.getGold());

			std::cout << "You killed the " << monster.getName() << "\n";
			std::cout << "You found " << monster.getGold() << " gold. \n";
		}
	}
	
}

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
	
	/*Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";*/
	
	/*for (int i{ 0 }; i < 10; ++i)
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}*/

	std::string name{};
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "\n";

	Player player{ name };
	
	while (!player.isDead()) {
		Monster monster{ Monster::getRandomMonster() };
		std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n";
		fightMonster(player, monster);

		if (player.hasWon()) {
			std::cout << "You reached level 20 and won game!!!\n";
			std::cout << "You collected " << player.getGold() << " gold.\n";
			break;
		}
	}

	if (player.isDead()) {
		//You died at level 3 and with 35 gold.
		//Too bad you can’t take it with you!
		
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	
	return 0;
}
