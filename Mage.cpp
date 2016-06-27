#include "Hero.h"
#include "Mage.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
Mage::Mage()
{
    this -> className = "Mage";
    this -> abilityName = "Fire Blast";
    this -> abilityCost = 115;
    this -> mainStat = "INT";
    this -> STR = 20;
    this -> AGI = 16;
    this -> INT = 27;
    this -> hitPoints = 320 + 19 * this -> STR;
    this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 0.7 * this -> AGI;
}

int Mage::useAbility(Hero *target)
{
    //FIRE BLAST
    // Damage random intre 25 si 40 + 0.5 * INT // COST 30 MANA
    if(this -> manaPoints < this -> abilityCost)
    {
        return 0;
    }
    this -> manaPoints -= this -> abilityCost;
    int dmg = rand() % 4;
    if(dmg == 0) // In case of MARE CRITICALA 55 dmg
    {
        dmg =  21.8 * this -> INT;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " CRITICAL STRIKE, " << dmg <<" damage done with your Fire Blast." << endl << endl;
        return dmg;
    }
    dmg = 13.5 * this -> INT;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " You have inflicted " << dmg << " with your Fire Blast." << endl << endl;
    return dmg;
}
int Mage::basicAttack(Hero *target)
{
    cout << " You hit the enemy with your staff" << endl;
    int dmg = rand() % 4;
    if(dmg == 0)
    {
        dmg = 12.3 * this -> INT;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " CRITICAL STRIKE, " << dmg << " damage with your Staff" << endl << endl;
        return dmg;
    }
    dmg = 6.8 * this -> INT;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " You have inflicted " << dmg << " with your Staff." << endl << endl;
    return dmg;
}


