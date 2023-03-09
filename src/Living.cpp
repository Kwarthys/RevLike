#include "Living.h"

Living::Living(string name, int health, Stats stats)
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
    if(!isAlive())
    {
        std::cout << "bonk" << std::endl;
        return;
    }

    int reducedDamage = amount - m_stats.m_armor;
    if(reducedDamage < 0)
    {
        reducedDamage = 0;
    }
    health = health - reducedDamage;

    if(health < 0)
    {
        health = 0;
    }

    std::cout << name << " takes " << reducedDamage << "(" << amount << "-" << m_stats.m_armor << ") damage.\n" << std::endl;
}

void Living::attack(Living* target)
{
    int damage = m_stats.m_damage;

    std::cout << name << " attacks " << target->name << std::endl;

    if(rand()%100+1 < m_stats.m_crit)
    {
        std::cout << "CRIT" << std::endl;
        damage *= 2;
    }

    target->takeDamage(damage);
}

string Living::display()
{
    ostringstream data;
    if(isAlive())
    {
        data << name << "(" << health << ") : " << m_stats.m_damage << "(" << m_stats.m_crit << "%) - " << m_stats.m_armor;
    }
    else
    {
        data << "Dead" << endl;
    }
    return data.str();
}
