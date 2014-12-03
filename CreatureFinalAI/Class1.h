//
//  Class1.h
//  Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#ifndef __CreatureTrainer__Class1__
#define __CreatureTrainer__Class1__
#include <string>
using namespace std;

// vvvvvv Your implementations go between this line…

class ourCreatures{
public:
    ourCreatures();
    ourCreatures(int hp, int maxHp, string creatName);
    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setName(string creatName);
    void setElemWeak(string elem);
    void setElemStren(string elem);
    int getHp();
    int getMaxHp();
    string getName();
    void setMain(bool main);
    bool getMain();
    
private:
    int health;
    int maxHealth;
    string elemWeak;
    string elemStren;
    string name;
    bool mainCreat;
};



// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */
