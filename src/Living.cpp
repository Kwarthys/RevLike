#include "Living.h"

Living::Living(string name, int health, Stats stats)
{
    this->name = name;
    this->maxHealth = health;
    this->health = health;
    this->stats = stats;
}

Living::~Living()
{
    //delete name;
}

void Living::takeDamage(int amount)
{
    if(!isAlive())
    {
        cout << "bonk" << endl;
        return;
    }

    int reducedDamage = amount - stats.m_armor;
    if(reducedDamage < 0)
    {
        reducedDamage = 0;
    }
    health = health - reducedDamage;

    if(health < 0)
    {
        health = 0;
    }

    cout << name << " takes " << reducedDamage << "(" << amount << "-" << stats.m_armor << ") damage.\n" << endl;
}

void Living::heal(int amount)
{
    int amountHealed;

    int missingHealth = maxHealth - health;
    if(amount < missingHealth)
    {
        health += amount;
        amountHealed = amount;
    }
    else
    {
        health = maxHealth;
        amountHealed = missingHealth;
    }

    cout << name << " regains " << amountHealed << " hps." << endl;
}

void Living::attack(Living& target)
{
    int damage = stats.m_damage;

    cout << name << " attacks " << target.name << endl;

    if(rand()%100+1 < stats.m_crit)
    {
        cout << "CRIT" << endl;
        damage *= 2;
    }

    target.takeDamage(damage);
}

string Living::display()
{
    ostringstream data;
    if(isAlive())
    {
        data << name << " " << health << "/" << maxHealth << " \nDamage: " << stats.m_damage << "\nCrit: " << stats.m_crit << "%)\nArmor: " << stats.m_armor << "\n";
    }
    else
    {
        data << "Dead\n";
    }
    return data.str();
}

void Living::loot(Loot loot)
{
    this->stats.add(loot.stats);
}

void Living::horizontalDisplay(vector<Living*>& livings)
{
    vector<string> data;
    for(size_t i=0; i < livings.size(); ++i)
    {
        data.push_back(livings.at(i)->display());
    }

    DisplayManager::horizontalLinesDisplay(data, 50);
}
