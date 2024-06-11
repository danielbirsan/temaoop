
#ifndef OOP_LUCKYGAME_H
#define OOP_LUCKYGAME_H


#include <iostream>
#include <memory>
#include <stdexcept>

class LuckyGame {
    std::string name;


public:
    LuckyGame() = default;

    virtual ~LuckyGame() = default;

    [[nodiscard]] virtual int playGame() const = 0;
    [[nodiscard]] virtual std::string getName() const = 0;

    [[nodiscard]] virtual std::unique_ptr<LuckyGame> clone() const = 0;


    LuckyGame(const LuckyGame& other) = default;


protected:
   LuckyGame& operator=(LuckyGame&& other) = default;
    LuckyGame(LuckyGame&& other) = default;
};


#endif //OOP_LUCKYGAME_H
