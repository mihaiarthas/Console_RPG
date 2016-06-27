#include "Warrior.h"
#include "Hero.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
Warrior::Warrior()
{
    this -> className = "Warrior";
    this -> abilityName = "Mortal Strike";
    this -> abilityCost = 100;
    this -> mainStat = "STR";
    this -> STR = 25;
    this -> AGI = 19;
    this -> INT = 16;
    this -> hitPoints = 320 + 19 * this -> STR;
    this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 0.7 * this -> AGI;
}

int Warrior::useAbility(Hero *target)
{
    //MORTAL STRIKE
    // Random damage intre 30 si 45 // COST 40 MANA
    if(this -> manaPoints < this -> abilityCost)
    {
        return 0;
    }
    this -> manaPoints -= this -> abilityCost;
    int dmg = rand() % 3;
    if(dmg == 0) // In case of MARE CRITICALA 60 dmg
    {
        dmg =  25.5 * this -> STR;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " CRITICAL STRIKE, " << dmg <<" damage done with your Mortal Strike." << endl << endl;
        return dmg;
    }
    dmg =  16.3 * this -> STR;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " You have inflicted " << dmg << " damage with your Mortal Strike." << endl << endl;
    return dmg;
}
int Warrior::basicAttack(Hero *target)
{
    // Damage random
    cout << " You hit the enemy with your Battle Axe" << endl;
    int dmg = rand() % 3;
    if(dmg == 0)
    {
        dmg = 15.9 * this -> STR;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " CRITICAL STRIKE, " << dmg << " damage with your Battle Axe" << endl << endl;
        return dmg;
    }
    dmg = 8.2 * this -> STR;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " You have inflicted " << dmg << " damage with your Battle Axe." << endl << endl;
    return dmg;
}
