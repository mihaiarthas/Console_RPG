#ifndef MAGE_H
#define MAGE_H
#include "Hero.h"
#include <string>

class Mage : public Hero
{
    public:
        Mage();
        int useAbility(Hero*);
        int basicAttack(Hero*);

    protected:
    private:
};

#endif // MAGE_H
