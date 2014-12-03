//
//  Trainer.cpp
//  CreatureTrainer
//
//  You may NOT #include any .h files we provide you (Battle, Creature, CreatureType,
//  EECSRandom, Party, PrintHelper)
//  other than the ones name "ClassX.h" and "Trainer.h"
//  You may #include other <> libraries if you wish to
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"

//#include "CreatureType.h"

using namespace std;
bool dex_1, dex_2, dex_3, dex_4, dex_5, dex_6, dex_7 = false;
bool dex_8, dex_9, dex_10, dex_11, dex_12, dex_13, dex_14 = false;
bool dex_15, dex_16, dex_17, dex_18, dex_19, dex_20, dex_21 = false;
bool dex_22, dex_23, dex_24, dex_25, dex_26 = false;
int recentDmg = 0;
enemyCreature Axolotyl, Bittern, C_lacanth, Dugong, Echidna, Fossa, Guanaco,
    Honeybdgr, Ibex, Jackal, Kiwi, Loris, Megapode, Narwhal, Ovenbird, Pika, Quagga,
    RockHyrax, Solenodon, Tuatara, Uromastyx, Vaquita, Wolverine, Xenops, Yaminon, Zebu;
enemyCreature enemyTeam[26] = {Axolotyl, Bittern, C_lacanth, Dugong, Echidna, Fossa, Guanaco,
    Honeybdgr, Ibex, Jackal, Kiwi, Loris, Megapode, Narwhal, Ovenbird, Pika, Quagga,
    RockHyrax, Solenodon, Tuatara, Uromastyx, Vaquita, Wolverine, Xenops, Yaminon, Zebu};
ourCreatures creature1, creature2, creature3, creature4;
ourCreatures ourTeam[4] = {creature1, creature2, creature3, creature4};


