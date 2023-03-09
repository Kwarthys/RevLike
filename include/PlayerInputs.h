#ifndef PLAYERINPUTS_H
#define PLAYERINPUTS_H

#include <iostream>
#include <vector>

using namespace std;

class PlayerInputs
{
    public:
        PlayerInputs();
        virtual ~PlayerInputs();

        static int getPlayerChoice(std::vector<string> options);

    protected:

    private:
};

#endif // PLAYERINPUTS_H
