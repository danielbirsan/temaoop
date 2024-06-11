#ifndef OOP_ROULETTEGAME_H
#define OOP_ROULETTEGAME_H

#include "../luckygame.h"
#include <random>
#include <memory>

class RouletteGame : public LuckyGame {
    std::string name = "Roulette Game";
public:
    RouletteGame();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;

    RouletteGame& operator=(const RouletteGame& rouletteGame) = delete;
    RouletteGame(const RouletteGame& rouletteGame) = default;
    ~RouletteGame() override = default;
    [[nodiscard]] std::string getName() const override;

};

#endif // OOP_ROULETTEGAME_H
