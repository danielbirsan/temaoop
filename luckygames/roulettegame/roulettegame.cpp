#include "roulettegame.h"

RouletteGame::RouletteGame() : LuckyGame() {}

    int RouletteGame::playGame() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);

    int first = dist(gen);
    int second = dist(gen);
    int third = dist(gen);
    std::cout << "Roulette: " << first << " " << second << " " << third << std::endl;

    if (first == second && second == third) {
        return 100;
    } else if (first == second || second == third || first == third) {
        return 30;
    } else {
        return 0;
    }
}

std::unique_ptr<LuckyGame> RouletteGame::clone() const {
    return std::make_unique<RouletteGame>(*this);
}

std::string RouletteGame::getName() const {
    return name;
}