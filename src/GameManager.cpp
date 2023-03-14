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

    HealthPotion* hp = new HealthPotion();
    player.inventory.push_back(hp);

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
    size_t unsignedChoice = choice;

    if(choice >= 0)
    {
        if(unsignedChoice < loots.size())
        {
            player.loot(loots.at(choice));
        }
    }
}

bool GameManager::manageItems(Player& player, std::vector<Living*>& monsters)
{
    //use potions, maybe throw grenades

    vector<string> itemsStats;
    vector<string> options;
    for(size_t i = 0; i < player.inventory.size(); ++i)
    {
        //for items display
        itemsStats.push_back(player.inventory.at(i)->display());

        //for item selection
        options.push_back(player.inventory.at(i)->name);
    }

    DisplayManager::horizontalLinesDisplay(itemsStats, 50);

    cout << "What item to use ?" << endl;
    int choice = PlayerInputs::getPlayerChoice(options);
    size_t unsignedChoice = choice;

    if(choice >= 0)
    {
        if(unsignedChoice < player.inventory.size())
        {
            player.useItem(choice, player);
            return true;
        }
    }

    return false;
}

bool GameManager::manageAttacks(Living& player, std::vector<Living*>& monsters)
{
    cout << "Who to attack ?" << endl;
    //building monsters options
    vector<string> options;
    for(size_t i = 0; i < monsters.size(); ++i)
    {
        options.push_back(monsters.at(i)->name);
    }

    int choice = PlayerInputs::getPlayerChoice(options);
    size_t unsignedChoice = choice;
    if(choice >= 0 )
    {
        if(unsignedChoice < monsters.size())
        {
            player.attack(*monsters.at(choice));
            if(!monsters.at(choice)->isAlive())
            {
                cout << "\nYou killed " << monsters.at(choice)->name << " !\n" << endl;
            }
        }

       PlayerInputs::waitPlayerPause();

       return true;
    }

    return false;
}

void GameManager::manageMonstersTurn(Living& player, std::vector<Living*>& monsters)
{
    for(size_t i = 0; i < monsters.size(); ++i)
    {
        if(monsters.at(i)->isAlive())
        {
            monsters.at(i)->attack(player);
        }
    }
}

void GameManager::manageEncounter(Player& player, vector<Living*>& monsters)
{
    vector<string> baseMenuOptions;
    baseMenuOptions.push_back("Attack");
    baseMenuOptions.push_back("Use Items");
    baseMenuOptions.push_back("Surrender");


    bool monstersAlive = true;
    while(player.isAlive() && monstersAlive)
    {
        cout << "------------------------------------------" << endl; //new turn visual hint
        cout << player.display() << endl;
        Living::horizontalDisplay(monsters);


        bool didAction = false;
        while(!didAction)
        {
            int choice = PlayerInputs::getPlayerChoice(baseMenuOptions, false);

            if(choice == 0)
            {
                didAction = manageAttacks(player, monsters);
            }
            else if(choice == 1)
            {
                //cout << "useItems" << endl;
                didAction = manageItems(player, monsters);
            }
            else
            {
                cout << "Surrender" << endl;
                player.health = 0;
                didAction = true;
            }
        }

        if(player.isAlive())
        {
            monstersAlive = false;
            for(size_t i = 0; i < monsters.size(); ++i)
            {
                monstersAlive = monstersAlive || monsters.at(i)->isAlive();
            }

            if(monstersAlive)
            {
                manageMonstersTurn(player, monsters);
                PlayerInputs::waitPlayerPause(false);
            }
        }
    }
    cout << "End of encounter" << endl;
}
