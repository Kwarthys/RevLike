#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Consumable.h"

using namespace std;

class HealthPotion : public Consumable
{
    public:
        HealthPotion(string name);
        virtual ~HealthPotion();

        int healAmount = 50;

    protected:

    private:
};

#endif // HEALTHPOTION_H
