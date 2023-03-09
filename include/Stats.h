#ifndef STATS_H
#define STATS_H

#include <string>
#include <sstream>

class Stats
{
    public:
        Stats();
        virtual ~Stats();

        int m_damage;
        int m_armor;
        int m_speed;
        int m_crit;

        std::string display();

        void add(Stats toAdd);

    protected:

    private:
};

#endif // STATS_H
