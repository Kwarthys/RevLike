#include "Player.h"
#include <iostream>

Player::Player(char* name, int maxHealth, Stats* stats) : Living(name, maxHealth, stats)
{
}

Player::~Player()
{}
