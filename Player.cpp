#include "Player.h"

Player::Player(std::string_view name)
	: Creature(name, '@', 10, 1, 0)
	, m_level{1}
{
}

int Player::getLevel() const
{
	return m_level;
}

void Player::levelUp()
{
	++m_level;
	++m_damage;

}

bool Player::hasWon() const
{
	return m_level == 20;
}
