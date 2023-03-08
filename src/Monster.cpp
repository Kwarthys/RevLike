#include "Monster.h"

Monster::Monster(char* name, int maxHealth, Stats* stats) : Living(name, maxHealth, stats)
{
}

Monster::~Monster()
{}
