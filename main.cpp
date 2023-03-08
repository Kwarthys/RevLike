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

    char monstersName[30] = "Monster";
    Monster monster1(monstersName, 50, monsterStats);
    Monster monster2(monstersName, 50, monsterStats); //shared stats, this should not be an issue for now (will be with modifiers)

    Monster* monsters[2];
    monsters[0] = &monster1;
    monsters[1] = &monster2;

    cout << "Hello " << player.name << endl;

    GameManager manager;
    manager.manageEncounter(&player, monsters, 2);

    delete playerStats;
    delete monsterStats;

    return 0;
}
