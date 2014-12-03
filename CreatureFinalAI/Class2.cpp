//  Class2.cpp
//  Helper Class2
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#include "Class2.h"

enemyCreature::enemyCreature(){
    setElem("none");
    setAttack(0);
    setName("none");
}
enemyCreature::enemyCreature(string elem, int attack, string creatName)
{
    setElem(elem);
    setAttack(attack);
    setName(creatName);
}
void enemyCreature::setElem(string elem)
{
    element = elem;
}
void enemyCreature::setAttack(int attack)
{
    attackDmg = attack;
}
void enemyCreature::setName(string creatName)
{
    name = creatName;
}
string enemyCreature::getElem()
{
    return element;
}
int enemyCreature::getAttack()
{
    return attackDmg;
}
string enemyCreature::getName()
{
    return name;
}
void enemyCreature::setElemWeak(string elem)
{
    elemWeak = elem;
}
void enemyCreature::setElemStren(string elem)
{
    elemStren = elem;
}
