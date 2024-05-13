
#ifndef OOP_LUCKYGAME_H
#define OOP_LUCKYGAME_H


#include <iostream>
#include <memory>
#include <stdexcept>

class LuckyGame {
public:
    LuckyGame() = default;

    virtual ~LuckyGame() = default;

    virtual int playGame() const = 0;

    [[nodiscard]] virtual std::unique_ptr<LuckyGame> clone() const = 0;

    virtual LuckyGame& operator=(const LuckyGame& other) = default;

    LuckyGame(const LuckyGame& other) = default;
};


#endif //OOP_LUCKYGAME_H
