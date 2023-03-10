#include "Loot.h"

Loot::Loot(std::string name)
{
    this->name = name;
}

Loot::~Loot()
{
    //dtor
}

Loot Loot::generateRandomLoot(int level)
{
    //sloppy, maybe enum for that ?

    Loot loot("Loot");
    Stats lootStats;

    int perks = rand() % level + 1;
    for(int i = 0; i < perks; ++i)
    {
        int r = rand() % 100;

        if(r < 20)
        {
            //crit
            lootStats.m_crit += (rand() % level + 1) * 1;

            if(i==0)
            {
                loot.name = "Rune of Crit";
            }
        }
        else if(r < 40)
        {
            //damage
            lootStats.m_damage += (rand() % level + 1) * 5;

            if(i==0)
            {
                loot.name = "Rune of Strength";
            }
        }
        else if(r < 60)
        {
            //speed
            lootStats.m_speed += (rand() % level + 1) * 5;

            if(i==0)
            {
                loot.name = "Rune of Wind";
            }
        }
        else if(r < 80)
        {
            //armor
            lootStats.m_armor += (rand() % level + 1) * 1;

            if(i==0)
            {
                loot.name = "Rune of Stone";
            }
        }
        else
        {
            //maxhealth
            lootStats.m_armor += (rand() % level + 1) * 1;

            if(i==0)
            {
                loot.name = "Rune of Stone";
            }
        }
    }

    loot.stats = lootStats;
    return loot;
}

void Loot::horizontalLootsDisplay(vector<Loot> loots)
{
    int cellWidth = 20;

    vector<string> names;
    vector<string> lootsStats;//these are multiline strings
    for(size_t i = 0; i < loots.size(); ++i)
    {
        /*** Stats retrieve ***/
        lootsStats.push_back(loots.at(i).stats.display());
        /*** Name retrieve  ***/
        names.push_back(loots.at(i).name);
    }

    /*** Name Display ***/
    DisplayManager::horizontalDisplay(names, cellWidth);


    string delimiter = "\n";
    bool dowrite = true;
    while(dowrite)
    {
        dowrite = false;
        vector<string> lines;
        for(size_t i = 0; i < lootsStats.size(); ++i)
        {
            string line;
            int pos = lootsStats.at(i).find(delimiter);
            if(pos != string::npos)
            {
                //found end of line
                line = lootsStats.at(i).substr(0, pos);
                lootsStats.at(i).erase(0, pos + delimiter.length());

                dowrite = true;
            }
            else
            {
                //no more lines
                line = " ";
            }

            lines.push_back(line);
        }

        if(dowrite)
        {
            DisplayManager::horizontalDisplay(lines, cellWidth);
        }
    }
}
