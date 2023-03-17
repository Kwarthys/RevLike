#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "HealthPotion.h"
#include "Consumable.h"
#include "Living.h"
#include "PlayerInputs.h"
#include "Loot.h"
#include "Player.h"
#include "MonsterFactory.h"

class GameManager
{
    public:
        GameManager();
        virtual ~GameManager();

        void playGame(Player& player, int numberOfTurn);

        void manageEncounter(Player& player, std::vector<Living*>& monsters);

        bool manageAttacks(Living& player, std::vector<Living*>& monsters);
        bool manageItems(Player& player, std::vector<Living*>& monsters);       //Player here cause we need the inventory

        void manageMonstersTurn(Living& player, std::vector<Living*>& monsters);

        void manageLooting(Living& player, std::vector<Loot>& loots);

    protected:

    private:
};

#endif // GAMEMANAGER_H
