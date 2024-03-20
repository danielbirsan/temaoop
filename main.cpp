#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "game.h"
#include "randomword.h"
int main() {


    std::string secretWord = GameInitializer::getRandomWord();

    Word word(secretWord);

    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

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
