#include "Hero.h"
#include "Mage.h"
#include "Warrior.h"
#include "enemyGhoul.h"
#include "Rogue.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "frenzyBandit.h"
#include "enemyHellhound.h"
using namespace std;

void battleMP(Hero *hero1, Hero *hero2)
{
    cout << hero1->getClassName() << " Versus " << hero2->getClassName() << endl << endl;
    int p = 1,input;
    while(p)
    {
        if(hero1->getHitPoints() <= 0)
        {
            cout << " PLAYER 2 WON " << endl;
            break;
        }
        if(hero2->getHitPoints() <= 0)
        {
            cout << " PLAYER 1 WON " << endl;
            break;
        }
        cout << " PLAYER 1 " << endl;
        printHero(hero1);
        cout << " PLAYER 2 " << endl;
        printHero(hero2);
        cout << " PLAYER 1 TURN" << endl << endl;
        cout << "1. Basic Attack - no cost" << endl << "2. Use Ability - "<< hero1 -> getAbilityCost() << " mana cost." << endl << endl;
        cin >> input;
        if(input == 1)
            hero2 -> takeDamage(hero1 -> basicAttack(hero2));
        if(input == 2)
            {
                if(hero1 -> getManaPoints() < hero1 -> getAbilityCost())
                {
                    cout << "NOT ENOUGH MANA !!!" << endl << endl;
                    system("pause");
                    system("CLS");
                    continue;
                }
                hero2 -> takeDamage(hero1 -> useAbility(hero2));
            }
        if(hero1->getHitPoints() <= 0)
        {
            cout << " PLAYER 2 WON " << endl;
            system("pause");
            break;
        }
        if(hero2->getHitPoints() <= 0)
        {
            cout << " PLAYER 1 WON " << endl;
            system("pause");
            break;
        }
        system("pause");
        system("CLS");
        cout << " PLAYER 1 " << endl;
        printHero(hero1);
        cout << " PLAYER 2 " << endl;
        printHero(hero2);
        cout << " PLAYER 2 TURN" << endl << endl;
        cout << "1. Basic Attack - no cost" << endl << "2. Use Ability - "<< hero2 -> getAbilityCost() << " mana cost." << endl << endl;
        cin >> input;
        if(input == 1)
            hero1 -> takeDamage(hero2 -> basicAttack(hero1));
        if(input == 2)
            {
                if(hero2 -> getManaPoints() < hero2 -> getAbilityCost())
                {
                    cout << "NOT ENOUGH MANA !!!" << endl << endl;
                    system("pause");
                    system("CLS");
                    continue;
                }
                hero1 -> takeDamage(hero2 -> useAbility(hero1));
            }
        system("pause");
        system("cls");
    }
}
int battle(Hero *hero, Hero *enemy)
{
    int factor,q = 0,input,p = 1;
    cout << endl << " You have encountered a " << enemy -> getClassName() << "." << endl << endl;
    while(p)
    {
        if(enemy -> getHitPoints() <= 0)
        {
            cout << " YOU WON !!!" << endl;
            system("pause");
            if(enemy -> getClassName() == "Hellhound")
            {
                break;
            }
            increases(hero,15);
            break;
        }
        if(hero -> getHitPoints() <= 0)
        {
            cout << " YOU LOST !!! PLEASE RESTART GAME" << endl;
            system("pause");
            return -1;
        }
        printHero(hero);
        printHero(enemy);
        cout << " 1. Basic Attack - no cost" << endl << " 2. Use Ability - "<< hero -> getAbilityCost() << " mana cost." << endl << endl;
        cin >> input;
        if(input == 1)
            enemy -> takeDamage(hero -> basicAttack(enemy));
        if(input == 2)
            {
                if(hero -> getManaPoints() < hero -> getAbilityCost())
                {
                    cout << "NOT ENOUGH MANA !!!" << endl << endl;
                    system("pause");
                    system("CLS");
                    continue;
                }
                enemy -> takeDamage(hero -> useAbility(enemy));
            }
        if(enemy -> getManaPoints() >= enemy -> getAbilityCost())
        {
            factor = rand() % 2;
            if(factor == 0)
            hero -> takeDamage(enemy -> basicAttack(hero));
            if(factor == 1 && enemy -> getClassName() == "Ghoul" && enemy -> getHitPoints() <= enemy -> getMaxHitPoints() - 100)
                {
                    hero -> takeDamage(enemy -> useAbility(hero));
                    factor = 3;
                }
            if(factor == 1)
            hero -> takeDamage(enemy -> useAbility(hero));

        }
        else
            hero -> takeDamage(enemy -> basicAttack(hero));
        system("pause");
        system("CLS");
    }
}

