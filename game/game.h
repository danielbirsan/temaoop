
#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../player/player.h"
#include "../word/word.h"
#include "../luckygames/wheelgame/wheelgame.h"
#include "../luckygames/guessgame/guessgame.h"
#include "../luckygames/roulettegame/roulettegame.h"
#include "../luckygames/zeroorhero/ZeroorHero.h"
#include "../erori/errors.h"
#include "../itempurchase/itemPurchase.h"
#include "../winning/WinnerManager.h"



class Game {
private:
    static std::vector<LuckyGame*> games;
    Word word;
    Players players;

    void displayGameState(const Player &currentPlayer);
    void displayAllStatistics();
    std::string getValidGuess();
    void updateGameState(const std::string &guess, Player &currentPlayer);
    bool isWordGuessed();
    void winner();
public:
    Game(const Word& word, Players players);

    void play();






    friend std::ostream &operator<<(std::ostream &os, const Game &game);
};


#endif //OOP_GAME_H


