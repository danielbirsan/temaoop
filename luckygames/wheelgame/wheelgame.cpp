#include "wheelgame.h"

WheelGame::WheelGame() : LuckyGame() {}

int WheelGame::playGame() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 30);
    return dist(gen);
}

std::unique_ptr<LuckyGame> WheelGame::clone() const {

    return std::make_unique<WheelGame>(*this);
}

std::string WheelGame::getName() const {
    return name;
}

