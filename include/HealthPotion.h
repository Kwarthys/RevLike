#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Consumable.h"

using namespace std;

class HealthPotion : public Consumable
{
    public:
        HealthPotion();
        virtual ~HealthPotion();

        void use(Living& player, std::vector<Living*>& monsters) override;
        virtual string display() override;

        int healAmount = 50;

    protected:

    private:
};

#endif // HEALTHPOTION_H
