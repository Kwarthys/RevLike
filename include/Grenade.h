#ifndef GRENADE_H
#define GRENADE_H

#include "Consumable.h"


class Grenade : public Consumable
{
    public:
        Grenade();
        virtual ~Grenade();

        void use(Living& player, std::vector<Living*>& monsters) override;
        virtual string display() override;

        int damage = 30;

    protected:

    private:
};

#endif // GRENADE_H