string activeCreat;
string Trainer::makeMove(stringstream& situation) {

    // pull the entire string out of stringStream& situation
    string situationString = situation.str();
    // situationString now includes ALL of the lines that will be sent to cout
    
    // Here's how to use the stringSplit function
    vector<string> lines = splitString(situationString, "\n");
    // This splits situationString into a vector of individual lines.
    // (it splits on the new line character "\n")
    // To access the 3rd line (as in 0, 1, 2, 3), you would use bracket access
    //   as in: lines[3]
    
    // This loop will iterate through all the lines
    int pipeLine = -1;
    int enemyLine = -1;
    int teamLine = -1;
    // lines.size() tells us how many elements are in the vector<string> lines
    // In this case, it tells us how many lines we pulled in
    for (int i=0; i<lines.size(); i++) {
        // Store each line in the string line
        string line = lines[i];
        // Store the first char of line in the char c
        char c = line[0];
        char mainC = line[6];
        // If c is a pipe ('|'), then this is the line that tells us about our
        //    party and the health of each Creature we own.
        if (c == '|') {
            // Store which line number this is
            pipeLine = i;
        }
        if (c == 'E')
        {
            // Store which line number is the enemy
            enemyLine = i;
        }
        if (c == 'Y')
        {
            for(int x = 0; x < 4; x++)
            {
                if(ourTeam[x].getMain())
                {
                    if(ourTeam[x].getName()[1] == mainC)
                    {
                        teamLine = i;
                    }
                }
            }
        }
    }
    // Now that we know which line has the health, do something with it
    //cout << lines[pipeLine] << "\n"; // Output for testing only
    
    // Split the party health line by pipes "|"
    vector<string> creatureHealthBits = splitString(lines[pipeLine], "|");
    // This gives us something like the vector description below
    /* { "",
         " *Jackal     10/10",
         " Yaminon    17/17",
         " Megapode   13/13",
         " Jackal     10/10",
         "" } */
    // You can see that the first and last pipe caused empty strings
    
    // Now, go through this information and pull out info for each entry
    // We do 1 to <creatureHealthBits.size()-1 because we only need the middle
    //    four elements (and are skipping the empty ones.
    int count = 0; //count for which creature we are on
    for (int i=1; i<creatureHealthBits.size()-1; i++) {
        // cout just for testing
        //cout << creatureHealthBits[i] << "\n";
        
        
        // We are putting the string into a stringStream so we can use >>
        stringstream ss;
        ss << creatureHealthBits[i];
        
        // For example, we have a stringstream ss containing " *Jackal   10/10 "
        // pull the name as a string
        string name;
        string activeCreat;
        ss >> name; // name = "*Jackal"
        
        // pull the health
        int health;
        ss >> health; // health = 10
        
        // Get rid of the slash char
        char slash;
        ss >> slash; // slash = '/'
        
        // get max health
        int maxHealth;
        ss >> maxHealth; // maxHealth = 10
        
        // cout this info for testing purposes
        //cout << "Name: " << name << " health: " << health << "\n";
        switch (count)
        {
            {
            case 0:
                ourTeam[0].setHp(health);
                ourTeam[0].setMaxHp(maxHealth);
                ourTeam[0].setName(name);
                if(ourTeam[0].getName()[0] == '*')
                {
                    ourTeam[0].setMain(true);
                }
                else
                {
                    ourTeam[0].setMain(false);
                }
                break;
            }
            {
                case 1:
                ourTeam[1].setHp(health);
                ourTeam[1].setMaxHp(maxHealth);
                ourTeam[1].setName(name);
                if(ourTeam[1].getName()[0] == '*')
                {
                    ourTeam[1].setMain(true);
                }
                else
                {
                    ourTeam[1].setMain(false);
                }
                break;
            }
            {
            case 2:
                ourTeam[2].setHp(health);
                ourTeam[2].setMaxHp(maxHealth);
                ourTeam[2].setName(name);
                if(ourTeam[2].getName()[0] == '*')
                {
                    ourTeam[2].setMain(true);
                }
                else
                {
                    ourTeam[2].setMain(false);
                }
                break;
            }
            {
            case 3:
                ourTeam[3].setHp(health);
                ourTeam[3].setMaxHp(maxHealth);
                ourTeam[3].setName(name);
                if(ourTeam[3].getName()[0] == '*')
                {
                    ourTeam[3].setMain(true);
                }
                else
                {
                    ourTeam[3].setMain(false);
                }
                break;
            }
        }
        count++;
        
    }
    if(teamLine != -1)
    {
        stringstream ss;
        ss << lines[teamLine];
        string junk, element, elementStren, elementWeak, name;
        int attackD = 0;
        ss >> junk >> junk >> junk >> junk >> name >> junk >> element;
        ss >> junk >> attackD;
        char enemyChar = name[0];
        int baseAttack = attackD;
        if(attackD < 4)
        {
            baseAttack = attackD*2;
            elementStren = element;
            switch(enemyChar)
            {
                case 'A':
                    enemyTeam[0].setElemStren(element);
                    break;
                case 'B':
                    enemyTeam[1].setElemStren(element);
                    break;
                case 'C':
                    enemyTeam[2].setElemStren(element);
                    break;
                case 'D':
                    enemyTeam[3].setElemStren(element);
                    break;
                case 'E':
                    enemyTeam[4].setElemStren(element);
                    break;
                case 'F':
                    enemyTeam[5].setElemStren(element);
                    break;
                case 'G':
                    enemyTeam[6].setElemStren(element);
                    break;
                case 'H':
                    enemyTeam[7].setElemStren(element);
                    break;
                case 'I':
                    enemyTeam[8].setElemStren(element);
                    break;
                case 'J':
                    enemyTeam[9].setElemStren(element);
                    break;
                case 'K':
                    enemyTeam[10].setElemStren(element);
                    break;
                case 'L':
                    enemyTeam[11].setElemStren(element);
                    break;
                case 'M':
                    enemyTeam[12].setElemStren(element);
                    break;
                case 'N':
                    enemyTeam[13].setElemStren(element);
                    break;
                case 'O':
                    enemyTeam[14].setElemStren(element);
                    break;
                case 'P':
                    enemyTeam[15].setElemStren(element);
                    break;
                case 'Q':
                    enemyTeam[16].setElemStren(element);
                    break;
                case 'R':
                    enemyTeam[17].setElemStren(element);
                    break;
                case 'S':
                    enemyTeam[18].setElemStren(element);
                    break;
                case 'T':
                    enemyTeam[19].setElemStren(element);
                    break;
                case 'U':
                    enemyTeam[20].setElemStren(element);
                    break;
                case 'V':
                    enemyTeam[21].setElemStren(element);
                    break;
                case 'W':
                    enemyTeam[22].setElemStren(element);
                    break;
                case 'X':
                    enemyTeam[23].setElemStren(element);
                    break;
                case 'Y':
                    enemyTeam[24].setElemStren(element);
                    break;
                case 'Z':
                    enemyTeam[25].setElemStren(element);
                    break;
            }
            
        }
        else if(attackD > 6)
        {
            baseAttack = attackD/2;
            elementWeak = element;
            //new comment to test commiting changes
            //*************************************
        }
    }
    
    //TO DO NEXT TIME
    
    
    
    if(enemyLine != -1)
    {
        stringstream ss;
        ss << lines[enemyLine];
        string junk, name, element, elementStren, elementWeak;
        int attackD = 0;
        ss >> junk >> name >> junk >> junk >> junk >> junk >> element;
        ss >> junk >> attackD;
        int baseAttack = attackD;
        if(attackD < 4)
        {
            baseAttack = attackD*2;
            elementStren = element;
            
            for(int j = 0; j < 4; j++)
            {
                if(ourTeam[j].getMain())
                {
                    ourTeam[j].setElemStren(elementStren);
                }
            }
        }
        else if(attackD > 6)
        {
            baseAttack = attackD/2;
            elementWeak = element;
            
            for(int j = 0; j < 4; j++)
            {
                if(ourTeam[j].getMain())
                {
                    ourTeam[j].setElemWeak(elementWeak);
                }
            }
            
        }
        if(name == "Axolotyl" && !dex_1)
        {
            enemyTeam[0].setName("Axolotyl");
            enemyTeam[0].setAttack(baseAttack);
            enemyTeam[0].setElem(element);
            dex_1 = true;
        }
        else if(name == "Bittern" && !dex_2)
        {
            enemyTeam[1].setName("Bittern");
            enemyTeam[1].setAttack(baseAttack);
            enemyTeam[1].setElem(element);
            dex_2 = true;
        }
        else if(name == "C-lacanth" && !dex_3)
        {
            enemyTeam[2].setName("C-lacanth");
            enemyTeam[2].setAttack(baseAttack);
            enemyTeam[2].setElem(element);
            dex_3= true;
        }
        else if(name == "Dugong" && !dex_4)
        {
            enemyTeam[3].setName("Dugong");
            enemyTeam[3].setAttack(baseAttack);
            enemyTeam[3].setElem(element);
            dex_4 = true;
        }
        else if(name == "Echidna" && !dex_5)
        {
            enemyTeam[4].setName("Echidna");
            enemyTeam[4].setAttack(baseAttack);
            enemyTeam[4].setElem(element);
            dex_5 = true;
        }
        else if(name == "Fossa" && !dex_6)
        {
            enemyTeam[5].setName("Fossa");
            enemyTeam[5].setAttack(baseAttack);
            enemyTeam[5].setElem(element);
            dex_6 = true;
        }
        else if(name == "Guanaco" && !dex_7)
        {
            enemyTeam[6].setName("Guanaco");
            enemyTeam[6].setAttack(baseAttack);
            enemyTeam[6].setElem(element);
            dex_7 = true;
        }
        else if(name == "Honeybdgr" && !dex_8)
        {
            enemyTeam[7].setName("Honeybdgr");
            enemyTeam[7].setAttack(baseAttack);
            enemyTeam[7].setElem(element);
            dex_8 = true;
        }
        else if(name == "Ibex" && !dex_9)
        {
            enemyTeam[8].setName("Ibex");
            enemyTeam[8].setAttack(baseAttack);
            enemyTeam[8].setElem(element);
            dex_9 = true;
        }
        else if(name == "Jackal" && !dex_10)
        {
            enemyTeam[9].setName("Jackal");
            enemyTeam[9].setAttack(baseAttack);
            enemyTeam[9].setElem(element);
            dex_10 = true;
        }
        else if(name == "Kiwi" && !dex_11)
        {
            enemyTeam[10].setName("Kiwi");
            enemyTeam[10].setAttack(baseAttack);
            enemyTeam[10].setElem(element);
            dex_11 = true;
        }
        else if(name == "Loris" && !dex_12)
        {
            enemyTeam[11].setName("Loris");
            enemyTeam[11].setAttack(baseAttack);
            enemyTeam[11].setElem(element);
            dex_12 = true;
        }
        else if(name == "Megapode" && !dex_13)
        {
            enemyTeam[12].setName("Megapode");
            enemyTeam[12].setAttack(baseAttack);
            enemyTeam[12].setElem(element);
            dex_13 = true;
        }
        else if(name == "Narwhal" && !dex_14)
        {
            enemyTeam[13].setName("Narwhal");
            enemyTeam[13].setAttack(baseAttack);
            enemyTeam[13].setElem(element);
            dex_14 = true;
        }
        else if(name == "Ovenbird" && !dex_15)
        {
            enemyTeam[14].setName("Ovenbird");
            enemyTeam[14].setAttack(baseAttack);
            enemyTeam[14].setElem(element);
            dex_15 = true;
        }
        else if(name == "Pika" && !dex_16)
        {
            enemyTeam[15].setName("Pika");
            enemyTeam[15].setAttack(baseAttack);
            enemyTeam[15].setElem(element);
            dex_16 = true;
        }
        else if(name == "Quagga" && !dex_17)
        {
            enemyTeam[16].setName("Quagga");
            enemyTeam[16].setAttack(baseAttack);
            enemyTeam[16].setElem(element);
            dex_17 = true;
        }
        else if(name == "RockHyrax" && !dex_18)
        {
            enemyTeam[17].setName("RockHyrax");
            enemyTeam[17].setAttack(baseAttack);
            enemyTeam[17].setElem(element);
            dex_18 = true;
        }
        else if(name == "Solenodon" && !dex_19)
        {
            enemyTeam[18].setName("Solenodon");
            enemyTeam[18].setAttack(baseAttack);
            enemyTeam[18].setElem(element);
            dex_19 = true;
        }
        else if(name == "Tuatara" && !dex_20)
        {
            enemyTeam[19].setName("Tuatara");
            enemyTeam[19].setAttack(baseAttack);
            enemyTeam[19].setElem(element);
            dex_20 = true;
        }
        else if(name == "Uromastyx" && !dex_21)
        {
            enemyTeam[20].setName("Uromastyx");
            enemyTeam[20].setAttack(baseAttack);
            enemyTeam[20].setElem(element);
            dex_21 = true;
        }
        else if(name == "Vaquita" && !dex_22)
        {
            enemyTeam[21].setName("Vaquita");
            enemyTeam[21].setAttack(baseAttack);
            enemyTeam[21].setElem(element);
            dex_22 = true;
        }
        else if(name == "Wolverine" && !dex_23)
        {
            enemyTeam[22].setName("Wolverine");
            enemyTeam[22].setAttack(baseAttack);
            enemyTeam[22].setElem(element);
            dex_23 = true;
        }
        else if(name == "Xenops" && !dex_24)
        {
            enemyTeam[23].setName("Xenops");
            enemyTeam[23].setAttack(baseAttack);
            enemyTeam[23].setElem(element);
            dex_24 = true;
        }
        else if(name == "Yaminon" && !dex_25)
        {
            enemyTeam[24].setName("Yaminon");
            enemyTeam[24].setAttack(baseAttack);
            enemyTeam[24].setElem(element);
            dex_25 = true;
        }
        else if(name == "Zebu" && !dex_26)
        {
            enemyTeam[25].setName("Zebu");
            enemyTeam[25].setAttack(baseAttack);
            enemyTeam[25].setElem(element);
            dex_26 = true;
        }
        activeCreat = name;
        recentDmg = attackD;
    }

    // This is something else you can do ONLY for testing.
    // In a previous post, I recommended #including CreatureType.h so that you
    //    can make a Trainer::decide() function that will make the right
    //    decision if you have perfect data about creature types.
    // While developing, you can use the static vector<CreatureType> TYPES to
    //    get that perfect information, though you will eventually need to write
    //    your own function to learn that information from the data that is sent
    //    in via stringstream& situation.
    
/*
    // This makes ct a copy of the CreatureType for Creature 0 (the Axolotyl).
    // All CreatureType and Element names start with a different letter of the
    //    alphabet (CreatureType is A-Z, Element is A-H).
    CreatureType ct = CreatureType::TYPES[0];
    // You can then get the type of ct, which is 0 because it's the Axolotyl
    int type = ct.getType();
    // You can also directly get info from CreatureTypes::TYPES elements.
    int elementalWeakness3 = CreatureType::TYPES[3].getElementalWeakness();
*/
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer 
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    cout << situationString;
    

    /* 
     * This line is basically what your AI chooses to do
     * When first playing, you may type in your move.
     * For both the core and reach portions, however, you need to
     * comment out "cin >> response" and instead have this function
     * generate a response string.
     */
    string response;

    for(int i = 0; i < 4; i++)
    {
        switch (i) {
            case 0:
                if(creature1.getMain())
                {
                    cout << "main: " << creature1.getName();
                }
                break;
            case 1:
                if(creature2.getMain())
                {
                    cout << "main: " << creature2.getName();
                }
                break;
            case 2:
                if(creature3.getMain())
                {
                    cout << "main: " << creature3.getName();
                }
                break;
            case 3:
                if(creature4.getMain())
                {
                    cout << "main: " << creature4.getName();
                }
                break;
            default:
                break;
        }
    }
    response = trainerDecide();
        

    return response;
}


