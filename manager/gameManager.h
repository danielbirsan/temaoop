#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../game/game.h"
#include "../word/word.h"
#include "../player/player.h"
#include "./GameInitializer/GameInitializer.h"

class GameManager {

    GameManager();
    void setupPlayers();
    static int getIntInput(const std::string& prompt, int minVal, int maxVal);

    std::vector<std::string> playerNames;
    std::vector<int> difficulties;
public:
    static GameManager& getInstance();
    void playGame();
    GameManager(const GameManager&) = delete;

    GameManager& operator=(const GameManager&) = delete;

};

#endif //OOP_GAMEMANAGER_H
