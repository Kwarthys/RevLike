#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
    //ctor
}

DisplayManager::~DisplayManager()
{
    //dtor
}

 void DisplayManager::horizontalDisplay(vector<string> strings, int cellWidth)
 {
    ostringstream stringBuilder;

    for(size_t i = 0; i < strings.size(); ++i)
    {
        int spaceLeft = cellWidth - strings.at(i).size();
        stringBuilder << '|' << strings.at(i);

        for(int si = 0; si < spaceLeft; ++si)
        {
            stringBuilder << ' ';//padding
        }
    }

    cout << stringBuilder.str() << endl;
 }