void Trainer::finalSituation(stringstream& situation) {
    cout << situation.str();
    
}



vector<string> Trainer::splitString(string inString, string splitOn) {
    vector<string> elements;
    string substring;
    
    size_t splitIndex = inString.find(splitOn),
    substrStart = 0;
    
    // keep searching until no spaces remain
    while (splitIndex != string::npos) {
        substring = inString.substr(substrStart, splitIndex - substrStart);
        elements.push_back(substring);
        substrStart = splitIndex + 1;
        // start at next character after finding substring
        splitIndex = inString.find(splitOn, substrStart);
    }
    // add last element to vector
    substring = inString.substr(substrStart, inString.length() - substrStart);
    elements.push_back(substring);
    
    return elements;
}
string Trainer::trainerDecide()
{
    int healthiest = getHealthiest();
    if(ourTeam[0].getName()[0] == '*')
    {
        if(ourTeam[0].getHp()<=recentDmg)
        {
            if(ourTeam[healthiest].getHp() >= (recentDmg*2))
            {
                return switchToHealth(healthiest);
            }
            else
            {
                return "a";
            }
        }
        else
        {
            return "a";
        }
    }
    else if(ourTeam[1].getName()[0] == '*')
    {
        if(ourTeam[1].getHp()<=recentDmg)
        {
            if(ourTeam[healthiest].getHp() >= (recentDmg*2))
            {
                return switchToHealth(healthiest);
            }
            else
            {
                return "a";
            }
        }
        else
        {
            return "a";
        }
    }
    else if(ourTeam[2].getName()[0] == '*')
    {
        if(ourTeam[2].getHp()<=recentDmg)
        {
            if(ourTeam[healthiest].getHp() >= (recentDmg*2))
            {
                return switchToHealth(healthiest);
            }
            else
            {
                return "a";
            }
        }
        else
        {
            return "a";
        }
    }
    else
    {
        if(ourTeam[3].getHp()<=recentDmg)
        {
            if(ourTeam[healthiest].getHp() >= (recentDmg*2))
            {
            return switchToHealth(healthiest);
            }
            else
            {
                return "a";
            }
        }
        else
        {
            return "a";
        }
    }
    
}
string Trainer::switchToHealth(int mostHp)
{
    switch(mostHp) {
        case 0:
            return "s1";
            break;
        case 1:
            return "s2";
            break;
        case 2:
            return "s3";
            break;
        case 3:
            return "s4";
            break;
        default:
            return "s1";
            break;
    }
}
int Trainer::getHealthiest()
{
    
    int k = 0, healthiest = 0, healthiestHp = 0, currentHp = 0; //reset the healthiest
    for(k = 0; k < 4; k++)
    {
        currentHp = ourTeam[k].getHp();
        if(currentHp > healthiestHp)
        {
            healthiestHp = ourTeam[k].getHp();
            healthiest = k;
        }
    }
    return healthiest;
}