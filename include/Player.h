#ifndef PLAYER_H
#define PLAYER_H

#include "Living.h"

class Player : public Living
{
    public:
        Player(char* name, int health, Stats* stats);
        virtual ~Player();

    protected:

    private:
};

#endif // PLAYER_H
