

#ifndef OOP_GAMEINITIALIZER_H
#define OOP_GAMEINITIALIZER_H

#include <iostream>
#include <vector>
#include <random>

class GameInitializer {
private:
    static const std::vector<std::string> words;

public:
    static std::string getRandomWord();
};

#endif //OOP_GAMEINITIALIZER_H
