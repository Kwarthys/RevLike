#ifndef LIVING_H
#define LIVING_H

#include "Stats.h"

class Living
{
    public:
        Living(char* name,  int health, Stats* stats);
        virtual ~Living();


        int health;
        int maxHealth;
        char* name;
        Stats* m_stats;

        void takeDamage(int amount);
        void attack(Living* target);
        bool isAlive(){return health > 0;}

    protected:

    private:
};

#endif // LIVING_H
