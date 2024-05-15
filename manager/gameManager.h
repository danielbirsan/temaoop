#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H


#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../game/game.h"
#include "../word/word.h"
#include "../player/player.h"
#include "./GameInitializer/GameInitializer.h"

class GameManager {
public:
    static GameManager& getInstance();

    void playGame();

private:
    GameManager();

    void setupPlayers();
    static int getIntInput(const std::string& prompt, int minVal, int maxVal);

    std::vector<std::string> playerNames;
    std::vector<int> difficulties;
};

#endif // GAMEMANAGER_H


#endif //OOP_GAMEMANAGER_H
