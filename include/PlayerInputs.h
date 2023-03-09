#ifndef PLAYERINPUTS_H
#define PLAYERINPUTS_H

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class PlayerInputs
{
    public:
        PlayerInputs();
        virtual ~PlayerInputs();

        static int getPlayerChoice(std::vector<string> options, bool enableCancel = true);
        static void waitPlayerPause();

    protected:

    private:
};

#endif // PLAYERINPUTS_H
