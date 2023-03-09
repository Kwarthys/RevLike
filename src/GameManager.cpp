#include "GameManager.h"

GameManager::GameManager()
{
    //ctor
}

GameManager::~GameManager()
{
    //dtor
}

void GameManager::manageEncounter(Living& player, vector<Living*>& monsters)
{
    bool monstersAlive = true;
    while(player.isAlive() && monstersAlive)
    {
        cout << "Who to attack ?" << endl;
        //building monsters options
        vector<string> options;
        for(size_t i = 0; i < monsters.size(); ++i)
        {
            options.push_back(monsters.at(i)->display());
        }

        int choice = PlayerInputs::getPlayerChoice(options);

        if(choice >= 0 && choice < monsters.size())
        {
            player.attack(monsters.at(choice));
        }

        monstersAlive = false;
        for(size_t i = 0; i < monsters.size(); ++i)
        {
            monstersAlive = monstersAlive || monsters.at(i)->isAlive();
        }
    }

    cout << "Victory !" << endl; // what a victory screen
}
