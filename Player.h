#pragma once

#include "Creature.h"
#include "Potion.h"
#include <string>


class Player : public Creature
{
public:
	explicit Player(std::string_view name);

	int getLevel() const;

	void levelUp();
	bool hasWon() const;

	void drankPotion(const Potion& potion);

private:
	int m_level{};
};

