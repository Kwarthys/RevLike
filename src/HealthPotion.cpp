#include "HealthPotion.h"

HealthPotion::HealthPotion() : Consumable("Health Potion")
{
    charges = 5;
}

HealthPotion::~HealthPotion()
{
    //dtor
}

void HealthPotion::use(Living& player, vector<Living*>& monsters)
{
    player.heal(healAmount);
    charges -= 1;
}

string HealthPotion::display()
{
    ostringstream data;
    data << name << "\n" << charges << " charges\nHeals " << healAmount << " health points.\n";
    return data.str();
}
