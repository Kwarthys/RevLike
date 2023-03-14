#include "Consumable.h"

Consumable::Consumable(string name)
{
    this->name = name;
}

Consumable::~Consumable()
{
    //dtor
}

void Consumable::use(Living& target){}
