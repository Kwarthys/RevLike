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

        Monster* getThisMonster(MonsterType type);

        Monster* getRandomMonster(int budget);
        std::vector<Living*> getRandomMonsters(int budget);

        int getMonsterCost(MonsterType type);

    protected:

    private:
};

#endif // MONSTERFACTORY_H
