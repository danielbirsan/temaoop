
#ifndef OOP_WINNERMANAGER_H
#define OOP_WINNERMANAGER_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include "../player/player.h"
#include "../itempurchase/itemPurchase.h"
#include "../erori/errors.h"

template <typename T>
class WinnerManager {

    WinnerManager() = default;
    ~WinnerManager() = default;
    void finalizeGame();

public:
    static WinnerManager& getInstance() {
        static WinnerManager instance;

        return instance;
    }

    void manageWinner(T& player, const std::string& secretWord);
    WinnerManager(const WinnerManager&) = delete;
    WinnerManager& operator=(const WinnerManager&) = delete;
};

#endif // OOP_WINNERMANAGER_H

