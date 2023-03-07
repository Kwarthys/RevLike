#include "Player.h"
#include <iostream>

Player::Player(char* name, int maxHealth)
{
    this->name = name;
    this->health = maxHealth;
}

Player::~Player()
{}