void increases(Hero* aux, int x)
{
    system("cls");
    int input;
    aux -> resetHero();
    while(x != 0)
    {
        cout << " Choose what stat point to increase : " << endl << " 1. STR    2. AGI    3. INT " << endl;
        cout << " Points left : " << x << endl;
        aux -> resetHero();
        printHero(aux);
        cin >> input;
        cout << endl;
        if(input == 1) aux -> increaseSTR(1);
        if(input == 2) aux -> increaseAGI(1);
        if(input == 3) aux -> increaseINT(1);
        x--;
        system("cls");
    }
    cout << " Choose what stat point to increase : " << endl << " 1. STR    2. AGI    3. INT " << endl;
    cout << " Points left : " << x << endl;
    aux -> resetHero();
    printHero(aux);
    cout << endl;
    system("pause");
    system("cls");
}


void printHero(Hero *aux)
{
    cout <<"    CLASS : " << aux->getClassName() << endl;
    cout <<"    Current Hit Points = " << aux->getHitPoints() << endl;
    cout <<"    Current Mana Points = " << aux->getManaPoints() << endl;
    cout <<"    Armor = " << aux->getArmor() << endl;
    cout <<"    STR = " << aux->getSTR() << "  AGI = " << aux->getAGI() << "  INT = " << aux->getINT() << endl << endl;
}

int main()
{
    int input;
    srand(time(NULL));
    system("Color F6");
    cout << endl;
    cout << " Things you should know: " << endl << " Your main stat increases your Hero`s damage." << endl;
    cout << " 1 STR = 19 HP , 1 INT = 13 MP , 1 AGI = 0.7 Armor " << endl << endl;
    system("pause");
    system("CLS");
    cout << endl;
    cout << "  MAIN MENU :" << endl << "  1.SINGLE PLAYER" << endl << "  2.MULTIPLAYER" << endl;
    cin >> input;
    if(input == 1)
    {
        int cont;
        system("cls");
        cout << "     Choose your class : " << endl << endl << " 1. Warrior - Main stat = Strength" << endl << endl;
        cout << " 2. Rogue - Main Stat = Agility" << endl << endl;
        cout << " 3. Mage - Main Stat = Intelligence" << endl << endl;
        Hero *actor;
        cin >> input;
        system("cls");
        if(input == 1)
        {
            actor = new Warrior;
            system("Color 40");
        }
        if(input == 2)
        {
            actor = new Rogue;
            system("Color 3F");
        }
        if(input == 3)
        {
            actor = new Mage;
            system("Color 5E");
        }
        Hero *war1 = new enemyGhoul;
        cont = battle(actor,war1);
        if (cont == -1) return 0;
        actor -> resetHero();
        system("cls");
        Hero *war2 = new frenzyBandit;
        cont = battle(actor,war2);
        if (cont == -1) return 0;
        actor -> resetHero();
        system("cls");
        Hero *war3 = new enemyHellhound;
        cont = battle(actor,war3);
        if(cont == -1) return 0;
        return 0;
    }
    if(input == 2)
    {
        Hero *actor1,*actor2;
        int input;
        system("Color 74");
        system("cls");
        cout << "     PLAYER ONE , CHOOSE YOUR HERO !" << endl << endl;
        cout << "     Choose your class : " << endl << endl << " 1. Warrior - Main stat = Strength" << endl << endl;
        cout << " 2. Rogue - Main Stat = Agility" << endl << endl;
        cout << " 3. Mage - Main Stat = Intelligence" << endl << endl;
        cin >> input;
        if(input == 1)
        {
            actor1 = new Warrior;
        }
        if(input == 2)
        {
            actor1 = new Rogue;
        }
        if(input == 3)
        {
            actor1 = new Mage;
        }
        system("cls");
        cout << "     PLAYER TWO , CHOOSE YOUR HERO !" << endl << endl;
        cout << "     Choose your class : " << endl << endl << " 1. Warrior - Main stat = Strength" << endl << endl;
        cout << " 2. Rogue - Main Stat = Agility" << endl << endl;
        cout << " 3. Mage - Main Stat = Intelligence" << endl << endl;
        cin >> input;
        if(input == 1)
        {
            actor2 = new Warrior;
        }
        if(input == 2)
        {
            actor2 = new Rogue;
        }
        if(input == 3)
        {
            actor2 = new Mage;
        }
        system("cls");
        battleMP(actor1,actor2);
        return 0;
    }
    return 0;
}
