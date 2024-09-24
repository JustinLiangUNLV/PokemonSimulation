#include "pokemon.h"
#include "rnd.h"
#include "attackMove.h"
#include <string>

#ifndef PIKACHU_H
#define PIKACHU_H

class pikachu : pokemon // inherit from pokemon, everything in pokemon class will be copied to this class but all members will be private in this class
{
public:
    pikachu() : pokemon(), random(0) {}
    pikachu(int hp, int defense, int seed) :
        pokemon(hp, defense), random(seed) {} // set hp and defense

    bool addMove(attackMove); // insert this into move array by calling certain functions in pokemon header
    void decrementHp(int);
    char attackPikachu(pikachu&, int);

    int getDefense() const;
    int getHp() const;
    void displayHUD() const; // cout pikachu and call the function to display hud
private:
    rnd random;
};

#endif