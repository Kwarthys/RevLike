#ifndef LIVING_H
#define LIVING_H

class Living
{
    public:
        Living();
        virtual ~Living();

        void takeDamage(int amount);

        int health = 100;
        char* name;

    protected:

    private:
};

#endif // LIVING_H
