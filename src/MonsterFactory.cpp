#include "MonsterFactory.h"

MonsterFactory::MonsterFactory()
{
    //ctor
}

MonsterFactory::~MonsterFactory()
{
    //dtor
}


std::vector<Living*> MonsterFactory::getRandomMonsters(int budget)
{
    std::vector<Living*> monsters;

    while(budget > 0)
    {
        Monster* m = getRandomMonster(budget);
        budget -= m->monsterCost;

        monsters.push_back(m);
    }

    return monsters;
}

Monster* MonsterFactory::getRandomMonster(int budget)
{
    int lowestCost = -1;

    for(size_t i = 0; i < ALL_MONSTERS.size(); ++i)
    {
        int c = getMonsterCost(ALL_MONSTERS.at(i));

        if(lowestCost == -1)
        {
            lowestCost = c;
        }
        else
        {
            if(c < lowestCost)
            {
                lowestCost = c;
            }
        }
    }

    if(budget < lowestCost)
    {
        budget = lowestCost;
    }

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<size_t> distrib(0, ALL_MONSTERS.size() - 1);

    while(true)
    {
        MonsterType randomType = ALL_MONSTERS.at(distrib(gen));
        int cost = getMonsterCost(randomType);

        if(cost <= budget)
        {
            return getThisMonster(randomType);
        }
    }

}

Monster* MonsterFactory::getThisMonster(MonsterType type)
{
    Monster* m;
    Stats stats;
    switch(type)
    {
        case Giant:
            stats.m_armor = 10;
            stats.m_crit = 5;
            stats.m_speed = 5;
            stats.m_damage = 30;
            m = new Monster("Giant", 200, stats);
            m->monsterCost = getMonsterCost(type);
            break;

        case Goblin:
            stats.m_armor = 1;
            stats.m_crit = 10;
            stats.m_speed = 2;
            stats.m_damage = 10;
            m = new Monster("Goblin", 50, stats);
            m->monsterCost = getMonsterCost(type);
            break;
    }

    return m;
}

int MonsterFactory::getMonsterCost(MonsterType type)
{
    switch(type)
    {
        case Giant:
            return 10;

        case Goblin:
            return 3;
    }

    return 0;
}
