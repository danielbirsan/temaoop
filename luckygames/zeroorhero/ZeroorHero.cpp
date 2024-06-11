
#include "ZeroorHero.h"

ZeroorHero::ZeroorHero() : LuckyGame() {}

int ZeroorHero::playGame() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    if (dist(gen) == 0) {
        return 100;
    } else {
        return -100;
    }
}

std::unique_ptr<LuckyGame> ZeroorHero::clone() const {
    return std::make_unique<ZeroorHero>(*this);
}

std::string ZeroorHero::getName() const {
    return name;
}