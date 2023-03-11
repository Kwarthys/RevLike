#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Living.h"
#include "PlayerInputs.h"
#include "Loot.h"
#include "Monster.h"

class GameManager
{
    public:
        GameManager();
        virtual ~GameManager();

        void playGame(Living& player, int numberOfTurn);

        void manageEncounter(Living& player, std::vector<Living*>& monsters);

        void manageLooting(Living& player, std::vector<Loot>& loots);

    protected:

    private:
};

#endif // GAMEMANAGER_H
