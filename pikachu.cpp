#include "pikachu.h"
#include "pokemon.h"
#include <iostream>
using namespace std;

bool pikachu::addMove(attackMove m)
{
    return pokemon::addMove(m); // inherited from pokemon class
}

void pikachu::decrementHp(int hpAmount)
{
    pokemon::decrementHp(hpAmount);
}

char pikachu::attackPikachu(pikachu& opponent, int moveIndex)
{
    attackMove attack = getMove(moveIndex);
    bool truth = moveUseable(moveIndex);
    if (!moveUseable(moveIndex) || moveIndex < 0 || moveIndex > 5)
    {
       return 'U';  // Unavailable
    }
    moveUsed(moveIndex); // reduce the move that is going to be used
    int randomValue = random.generateRandomNumber() % 100;
    if(randomValue < attack.acc)
    {
        double defensePercentage = static_cast<double>(opponent.getDefense()/100.0);
        opponent.decrementHp(attack.power - (attack.power * defensePercentage));
        return 'H'; // returns H
    }
    else
    {
        return 'M'; // otherwise return M
    }
}

int pikachu::getDefense() const
{
   return pokemon::getDefense();
}

int pikachu::getHp() const
{
    return pokemon::getHp();
}

void pikachu::displayHUD() const
{
    cout << "Pikachu" << endl; // outputs the word Pikachu
    pokemon::displayHUD();
}