#include "frenzyBandit.h"
#include <iostream>
#include <time.h>
#include "Hero.h"
#include <cstdlib>
using namespace std;
frenzyBandit::frenzyBandit()
{
    this -> className = "Frenzy Bandit";
    this -> hitPoints = 1500;
    this -> manaPoints = 265;
    this -> abilityName = "Steal";
    this -> abilityCost = 50;
    this -> STR = 0;
    this -> AGI = 0;
    this -> INT = 0;
    //this -> hitPoints = 180 + 19 * this -> STR;
   // this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 5;
}

int frenzyBandit::useAbility(Hero *target)
{
    //STEAL HP
    if(this -> manaPoints >= this -> abilityCost)
    {
        int dmg = rand() % 301;
        if(dmg < 200) dmg = 200;
        dmg = dmg - dmg * target -> getArmor() / 100;
        if(this->hitPoints < this->maxHitPoints - dmg)
        {
            this -> manaPoints -= this -> abilityCost;
            this->hitPoints += dmg;
            cout << " The Frenzy Bandit stole " << dmg << " health from his target ! " << endl << endl;
            return dmg;
        }
    }
}

int frenzyBandit::basicAttack(Hero *target)
{
    //Kick
    cout << " The Frenzy Bandit kicked you" << endl << endl;
    int dmg = rand() % 201;
    if(dmg < 130) dmg = 130;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " It has inflicted " << dmg << " damage to you." << endl << endl;
    return dmg;
}
