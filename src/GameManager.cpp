#include "GameManager.h"

GameManager::GameManager()
{
    //ctor
}

GameManager::~GameManager()
{
    //dtor
}

void GameManager::manageEncounter(Living* player, Living* monsters[], int monsterNumber)
{
    bool monstersAlive = true;
    while(player->isAlive() && monstersAlive)
    {
        cout << "Who to attack ?" << endl;
        //building monsters options
        string options[monsterNumber];
        for(int i = 0; i < monsterNumber; ++i)
        {
            options[i] = monsters[i]->display();
        }

        int choice = PlayerInputs::getPlayerChoice(options, monsterNumber);

        if(choice > 0 && choice < monsterNumber)
        {
            player->attack(monsters[choice]);
        }
    }
}
