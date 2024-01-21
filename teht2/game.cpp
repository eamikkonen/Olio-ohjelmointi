#include "game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Game::Game(int max)
{
    maxNumber = max;
    numOfGuesses = 0;

    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{
    while (playerGuess != randomNumber)
    {
        cout << "Arvaa luku 1-" << maxNumber << ": " << endl;
        cin >> playerGuess;

        if (playerGuess > randomNumber)
        {
            cout << "Liian suuri" << endl << endl;
        }
        else if (playerGuess < randomNumber)
        {
            cout << "Liian pieni" << endl << endl;
        }
        else
        {
            cout << "Arvasit oikein!" << endl;
            numOfGuesses += 1;
            printGameResult();
        }

        numOfGuesses += 1;

    }
};

void Game::printGameResult()
{
    cout << "Pelin tulokset:" << endl << "Arvauksien määrä: " << numOfGuesses << endl;
}
