#ifndef ENEMYGHOUL_H
#define ENEMYGHOUL_H
#include "Hero.h"

class enemyGhoul : public Hero
{
    public:
        enemyGhoul();
        int useAbility(Hero*);
        int basicAttack(Hero*);

    protected:
    private:
};

#endif // ENEMYGHOUL_H
