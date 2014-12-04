//  Class1.cpp
//  Helper Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#include "Class1.h"

ourCreatures::ourCreatures(int hp, int maxHp, string creatName)
{
    setName(creatName);
    setHp(hp);
    setMaxHp(maxHp);

}
ourCreatures::ourCreatures()
{
    setName("none");
    setElemWeak("none");
    setElemStren("none");
    setElem("none");
    setHp(0);
    setMaxHp(0);

}
int ourCreatures::getHp()
{
    return hitPoints;
}
int ourCreatures::getMaxHp()
{
    return maxHitPoints;
}
int ourCreatures::getAttackDmg()
{
    return attackDmg;
}
string ourCreatures::getName()
{
    return pokeName;
}
bool ourCreatures::getMain()
{
    return mainCreat;
}
string ourCreatures::getElemStren()
{
    return elemStren;
}
string ourCreatures::getElemWeak()
{
    return elemWeak;
}
string ourCreatures::getElem()
{
    return element;
}
void ourCreatures::setMain(bool main)
{
    mainCreat = main;
}
void ourCreatures::setHp(int hp)
{
    hitPoints = hp;
}
void ourCreatures::setMaxHp(int maxHp)
{
    maxHitPoints = maxHp;
}
void ourCreatures::setName(string creatName)
{
    pokeName = creatName;
}
void ourCreatures::setAttackDmg(int attack)
{
    attackDmg = attack;
}
void ourCreatures::setElem(string elem)
{
    element = elem;
}
void ourCreatures::setElemWeak(string elem)
{
    elemWeak = elem;
}
void ourCreatures::setElemStren(string elem)
{
    elemStren = elem;
}