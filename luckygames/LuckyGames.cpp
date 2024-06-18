
#include "LuckyGames.h"
#include "wheelgame/wheelgame.h"
#include "roulettegame/roulettegame.h"
#include "guessgame/guessgame.h"
#include "zeroorhero/ZeroorHero.h"



LuckyGames::LuckyGames() {

    games = {new WheelGame(), new RouletteGame(), new GuessGame(), new ZeroorHero()};
}

LuckyGames::~LuckyGames() {



    for (LuckyGame* game : games) {
        delete game;
    }
    games.clear();
    games.shrink_to_fit();
}

int LuckyGames::playGames() {
    int wonPoints = 0;
    int gameIndex = 0;
    std::cout << "Welcome to the Lucky Game Collection!" << std::endl;
    int tries = 1;
    while (tries) {
        tries=0;
        std::cout << "Choose a game to play (0-" << games.size()  << "):" << std::endl;
        for (unsigned int i=0;i<games.size();i++){
            std::cout << i << " - " << games[i]->getName() << std::endl;
        }
        std::cout << games.size()<< " - Skip" << std::endl;

        if (!(std::cin >> gameIndex) || gameIndex < 0 || gameIndex > 4) {
            std::cout << "Invalid input! Please enter a valid number between 0 and " << games.size() << "." << std::endl;
            tries=1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;

        }

        if (gameIndex == (int)games.size()) {
            break;
        }
        std::unique_ptr<LuckyGame> game = games[gameIndex]->clone();
        wonPoints = game->playGame();
    }
    return wonPoints;

}
