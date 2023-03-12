#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Living.h"
#include "Consumable.h"

using namespace std;

class Player : public Living
{
    public:
        Player(string name, int health, Stats stats);
        virtual ~Player();

        vector<Consumable*> inventory;

    protected:

    private:
};

#endif // PLAYER_H
