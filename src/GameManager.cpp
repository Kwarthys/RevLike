#include "GameManager.h"

GameManager::GameManager()
{
    //ctor
}

GameManager::~GameManager()
{
    //dtor
}

void GameManager::manageEncounter(Living* a, Living* b)
{
    int gameCounter = 1;

    Living* fast;
    Living* slow;

    if(a->m_stats->m_speed <= b->m_stats->m_speed)
    {
        fast = a;
        slow = b;
    }
    else
    {
        fast = b;
        slow = a;
    }

    while(a->isAlive() && b->isAlive())
    {
        if(gameCounter % fast->m_stats->m_speed == 0)
        {
            fast->attack(slow);
        }

        if(slow->isAlive())
        {
            if(gameCounter % slow->m_stats->m_speed == 0)
            {
                slow->attack(fast);
            }
        }

        gameCounter++;
    }

}
