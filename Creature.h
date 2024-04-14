#pragma once
#include <iostream>
#include <string>

class Creature
{
public:
	Creature(std::string_view name, char symbol, int health, int attackPower, int gold);

	const std::string& getName() const;
	int getHealth() const;
	int getGold() const;

	bool isDead() const;	void addGold(int amount);	void reduceHealth(int amount); private:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_attackPower{};
	int m_gold{};
};

