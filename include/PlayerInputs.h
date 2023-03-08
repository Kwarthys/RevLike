#ifndef PLAYERINPUTS_H
#define PLAYERINPUTS_H

#include <iostream>

using namespace std;

class PlayerInputs
{
    public:
        PlayerInputs();
        virtual ~PlayerInputs();

        static int getPlayerChoice(string* options, int numberOfOptions);

    protected:

    private:
};

#endif // PLAYERINPUTS_H
