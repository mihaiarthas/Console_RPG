#include "enemyHellhound.h"
#include <iostream>
#include <time.h>
#include "Hero.h"
#include <cstdlib>
enemyHellhound::enemyHellhound()
{
    this -> className = "Hellhound";
    this -> hitPoints = 2000;
    this -> manaPoints = 500;
    this -> abilityName = "Infernal Bite";
    this -> abilityCost = 500;
    this -> STR = 0;
    this -> AGI = 0;
    this -> INT = 0;
    //this -> hitPoints = 180 + 19 * this -> STR;
   // this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 0;
}

int enemyHellhound::useAbility(Hero *target)
{
    //Annihilate
    int factor = rand() % 3;
    if(factor == 0)
        {
            if(this -> manaPoints >= this -> abilityCost)
            {
                int dmg = 600;
                cout << "The Hellhound annihilated you causing " << dmg << " pure damage ( ignores Armor )" << endl << endl;
                return dmg;
            }
        }
    else
    {
        //Bite
        cout << " The Hellhound bite you" << endl << endl;
        int dmg = rand() % 301;
        if(dmg < 150) dmg = 150;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " It has inflicted " << dmg << " damage to you." << endl << endl;
        return dmg;
    }
}

int enemyHellhound::basicAttack(Hero *target)
{
    //Bite
    cout << " The Hellhound bite you" << endl << endl;
    int dmg = rand() % 301;
    if(dmg < 150) dmg = 150;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " It has inflicted " << dmg << " damage to you." << endl << endl;
    return dmg;
}
