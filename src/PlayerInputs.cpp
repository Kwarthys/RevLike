#include "PlayerInputs.h"

PlayerInputs::PlayerInputs()
{
    //ctor
}

PlayerInputs::~PlayerInputs()
{
    //dtor
}

int PlayerInputs::getPlayerChoice(string* options, int numberOfOptions)
{
    cout << "What will you do ?" << endl;
    for(int i = 0; i < numberOfOptions; ++i)
    {
        cout << i << ": " << options[i] << endl;
    }

    int response;
    cin >> response;

    return response - 1;
}
