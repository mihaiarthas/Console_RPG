#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy
{
    public:
        Enemy();
        virtual int enemyAbility(){}
        virtual int enemyAttack(){}
        int getEnemyHitPoints();
        int getEnemyManaPoints();
        void setEnemyHitPoints(int x);
        void setEnemyManaPoints(int x);
        std::string getEnemyName();
    protected:
        unsigned int enemyHitPoints;
        unsigned int enemyManaPoints;
        std::string enemyName;
    private:
        friend void printHero();
};

#endif // ENEMY_H
