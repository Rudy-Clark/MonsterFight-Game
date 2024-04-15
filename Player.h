#pragma once
#include "Creature.h"
#include <string>


class Player : public Creature
{
public:
	explicit Player(std::string_view name);

	int getLevel() const;

	void levelUp();
	bool hasWon() const;

private:
	int m_level{};
};

