#pragma once
#include "Effect.h"

#include <cassert>
#include <string>
#include <array>

class Potion
{
public:
	enum class Type {
		Health,
		Strength,
		Poison,
		max_size,
	};

	enum class Size {
		Small,
		Medium,
		Large,
		max_size,
	};

	Potion(Type type, Size size);

	std::string getName() const;
	std::string getSize() const;

	static Potion getRandomPotion();

	const Effect& getEffect() const;

private:
	Type m_type{};
	Size m_size{};

	static const inline std::array<std::array<Effect, static_cast<int>(Size::max_size)>, static_cast<int>(Type::max_size)> m_effects{ 
		{
			{  Effect(0, 2, 0), Effect(0, 2, 0), Effect(0, 5, 0) }, // First row it's Health and columns represent size
			{  Effect(0, 0, 1), Effect(0, 0, 2), Effect(0, 0, 3) }, // Second Strength
			{  Effect(-1, 0, 0), Effect(-2, 0, 0), Effect(-2, 0, 0) }, // Third Poison
		}
	};

	static inline std::array m_type_names{
		"Health",
		"Strength",
		"Poison",
	};

	static inline std::array m_size_names{
		"Small",
		"Medium",
		"Large"
	};

	static_assert(m_type_names.size() == static_cast<int>(Type::max_size));
	static_assert(m_size_names.size() == static_cast<int>(Size::max_size));
};

