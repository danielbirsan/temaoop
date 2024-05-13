#ifndef OOP_WHEELGAME_H
#define OOP_WHEELGAME_H

#include "../luckygame.h"
#include <random>
#include <memory>

class WheelGame : public LuckyGame {
public:
    WheelGame();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;
};

#endif // OOP_WHEELGAME_H
