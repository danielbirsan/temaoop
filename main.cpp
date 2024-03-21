#include <iostream>
#include <vector>
#include <random>
#include "game.h"
#include "randomword.h"

#include <windows.h>


int main() {
    SetConsoleOutputCP( 65001 );

    system("chcp 65001");



    std::string secretWord = GameInitializer::getRandomWord();

    Word word(secretWord);

    int numPlayers;
    std::cout << "Enter the number of players: ";
    //make sure the input is an integer posivi number
    while (!(std::cin >> numPlayers) || numPlayers <= 0) {
        std::cout << "Invalid input! Enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }




    std::vector<std::string> playerNames;
    for (int i = 1; i <= numPlayers; ++i) {
        std::string playerName;
        std::cout << "Enter name for Player " << i << ": ";
        std::cin >> playerName;
        playerNames.push_back(playerName);
    }

    Players players(playerNames, 3+1);
    Game game(word, players);
    game.play();

    return 0;
}
