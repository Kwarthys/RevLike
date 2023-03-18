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

    MonsterFactory monsterFactory;

    HealthPotion* hp = new HealthPotion();
    player.inventory.push_back(hp);

    while((turn < numberOfTurn || numberOfTurn == 0) && player.isAlive()) // numberOfTurns of 0 means infinite
    {
        int turnLevel = turn / turnToLevelUp + 1;

        /*** generate x monsters ***/
        vector<Living*> monsters = monsterFactory.getRandomMonsters((turn+1) * 3, turnLevel);

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
        DisplayManager::displayEndOfCombatAction();
        cout << player.display() << endl;
        Living::horizontalDisplay(monsters);
        cout << endl;

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

        PlayerInputs::waitPlayerPause();
        DisplayManager::displayEndOfCombatAction();

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
    DisplayManager::displayEndOfEncounter();
}
