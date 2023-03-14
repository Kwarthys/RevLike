#include "Player.h"

Player::Player(string name, int maxHealth, Stats stats) : Living(name, maxHealth, stats)
{
}

Player::~Player()
{}

void Player::useItem(int itemIndex, Living& target)
{
    if(itemIndex >= 0 && itemIndex < inventory.size())
    {
        Consumable* item = inventory.at(itemIndex);
        item->use(target);

        if(item->charges == 0)
        {
            //remove item from vector
            inventory.erase(inventory.begin() + itemIndex);
            //delete item from memory
            delete item;
        }
    }
}
