#pragma once
#include "Creature.h"
#include <array>
#include <string>
#include <string_view>
#include <cassert>


class Monster : public Creature
{
public:
	enum class Type {
		dragon,
		orc,
		slime,
		max_types
	};

	explicit Monster(Type type);

	static Monster getRandomMonster();

private:
	inline static std::array m_monsterData{
		Creature{"dragon", 'D', 20, 4, 100 },
		Creature{"orc", 'o', 4, 2, 25},
		Creature{"slime", 's', 1, 1, 10}
	};

	static_assert(std::size(m_monsterData) == static_cast<int>(Type::max_types));
};

