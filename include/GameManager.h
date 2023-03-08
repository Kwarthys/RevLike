#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Living.h"

class GameManager
{
    public:
        GameManager();
        virtual ~GameManager();

        void manageEncounter(Living* a, Living* b);

    protected:

    private:
};

#endif // GAMEMANAGER_H
