#ifndef HERO_H
#define HERO_H
#include <string>
using namespace std;

class Hero
{
    public:
        Hero();
        void resetHero();
        virtual int useAbility(Hero*) = 0;
        virtual int basicAttack(Hero*) = 0;
        std::string getMainStat();
        int getHitPoints();
        int getManaPoints();
        int getArmor();
        void setHitPoints(int x);
        void setManaPoints(int x);
        void takeDamage(int x);
        void drainMana(int x);
        std::string getClassName();
        std::string getAbilityName();
        int getAbilityCost();
        int getMaxHitPoints();
        int getSTR();
        int getAGI();
        int getINT();
        void increaseSTR(int);
        void increaseAGI(int);
        void increaseINT(int);
    protected:
        unsigned int hitPoints;
        unsigned int manaPoints;
        std::string className;
        std::string abilityName;
        unsigned int abilityCost;
        unsigned int maxHitPoints;
        unsigned int STR;
        unsigned int AGI;
        unsigned int INT;
        unsigned int Armor;
        std::string mainStat;
    private:
        friend void increases(Hero*, int);
        friend void printHero(Hero*);
        friend int battle();
        friend void battleMP();
};

#endif // HERO_H
