
#ifndef OOP_LUCKYGAMES_H
#define OOP_LUCKYGAMES_H

#include <vector>
#include "../luckygame.h"


class LuckyGames {
     std::vector<LuckyGame*> games;
    LuckyGames();


public:

    ~LuckyGames();
    static LuckyGames& getInstance() {
        static LuckyGames instance;
        return instance;
    }

    int playGames();
    LuckyGames(LuckyGames const&) = delete;
    void operator=(LuckyGames const&) = delete;

};


#endif //OOP_LUCKYGAMES_H
