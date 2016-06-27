#ifndef ENEMYHELLHOUND_H
#define ENEMYHELLHOUND_H
#include "hero.h"

class enemyHellhound : public Hero
{
    public:
        enemyHellhound();
        int useAbility(Hero*);
        int basicAttack(Hero*);
    protected:
    private:
};

#endif // ENEMYHELLHOUND_H
