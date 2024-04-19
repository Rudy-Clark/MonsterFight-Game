#include "Effect.h"

Effect::Effect(int poison, int health, int strength)
	: m_poison{ poison }
	, m_health{ health }
	, m_strength{ strength }
{
}

int Effect::getPoison() const
{
	return m_poison;
}

int Effect::getHealth() const
{
	return m_health;
}

int Effect::getStrength() const
{
	return m_strength;
}
