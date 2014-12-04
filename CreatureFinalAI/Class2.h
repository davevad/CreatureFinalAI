//
//  Class2.h
//  Class2
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#ifndef __CreatureTrainer__Class2__
#define __CreatureTrainer__Class2__
#include <string>
using namespace std;

// vvvvvv Your implementations go between this line…

class enemyCreature{
public:
    enemyCreature();
    enemyCreature(string elem, int attack, string creatName);
    void setElem(string elem);
    void setName(string creatName);
    void setAttack(int attack);
    void setElemWeak(string elem);
    void setElemStren(string elem);
    void setActiveEnemy(bool main);
    string getElemWeak();
    string getElemStren();
    string getElem();
    string getName();
    int getAttack();
    
private:
    string element;
    int maxHitPoints;
    int attackDmg;
    string pokName;
    string elemWeak;
    string elemStren;
    bool activeEnemy;
};



// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class2__) */
