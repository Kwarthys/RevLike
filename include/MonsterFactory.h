#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include <vector>
#include <random>
#include "Monster.h"

class MonsterFactory
{
    public:
        MonsterFactory();
        virtual ~MonsterFactory();

        enum MonsterType{Giant, Goblin};
        std::vector<MonsterType> ALL_MONSTERS{Giant, Goblin};

        Monster* getThisMonster(MonsterType type, int level);

        Monster* getRandomMonster(int budget, int level);
        std::vector<Living*> getRandomMonsters(int budget, int level);

        int getMonsterCost(MonsterType type, int level);

    protected:

    private:
};

#endif // MONSTERFACTORY_H
