#ifndef MONSTER_H
#define MONSTER_H

#include "Living.h"

class Monster : public Living
{
    public:
        Monster(char* name,  int health);
        virtual ~Monster();

    protected:

    private:
};

#endif // MONSTER_H
