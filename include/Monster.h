#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "Living.h"

class Monster : public Living
{
    public:
        Monster(string name, int health, Stats stats);
        virtual ~Monster();

        static Monster* generateRandomMonster(int level);

    protected:

    private:
};

#endif // MONSTER_H
