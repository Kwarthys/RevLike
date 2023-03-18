#include "Grenade.h"

Grenade::Grenade() : Consumable("Grenade")
{
    charges = 2;
}

Grenade::~Grenade()
{
    //dtor
}

void Grenade::use(Living& player, vector<Living*>& monsters)
{
    for(size_t i = 0; i < monsters.size(); ++i)
    {
        monsters.at(i)->takeDamage(damage);
    }
    charges -= 1;
}

string Grenade::display()
{
    ostringstream data;
    data << name << "\n" << charges << " charges\nDeals " << damage << " damage.\n";
    return data.str();
}
