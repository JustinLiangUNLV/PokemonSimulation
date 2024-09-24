#include "pokemon.h"
#include "pikachu.h"
#include "attackMove.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int args, char * argv[])
{
    ifstream inputFile(argv[1]);
    ifstream inputFile2(argv[2]);

    int defense = 0; // initialize defense and seedAmount to 0
    int seedAmount = 0;
    inputFile >> defense >> seedAmount;
    pikachu player1(50, defense, seedAmount);

    for(int i = 0; i < 4; i++)
    {
        string moveName = "";
        int moveAmount = 0;
        int movePower = 0;
        int moveAccuracy = 0;
        inputFile >> moveName >> moveAmount >> movePower >> moveAccuracy;
        attackMove temp;
        temp.name = moveName;
        temp.amount = moveAmount;
        temp.power = movePower;
        temp.acc = moveAccuracy;
        player1.addMove(temp); // add this into the pikachu object
    }
    inputFile.close();

    int defense2 = 0;
    int seedAmount2 = 0;
    inputFile2 >> defense2 >> seedAmount2;
    pikachu player2(50, defense2, seedAmount2);
    
    for(int i = 0; i < 4; i++)
    {
        string moveName = "";
        int moveAmount = 0;
        int movePower = 0;
        int moveAccuracy = 0;
        inputFile2 >> moveName >> 
        moveAmount >> movePower >> moveAccuracy;
        attackMove temp2;
        temp2.name = moveName;
        temp2.amount = moveAmount;
        temp2.power = movePower;
        temp2.acc = moveAccuracy;
        player2.addMove(temp2);
    }
    inputFile2.close();

    int currentPlayer = 1; // set the current player to 1

    while(player1.getHp() > 0 && player2.getHp() > 0)
    {
        if(currentPlayer == 1)
        {
            cout << "Player 1" << endl;
            player1.displayHUD();
        }
        if(currentPlayer == 2) // else case if currentPlayer == 2
        {
            cout << "Player 2" << endl;
            player2.displayHUD();
        }

        int moveIndex = 0; // initialize the moveIndex to 0
        cout << endl;
        cout << "Enter move index: ";
        cin >> moveIndex;
        cout << moveIndex; // user enters in an index
        int newMoveIndex = moveIndex - 1;
        char outcome = ' '; 

        if(currentPlayer == 1)
        {
            outcome = player1.attackPikachu(player2, newMoveIndex);
        }
        else if(currentPlayer == 2)
        {
            outcome = player2.attackPikachu(player1, newMoveIndex);
        }

        if(outcome == 'U')
        {
            cout << endl;
            cout << "Move not available" << endl;
            cout << endl;
            continue;
        }
        else if(outcome == 'M')
        {
            cout << endl;
            cout << "Attack Missed" << endl;
            cout << endl;
        }
        else if(outcome =='H')
        {
            cout << endl;
            cout << "Attack Hit" << endl;
            cout << endl;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    if(player1.getHp() <= 0)
    {
        cout << "Player 2 Wins" << endl;
    }
    else
    {
        cout << "Player 1 Wins" << endl;
    }

    return 0;
}