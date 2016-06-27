#include "Hero.h"
#include "Mage.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Hero::Hero()
{}

int Hero::getHitPoints()
{
    return this -> hitPoints;
}

int Hero::getManaPoints()
{
    return this -> manaPoints;
}

void Hero::setHitPoints(int x)
{
    this -> hitPoints = x;
}
void Hero::setManaPoints(int x)
{
    this -> manaPoints = x;
}

string Hero::getClassName()
{
    return this -> className;
}

string Hero::getAbilityName()
{
    return this -> abilityName;
}
void Hero::drainMana(int x)
{
    this -> manaPoints -= x;
}
void Hero::takeDamage(int x)
{
    this -> hitPoints -= x;
}
int Hero::getAbilityCost()
{
    return this -> abilityCost;
}
int Hero::getMaxHitPoints()
{
    return this -> maxHitPoints;
}
int Hero::getSTR()
{
    return this -> STR;
}
int Hero::getAGI()
{
    return this -> AGI;
}
int Hero::getINT()
{
    return this -> INT;
}
std::string Hero::getMainStat()
{
    return this -> mainStat;
}
void Hero::increaseSTR(int x)
{
    this -> STR += x;
}
void Hero::increaseAGI(int x)
{
    this -> AGI += x;
}
void Hero::increaseINT(int x)
{
    this -> INT += x;
}
int Hero::getArmor()
{
    return this -> Armor;
}
void Hero::resetHero()
{
    this -> hitPoints = 180 + 19 * this -> STR;
    this -> manaPoints = 13 * this -> INT;
    this -> maxHitPoints = this -> hitPoints;
    this -> Armor = 0.5 * this -> AGI;
}
