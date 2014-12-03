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
ourCreatures::ourCreatures(){}
int ourCreatures::getHp()
{
    return health;
}
int ourCreatures::getMaxHp()
{
    return maxHealth;
}
string ourCreatures::getName()
{
    return name;
}
bool ourCreatures::getMain()
{
    return mainCreat;
}
void ourCreatures::setMain(bool main)
{
    mainCreat = main;
}
void ourCreatures::setHp(int hp)
{
    health = hp;
}
void ourCreatures::setMaxHp(int maxHp)
{
    maxHealth = maxHp;
}
void ourCreatures::setName(string creatName)
{
    name = creatName;
}
void ourCreatures::setElemWeak(string elem)
{
    elemWeak = elem;
}
void ourCreatures::setElemStren(string elem)
{
    elemStren = elem;
}