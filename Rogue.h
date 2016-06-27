#ifndef ROGUE_H
#define ROGUE_H
#include "Hero.h"

class Rogue : public Hero
{
    public:
        Rogue();
        int useAbility(Hero*);
        int basicAttack(Hero*);
    protected:
    private:
};

#endif // ROGUE_H
