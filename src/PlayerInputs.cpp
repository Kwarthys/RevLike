#include "PlayerInputs.h"

PlayerInputs::PlayerInputs()
{
    //ctor
}

PlayerInputs::~PlayerInputs()
{
    //dtor
}

int PlayerInputs::getPlayerChoice(std::vector<string> options, bool enableCancel)
{
    for(std::size_t i = 0; i < options.size(); ++i)
    {
        cout << (i+1) << ": " << options.at(i) << endl;
    }

    if(enableCancel)
    {
        cout << "0 : Cancel" << endl;
    }

    cout << "What will you do ?" << endl;
    int response;
    cin >> response;

    return response - 1;
}

void PlayerInputs::waitPlayerPause(bool ignore)
{
    cout << "\nPress Enter to continue";
    if(ignore)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //does not work twice in a row
    }
    cin.get();
    cout << endl;
}
