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

        static void horizontalDisplay(vector<string> strings, int cellWidth);

    protected:

    private:
};

#endif // DISPLAYMANAGER_H
