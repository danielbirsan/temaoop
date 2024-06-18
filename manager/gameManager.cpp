#include "gameManager.h"
GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

GameManager::GameManager() {
}
void GameManager::playGame() {
    setupPlayers();
    std::string secretWord = GameInitializer::getRandomWord();
    Word word(secretWord);
    Players players(playerNames, difficulties);
    Game::getInstance(word, players).play();

}

void GameManager::setupPlayers() {
    int numPlayers = getIntInput("Enter the number of players: ", 1, 10);

    for (int i = 0; i < numPlayers; ++i) {
        std::string playerName;
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::cin >> playerName;

        int difficulty = getIntInput("Enter difficulty for Player " + std::to_string(i + 1) + " (0 - Easy, 1 - Medium, 2 - Hard): ", 0, 2);

        playerNames.push_back(playerName);
        difficulties.push_back(difficulty);
    }
}
int GameManager::getIntInput(const std::string& prompt, int minVal, int maxVal) {
    int value = 0;
    int tries = 0;
    while (tries < 3) {
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

    if (tries == 3) {
        std::cout << "Too many invalid inputs! Exiting program..." << std::endl;
        std::cout << "For more information, visit: https://www.wikihow.com/Use-a-Computer" << std::endl;
        exit(1);
    }
    return value;
}
