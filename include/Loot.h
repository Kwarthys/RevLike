#ifndef LOOT_H
#define LOOT_H

#include <string>
#include <vector>
#include "Stats.h"
#include "DisplayManager.h"

using namespace std;

class Loot
{
    public:
        Loot(string name);
        virtual ~Loot();

        Stats stats;
        string name;

        static void horizontalLootsDisplay(vector<Loot> loots);

        static Loot generateRandomLoot(int level);

    protected:

    private:
};

#endif // LOOT_H
