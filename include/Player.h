#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Living.h"

class Player : public Living
{
    public:
        Player(string name, int health, Stats stats);
        virtual ~Player();

    protected:

    private:
};

#endif // PLAYER_H
