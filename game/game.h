
#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <iostream>
#include <utility>
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
    Word word;
    Players players;


    Game(const Word& word, Players players_) : word(word), players(std::move(players_)) {}
    void displayGameState(const Player &currentPlayer);
    void displayAllStatistics();
    std::string getValidGuess();
    void updateGameState(const std::string &guess, Player &currentPlayer);
    bool isWordGuessed();
    void winner();


public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game& getInstance(const Word& word, Players players) {
        static Game instance(word, std::move(players));
        return instance;
    }

    void play();

    friend std::ostream &operator<<(std::ostream &os, const Game &game);

    ~Game()= default;
};



#endif //OOP_GAME_H


