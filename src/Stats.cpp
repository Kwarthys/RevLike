#include "Stats.h"

Stats::Stats()
{
    m_damage = 0;
    m_armor = 0;
    m_speed = 0;
    m_crit = 0;
}

Stats::~Stats()
{
    //dtor
}

std::string Stats::display()
{
    std::ostringstream data;
    if(m_armor != 0)
    {
        data << "Armor: " << m_armor << "\n";
    }

    if(m_crit != 0)
    {
        data << "Crit: " << m_crit << "\n";
    }

    if(m_speed != 0)
    {
        data << "Speed: " << m_speed << "\n";
    }

    if(m_damage != 0)
    {
        data << "Damage: " << m_damage << "\n";
    }

    return data.str();
}

void Stats::add(Stats toAdd)
{
    m_armor += toAdd.m_armor;
    m_crit += toAdd.m_crit;
    m_speed += toAdd.m_speed;
    m_damage += toAdd.m_damage;
}
