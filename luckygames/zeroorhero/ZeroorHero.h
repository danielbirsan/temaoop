
#ifndef OOP_ZEROORHERO_H
#define OOP_ZEROORHERO_H
#include "../luckygame.h"
#include <random>
#include <memory>


class ZeroorHero : public  LuckyGame {
    std::string name = "Zero or Hero";
public:
    ZeroorHero();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;

        [[nodiscard]] std::string getName() const override;

~ZeroorHero() override = default;
};


#endif //OOP_ZEROORHERO_H
