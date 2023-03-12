#include "HealthPotion.h"

HealthPotion::HealthPotion(string name) : Consumable(name)
{
    //ctor
}

HealthPotion::~HealthPotion()
{
    //dtor
}

void HealthPotion::use(Living* owner)
{
    owner->heal(healAmount);
    charges -= 1;
}
