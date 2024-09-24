#include "pokemon.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool pokemon::addMove(attackMove m)
{
   if(amtMoves < MAX_MOVES) // if amtMoves is less than MAX_MOVES
   {
        moves[amtMoves] = m; // push the attackMove into the array
        amtMoves++; // increment the amoutn of moves
        return true; // returns true
   }
   else
   {
        return false;
   }
}

void pokemon::decrementHp(int amount)
{
    hp -= amount; // decrease the hp by a certain amount
    if(hp < 0) // if hp goes negative, just assign it to zero
    {
        hp = 0;
    }

}

bool pokemon::moveUseable(int moveIndex)
{  
    if(moves[moveIndex].amount > 0) // if the amount is greater than zero
    {
        return true; // is able to use this move
    }
    return false;
}

void pokemon::moveUsed(int moveIndex)
{
    moves[moveIndex].amount--; // decrease the move that has been used
    if(moves[moveIndex].amount < 0)
    {
        moves[moveIndex].amount = 0;
    }
}

attackMove pokemon::getMove(int moveIndex) const
{
    if (moveIndex >= 0 && moveIndex < amtMoves)
    {
        return moves[moveIndex]; // returns the index
    }
    else
    {
        return attackMove(); 
    }
}

int pokemon::getHp() const
{
    return hp; // returns hp
}

int pokemon::getDefense() const
{
    return defense; // returns defense
}

void pokemon::displayHUD() const // iomanip output of the game
{
    cout << "HP: " << getHp() << endl;
    cout << endl;
    cout << "i    " << left;
    cout << setw(17) << "Name" << left;
    cout << setw(5) << "Amt" << left;
    cout << setw(5) << "Pwr" << left;
    cout << setw(3) << "Acc" << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < amtMoves; i++)
    {
        cout << i + 1 << "    " << left;
        cout << setw(17) << moves[i].name << right;
        cout << setw(5) << moves[i].amount << right;
        cout << setw(5) << moves[i].power << right;
        cout << setw(5) << moves[i].acc << endl;
    }
}
