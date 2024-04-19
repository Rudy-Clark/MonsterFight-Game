#pragma once
class Effect
{
public:
	Effect(int poison, int health, int strength);

	int getPoison() const;
	int getHealth() const;
	int getStrength() const;

private:
	int m_poison{};
	int m_health{};
	int m_strength{};
};

