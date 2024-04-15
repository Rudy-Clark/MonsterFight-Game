#include "Monster.h"

Monster::Monster(Monster::Type type)
	:Creature(m_monsterData[static_cast<int>(type)])
{
}
