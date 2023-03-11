#include "Monster.h"

Monster::Monster(string name, int maxHealth, Stats stats) : Living(name, maxHealth, stats)
{
}

Monster::~Monster()
{}

Monster* Monster::generateRandomMonster(int level)
{
    Stats monsterStats;

    monsterStats.m_armor = rand() % level + 1;
    monsterStats.m_crit = (rand() % level + 1) * 5;
    monsterStats.m_damage = (rand() % level + 1) * 10;
    monsterStats.m_speed = 0;//not used yet

    Monster* m = new Monster("TheMonster", 100, monsterStats);
    return m;
}
