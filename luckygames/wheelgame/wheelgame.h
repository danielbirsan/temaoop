#ifndef OOP_WHEELGAME_H
#define OOP_WHEELGAME_H

#include "../luckygame.h"
#include <random>
#include <memory>
#include <chrono>
#include <thread>
#include <random>

class WheelGame : public LuckyGame {
    std::string name = "Wheel Game";
public:
    WheelGame();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;

    [[nodiscard]] std::string getName() const override;

    ~WheelGame() override = default;
};

#endif // OOP_WHEELGAME_H
