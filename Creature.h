#pragma once
#include <iostream>
#include <string>

class Creature
{
public:
	Creature(std::string_view name, char symbol, int health, int attackPower, int goldAmount);

	const std::string& getName() const;
	int getHealth() const;
	int getGold() const;




private:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_attackPower{};
	int m_goldAmount{};
};

