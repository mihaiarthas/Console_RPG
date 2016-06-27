#include "enemyGhoul.h"
#include <iostream>
#include <time.h>
#include "Hero.h"
#include <cstdlib>
using namespace std;
enemyGhoul::enemyGhoul()
{
    this -> className = "Ghoul";
    this -> hitPoints = 1000;
    this -> manaPoints = 100;
    this -> abilityName = "Devour";
    this -> abilityCost = 25;
    this -> STR = 0;
    this -> AGI = 0;
    this -> INT = 0;
    //this -> hitPoints = 180 + 19 * this -> STR;
   // this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 20;
}

int enemyGhoul::useAbility(Hero *target)
{
    //DEVOUR // MANA COST 25
    // Random damage intre 130 si 200/ Heal 100 HP
    if(this -> manaPoints >= this -> abilityCost)
    {
        this -> manaPoints -= this -> abilityCost;
        int dmg = rand() % 201;
        int heal = 100;
        if(this -> hitPoints < this -> maxHitPoints - heal) this -> hitPoints += heal;
        if (dmg  < 130) dmg = 130;
        dmg = dmg - dmg * target -> getArmor() / 100;
        cout << " The Ghoul dealt " << dmg << " damage with Devour and healed itself for " << heal << " Hit Points " << endl << endl;
        return dmg;
    }
}
int enemyGhoul::basicAttack(Hero *target)
{
    //Claw
    // Damage random intre 10 si 15
    cout << " The Ghoul hit you with his Claws" << endl;
    int dmg = rand() % 131;
    if(dmg < 70) dmg = 70;
    dmg = dmg - dmg * target -> getArmor() / 100;
    cout << " It has inflicted " << dmg << " damage to you." << endl << endl;
    return dmg;
}
