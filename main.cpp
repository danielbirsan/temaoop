#include <iostream>
#include <vector>
#include <random>
#include "game.h"
#include "randomword.h"
int main() {


    std::string secretWord = GameInitializer::getRandomWord();

    Word word(secretWord);
    int start=1;

    int numPlayers;
    while (start) {

        std::cout << "Enter the number of players: ";
        std::cin >> numPlayers;

        std::vector<std::string> playerNames;
        for (int i = 1; i <= numPlayers; ++i) {
            std::string playerName;
            std::cout << "Enter name for Player " << i << ": ";
            std::cin >> playerName;
            playerNames.push_back(playerName);
        }

        Players players(playerNames, 3 + 1);
        Game game(word, players);
        game.play();

        std::cout << "Do you want to play again? (1/0): ";
        std::cin >> start;

        if (start != 1) {
            break;
        }

    }
    return 0;
}
