#include "Living.h"
#include <iostream>

Living::Living(char* name,  int health, Stats* stats)
{
    this->name = name;
    this->maxHealth = health;
    this->health = health;
    this->m_stats = stats;
}

Living::~Living()
{
    //delete name;
}

void Living::takeDamage(int amount)
{
    int reducedDamage = amount - m_stats->m_armor;
    if(reducedDamage < 0)
    {
        reducedDamage = 0;
    }
    health = health - reducedDamage;

    std::cout << health << " " << name << " took " << reducedDamage << "(" << amount << "-" << m_stats->m_armor << ") damage." << std::endl;
}

void Living::attack(Living* target)
{
    target->takeDamage(this->m_stats->m_damage);
}
