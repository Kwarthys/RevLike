#include "Living.h"
#include <iostream>

Living::Living()
{}

Living::~Living()
{}

void Living::takeDamage(int amount)
{
    this->health = this->health - amount;
}
