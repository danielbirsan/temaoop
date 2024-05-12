#include <iostream>
#include <vector>
#include "game/game.h"
#include "word/word.h"
#include "player/player.h"
#include "GameInitializer/GameInitializer.h"


int getIntInput(const std::string& prompt, int minVal, int maxVal, int maxTries = 3) {
    int value =0;
    int tries = 0;
    while (tries < maxTries) {
        std::cout << prompt;
        if (!(std::cin >> value) || value < minVal || value > maxVal) {
            std::cout << "Invalid input! Please enter a valid number between " << minVal << " and " << maxVal << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ++tries;
        } else {
            break;
        }
    }

    if (tries == maxTries) {
        std::cout << "Too many invalid inputs! Exiting program..." << std::endl;
        std::cout << "For more information, visit: https://www.wikihow.com/Use-a-Computer" << std::endl;
        exit(1);
    }
    return value;
}

void setupPlayers(std::vector<std::string>& playerNames, std::vector<int>& difficulties) {
    int numPlayers = getIntInput("Enter the number of players: ", 1, 10);

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerName;
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::cin >> playerName;
        playerNames.push_back(playerName);

        int difficulty = getIntInput("Enter difficulty for Player " + std::to_string(i + 1) + " (0 - Easy, 1 - Medium, 2 - Hard): ", 0, 2);
        difficulties.push_back(difficulty);
    }
}

int main() {
    std::string secretWord = GameInitializer::getRandomWord();
    Word word(secretWord);

    std::vector<std::string> playerNames;
    std::vector<int> difficulties;

    setupPlayers(playerNames, difficulties);

    Players players(playerNames, difficulties);
    Game game(word, players);

    game.play();

    return 0;
}
