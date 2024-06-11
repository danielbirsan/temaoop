#ifndef GUESSGAME_H
#define GUESSGAME_H

#include "../luckygame.h"
#include <iostream>
#include <memory>
#include <limits>

class GuessGame : public LuckyGame {
    std::string name = "Guess Game";
public:
    GuessGame();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;

    [[nodiscard]] std::string getName() const override;

    ~GuessGame() override = default;



};

#endif // GUESSGAME_H
