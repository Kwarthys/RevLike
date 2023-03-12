#include "GameManager.h"

GameManager::GameManager()
{
    //ctor
}

GameManager::~GameManager()
{
    //dtor
}

void GameManager::playGame(Player& player, int numberOfTurn)
{
    int turn = 0;
    int turnToLevelUp = 2;

    while(turn < numberOfTurn && player.isAlive())
    {
        int turnLevel = turn / turnToLevelUp + 1;

        /*** generate x monsters ***/
        vector<Living*> monsters;
        int nMonsters = rand() % 3 + 1;

        if(nMonsters > turn+1)
        {
            nMonsters = turn+1;
        }

        for(int i = 0; i < nMonsters; ++i)
        {
            cout << "generating monster" << i << " level" << turnLevel << endl;
            Monster* m = Monster::generateRandomMonster(turnLevel);
            cout << "adding monster" << i << endl;
            monsters.push_back(m);
        }

        cout << "FIGHT" << endl;

        manageEncounter(player, monsters);

        for(size_t i = 0; i < monsters.size(); ++i)
        {
            delete monsters.at(i);
        }

        if(player.isAlive())
        {
            vector<Loot> loots;
            for(int i = 0; i < 3; ++i)
            {
                loots.push_back(Loot::generateRandomLoot(turnLevel));
            }

            manageLooting(player, loots);
        }

        player.health = player.maxHealth;//no regen potion for now

        turn++;
    }
}

void GameManager::manageLooting(Living& player, vector<Loot>& loots)
{
    cout << "\nLoot ! Choose one :" << endl;
    Loot::horizontalLootsDisplay(loots);
    cout << endl;

    vector<string> options;
    for(size_t i = 0; i < loots.size(); ++i)
    {
        options.push_back(loots.at(i).name);
    }

    int choice = PlayerInputs::getPlayerChoice(options, false);

    if(choice >= 0 && choice < loots.size())
    {
        player.loot(loots.at(choice));
    }
}

void GameManager::manageEncounter(Player& player, vector<Living*>& monsters)
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
