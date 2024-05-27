
#ifndef OOP_ZEROORHERO_H
#define OOP_ZEROORHERO_H
#include "../luckygame.h"
#include <random>
#include <memory>


class ZeroorHero : public  LuckyGame {
public:
    ZeroorHero();

    [[nodiscard]] int playGame() const override;

    [[nodiscard]] std::unique_ptr<LuckyGame> clone() const override;
};


#endif //OOP_ZEROORHERO_H
