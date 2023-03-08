#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Living.h"
#include "PlayerInputs.h"

class GameManager
{
    public:
        GameManager();
        virtual ~GameManager();

        void manageEncounter(Living* player, Living* monsters[], int monsterNumber);

    protected:

    private:
};

#endif // GAMEMANAGER_H
