#include <iostream>
#include "Player.h"
#include "Monster.h"

using namespace std;

int main()
{
    char name[30];
    cin >> name;

    Player player(name, 100);

    cout << "Hello " << player.name << endl;

    cout << player.name << " has " << player.health << " HPs" << endl;

    player.takeDamage(50);

    cout << player.name << " has " << player.health << " HPs" << endl;



    return 0;
}
