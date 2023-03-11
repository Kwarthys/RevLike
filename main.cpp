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

    cout << "Hello " << player.name << endl;

    GameManager manager;
    manager.playGame(player, 2);

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
