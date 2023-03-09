#ifndef LIVING_H
#define LIVING_H

#include "Stats.h"

#include <iostream>
#include <sstream>
using namespace std;

class Living
{
    public:
        Living(string name, int health, Stats stats);
        virtual ~Living();


        int health;
        int maxHealth;
        string name;
        Stats m_stats;

        void takeDamage(int amount);
        void attack(Living* target);
        bool isAlive(){return health > 0;}

        string display();

    protected:

    private:
};

#endif // LIVING_H
