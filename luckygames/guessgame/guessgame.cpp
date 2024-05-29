#include "guessgame.h"
#include <random>
#include <iostream>

GuessGame::GuessGame() : LuckyGame() {}

int GuessGame::playGame() const {
    int maxTries = 3;
    int value = 0;
    int tries = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    while (tries < maxTries) {
        std::cout << "Guess 0 or 1: ";
        if (!(std::cin >> value) || value < 0 || value > 1) {
            std::cout << "Invalid input! Please enter 0 or 1." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ++tries;
        } else {
            break;
        }
    }

    int randomValue = dis(gen);

    return (value == randomValue) ? 50 : 0;
}

std::unique_ptr<LuckyGame> GuessGame::clone() const {
    return std::make_unique<GuessGame>(*this);
}
