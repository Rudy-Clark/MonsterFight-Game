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

void Player::drankPotion(const Potion& potion)
{
	const Effect& effect{ potion.getEffect() };

	m_damage += effect.getStrength();
	m_health += effect.getHealth();
	m_health += effect.getPoison();

	
}
