#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>
#include <sstream>
#include "Living.h"

using namespace std;

class Consumable
{
    public:
        Consumable(string name);
        virtual ~Consumable();

        virtual void use(Living& target);
        virtual string display(){return "Item\n";}

        int charges = 0;

        string name;

    protected:

    private:
};

#endif // CONSUMABLE_H
