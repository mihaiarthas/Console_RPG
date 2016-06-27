#ifndef FRENZYBANDIT_H
#define FRENZYBANDIT_H
#include "hero.h"

class frenzyBandit : public Hero
{
    public:
        frenzyBandit();
        int useAbility(Hero*);
        int basicAttack(Hero*);
    protected:
    private:
};

#endif // FRENZYBANDIT_H
