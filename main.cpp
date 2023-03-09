#include <iostream>
#include <vector>

#include "GameManager.h"
#include "Player.h"
#include "Monster.h"
#include "Stats.h"

using namespace std;

int main()
{
    char name[30] = "Player";
    //cin >> name;

    Stats playerStats;
    playerStats.m_armor = 1;
    playerStats.m_damage = 20;
    playerStats.m_speed = 1;
    playerStats.m_crit = 50;

    Player player(name, 100, playerStats);

    Stats monsterStats;
    monsterStats.m_armor = 5;
    monsterStats.m_damage = 25;
    monsterStats.m_speed = 3;
    monsterStats.m_crit = 5;

    char monstersName[30] = "Monster";
    Monster monster1(monstersName, 50, monsterStats);
    Monster monster2(monstersName, 50, monsterStats); //shared stats, this should not be an issue for now (will be with modifiers)

    vector<Living*> monsters;
    monsters.push_back(&monster1);
    monsters.push_back(&monster2);

    cout << "Hello " << player.name << endl;

    GameManager manager;
    manager.manageEncounter(player, monsters);

    if(player.isAlive())
    {
        cout << "Victory !" << endl; // what a victory screen
    }
    else
    {
        cout << "Defeat ..." << endl; // what a game over screen;
    }


    return 0;
}
