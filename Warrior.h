#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include "Hero.h"
class Warrior : public Hero
{
    public:
        Warrior();
        int useAbility(Hero*);
        int basicAttack(Hero*);
    protected:

    private:
};

#endif // WARRIOR_H
