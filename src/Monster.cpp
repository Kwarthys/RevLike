#include "Monster.h"

Monster::Monster(char* name, int maxHealth)
{
    this->name = name;
    this->health = maxHealth;
}

Monster::~Monster()
{
    delete[] name;
}
