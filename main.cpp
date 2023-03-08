#include <iostream>

#include "GameManager.h"
#include "Player.h"
#include "Monster.h"
#include "Stats.h"

using namespace std;

int main()
{
    char name[30] = "Player";
    //cin >> name;

    Stats* playerStats = new Stats();
    playerStats->m_armor = 1;
    playerStats->m_damage = 10;
    playerStats->m_speed = 1;

    Player player(name, 100, playerStats);

    Stats* monsterStats = new Stats();
    monsterStats->m_armor = 5;
    monsterStats->m_damage = 25;
    monsterStats->m_speed = 3;

    char * monstersName = "Monster";
    Monster monster(monstersName, 50, monsterStats);

    cout << "Hello " << player.name << endl;

    GameManager manager;
    manager.manageEncounter(&player, &monster);

    delete playerStats;
    delete monsterStats;

    return 0;
}
