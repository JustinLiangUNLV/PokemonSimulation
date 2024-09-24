#include <string>
#include "attackMove.h"

#ifndef POKEMON_H
#define POKEMON_H

class pokemon
{
public:
    pokemon() : hp(0), defense(0), amtMoves(0) {} // default constructor to set all variables to 0
    pokemon(int h, int d) : hp(h), defense(d), amtMoves(0) {} // set health and defense accordingly
    bool addMove(attackMove); // insert attackMove into an array, return true if move was added
    void decrementHp(int); // decrements hp from hp, only reaches til 0
    void moveUsed(int); // takes in an index and decrement the specific move, map it to the position in the moves array
    bool moveUseable(int); // returns true or false and see if the move is able to be used, if the amountMoves is 0, then return false

    int getHp() const; // returns hp
    int getDefense() const; // returns defense
    void displayHUD() const; // output health of pokemon and all of their attacks
    attackMove getMove(int) const; // returns move at a certain index
private:
    static const int MAX_MOVES = 4;
    int hp; // health of the pokemon, cannot go negative
    int defense; // how much damage can be absorbed
    int amtMoves; // counter for how many moves inside attackMove array, increment after move added
    attackMove moves[MAX_MOVES];
};

#endif