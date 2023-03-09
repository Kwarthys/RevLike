#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Living.h"
#include "PlayerInputs.h"

class GameManager
{
    public:
        GameManager();
        virtual ~GameManager();

        void manageEncounter(Living& player, std::vector<Living*>& monsters);

    protected:

    private:
};

#endif // GAMEMANAGER_H
