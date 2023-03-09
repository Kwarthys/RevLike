#include "PlayerInputs.h"

PlayerInputs::PlayerInputs()
{
    //ctor
}

PlayerInputs::~PlayerInputs()
{
    //dtor
}

int PlayerInputs::getPlayerChoice(std::vector<string> options)
{
    for(std::size_t i = 0; i < options.size(); ++i)
    {
        cout << (i+1) << ": " << options.at(i) << endl;
    }

    cout << "What will you do ?" << endl;
    int response;
    cin >> response;

    return response - 1;
}
