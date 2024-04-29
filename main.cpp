#include <iostream>
#include <vector>
#include <random>
#include "game.h"
#include "word.h"
#include "player.h"
#include "randomword.h"

int main() {

    std::string secretWord = GameInitializer::getRandomWord();

    Word word(secretWord);

    int numPlayers;
    std::cout << "Enter the number of players: ";

    int tries = 0;
    while (!(std::cin >> numPlayers) || numPlayers <= 0 ) {
        if (tries == 3) {
            std::cout << "Too many invalid inputs! Exiting program..." << std::endl;
            std::cout << "Access this link to learn more: https://www.wikihow.com/Use-a-Computer";
            return 1;}
        std::cout << "Invalid input! Enter another number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        tries++;


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
