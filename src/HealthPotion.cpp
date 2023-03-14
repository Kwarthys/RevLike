#include "HealthPotion.h"

HealthPotion::HealthPotion() : Consumable("Health Potion")
{
    charges = 5;
}

HealthPotion::~HealthPotion()
{
    //dtor
}

void HealthPotion::use(Living& target)
{
    target.heal(healAmount);
    charges -= 1;
}

string HealthPotion::display()
{
    ostringstream data;
    data << "Health Potion\n" << charges << " charges\nHeals " << healAmount << " health points.\n";
    return data.str();
}
