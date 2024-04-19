#include "Potion.h"
#include "Random.h"

Potion::Potion(Type type, Size size)
    : m_type{ type }
    , m_size{ size }
{
}

std::string Potion::getName() const
{
    return m_type_names[static_cast<int>(m_type)];
}

std::string Potion::getSize() const
{
    return m_size_names[static_cast<int>(m_size)];
}

Potion Potion::getRandomPotion()
{
    return Potion{ 
        static_cast<Potion::Type>(Random::get(0, (int)Type::max_size - 1)),  
        static_cast<Potion::Size>(Random::get(0, (int)Size::max_size - 1)) 
    };
}

const Effect& Potion::getEffect() const
{
    return m_effects[static_cast<int>(m_type)][static_cast<int>(m_size)];
}

