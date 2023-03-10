#ifndef LIVING_H
#define LIVING_H

#include <iostream>
#include <sstream>
#include "Stats.h"
#include "Loot.h"

using namespace std;

class Living
{
    public:
        Living(string name, int health, Stats stats);
        virtual ~Living();

        bool isAlive(){return health > 0;}

        int health;
        int maxHealth;
        string name;
        Stats stats;

        void takeDamage(int amount);
        void attack(Living& target);

        void loot(Loot loot);

        string display();

    protected:

    private:
};

#endif // LIVING_H
