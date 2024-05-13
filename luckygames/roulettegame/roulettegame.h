#ifndef OOP_ROULETTEGAME_H
#define OOP_ROULETTEGAME_H

#include "../luckygame.h"
#include <random>
#include <memory>

class RouletteGame : public LuckyGame {
public:
    RouletteGame();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;

    RouletteGame& operator=(const RouletteGame& rouletteGame) = default;
    RouletteGame(const RouletteGame& rouletteGame) = default;
    ~RouletteGame() override = default;
};

#endif // OOP_ROULETTEGAME_H
