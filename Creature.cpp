#include "Creature.h"

Creature::Creature(std::string_view name, char symbol, int health, int damage, int gold)
    : m_name{name}
    , m_symbol{symbol}
    , m_health{health}
    , m_damage{damage}
    , m_gold{gold}
{
}

const std::string& Creature::getName() const
{
    return m_name;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getGold() const
{
    return m_gold;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

bool Creature::isDead() const
{
    return m_health <= 0;
}

void Creature::addGold(int amount)
{
    if (amount <= 0) return;

    m_gold += amount;
}

void Creature::reduceHealth(int amount)
{
    if (amount <= 0) return;
    m_health -= amount;
}
