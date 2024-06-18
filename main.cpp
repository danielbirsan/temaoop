#include "manager/gameManager.h"



int main() {
    GameManager& gameManager = GameManager::getInstance();
    gameManager.playGame();
}
