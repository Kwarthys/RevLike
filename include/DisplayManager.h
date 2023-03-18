#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class DisplayManager
{
    public:
        DisplayManager();
        virtual ~DisplayManager();

        static void horizontalLineDisplay(vector<string> strings, int cellWidth);

        static void horizontalLinesDisplay(vector<string> multiLineStrings, int cellWidth);

        static void displayEndOfEncounter(){cout << "--------------------------------------" << endl;}
        static void displayEndOfCombatAction(){cout << "--------------------" << endl;}

    protected:

    private:
};

#endif // DISPLAYMANAGER_H
