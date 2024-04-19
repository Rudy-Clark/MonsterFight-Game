#include "Monster.h"
#include "Random.h"

Monster::Monster(Monster::Type type)
	: Creature(m_monsterData[static_cast<int>(type)])
{
}

Monster Monster::getRandomMonster()
{
	int randomMonsterId{ Random::get(0, static_cast<int>(Monster::Type::max_types) - 1) };
	return Monster{ static_cast<Type>(randomMonsterId) };
}
