// FightMonstersGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author Rudy Clark

#include <iostream>
#include <functional>
#include "Player.h"
#include "Monster.h"
#include "Random.h"
#include "Potion.h"

inline bool isFight(char c) { return (c == 'f' || c == 'F'); }
inline bool isRun(char c) { return (c == 'r' || c == 'R'); }
inline bool checkIsFR(char c) { return (isFight(c) || isRun(c)); }

inline bool isYes(char c) { return (c == 'Y' || c == 'y'); }
inline bool isNo(char c) { return (c == 'N' || c == 'n'); }
inline bool checkIsYN(char c) { return (isYes(c) || isNo(c)); }

inline bool isEscaped() { return Random::get(0, 100) >= 50; }
inline bool isPotionFound() { return Random::get(0, 100) >= 70; }

template<typename T>
char getUserAction(const std::function<bool(T)>& f) {
	while (true) {
		char action{};
		std::cin >> action;

		if (f(action)) {
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

		if (isFight(getUserAction<char>(checkIsFR)))
		{
			attackMonster(player, monster);
			std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
		}
		else
		{
			// let's try to escape.
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

		if (player.hasWon()) 
		{
			std::cout << "You reached level 20 and won game!!!\n";
			std::cout << "You collected " << player.getGold() << " gold.\n";
			break;
		}

		// end of the fight, let's check did player found potion
		if (isPotionFound() && !player.isDead()) 
		{
			std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";

			if (char potionFoundAction{ getUserAction<char>(checkIsYN) }; isYes(potionFoundAction)) 
			{
				Potion potion{ Potion::getRandomPotion() };
				player.drankPotion(potion);
				std::cout << "You drank a " << potion.getSize() << " potion of " << potion.getName();
			}
		}
	}

	if (player.isDead()) {
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}

	// Let's test our generator
	/*for (size_t i{}; i < 10; ++i) {
		Potion potion{ Potion::getRandomPotion() };
		std::cout << i + 1 << ". Generated " << potion.getSize() << " potion of the " << potion.getName() << "\n";
	}*/

	
	return 0;
}
