#ifndef GUESSGAME_H
#define GUESSGAME_H

#include "../luckygame.h"
#include <iostream>
#include <memory>
#include <limits>

class GuessGame : public LuckyGame {
public:
    GuessGame();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;
};

#endif // GUESSGAME_H
