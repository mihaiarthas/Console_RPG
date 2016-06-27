#include "Rogue.h"
#include "Hero.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Rogue::Rogue()
{
    this -> className = "Rogue";
    this -> abilityName = "Mutilate";
    this -> abilityCost = 45;
    this -> mainStat = "STR";
    this -> STR = 21;
    this -> AGI = 27;
    this -> INT = 14;
    this -> hitPoints = 320 + 19 * this -> STR;
    this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 0.7 * this -> AGI;
}
int Rogue::useAbility(Hero *target)
{
    // MUTILATE
    if(this -> manaPoints < this -> abilityCost)
    {
        return 0;
    }
    this -> manaPoints -= this -> abilityCost;
    int dmg = rand() % 3;
    if(dmg == 0) // In case of MARE CRITICALA
    {
        dmg = 23.4 * this -> AGI;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " CRITICAL STRIKE, " << dmg <<" you hit your target from behind with Mutilate." << endl << endl;
        return dmg;
    }
    dmg = 17.2 * this -> AGI;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " You have inflicted " << dmg << " damage with your Mutilate." << endl << endl;
    return dmg;
}
int Rogue::basicAttack(Hero *target)
{
    // Damage random
    cout << " You hit the enemy with your Daggers" << endl;
    int dmg = rand() % 4;
    if(dmg == 0)
    {
        dmg = 17.7 * this -> AGI;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << "CRITICAL STRIKE, " << dmg << " damage with your Daggers" << endl << endl;
        return dmg;
    }
    dmg = 14.5 * this -> AGI;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " You have inflicted " << dmg << " damage with your Daggers." << endl << endl;
    return dmg;
}

