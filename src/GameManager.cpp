#include "GameManager.h"

GameManager::GameManager()
{
    //ctor
}

GameManager::~GameManager()
{
    //dtor
}

void GameManager::manageLooting(Living& player, std::vector<Stats>& loots)
{
    vector<string> options;
    for(size_t i = 0; i < loots.size(); ++i)
    {
        options.push_back(loots.at(i).display());
    }

    int choice = PlayerInputs::getPlayerChoice(options, false);

    if(choice >= 0 && choice < loots.size())
    {
        player.loot(loots.at(choice));
    }
}

void GameManager::manageEncounter(Living& player, vector<Living*>& monsters)
{
    bool monstersAlive = true;
    while(player.isAlive() && monstersAlive)
    {
        cout << player.display() << endl;

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
            player.attack(*monsters.at(choice));

            if(!monsters.at(choice)->isAlive())
            {
                cout << "\nYou killed " << monsters.at(choice)->name << " !\n" << endl;
            }

            PlayerInputs::waitPlayerPause();
        }

        monstersAlive = false;
        for(size_t i = 0; i < monsters.size(); ++i)
        {
            bool alive =  monsters.at(i)->isAlive();
            monstersAlive = monstersAlive || alive;

            if(alive)
            {
                monsters.at(i)->attack(player);
            }
        }
        if(monstersAlive)
        {
            PlayerInputs::waitPlayerPause();
        }
    }

    cout << "End of encounter" << endl;
}
