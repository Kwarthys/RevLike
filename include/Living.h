#ifndef LIVING_H
#define LIVING_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Stats.h"
#include "Loot.h"
#include "DisplayManager.h"

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

        void heal(int amount);
        void takeDamage(int amount);
        void attack(Living& target);

        static void horizontalDisplay(vector<Living*>& livings);

        void loot(Loot loot);

        string display();

    protected:

    private:
};

#endif // LIVING_H
