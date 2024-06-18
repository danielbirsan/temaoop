#include "wheelgame.h"

WheelGame::WheelGame() : LuckyGame() {}



// Function to simulate a delay generated to complete the task
void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Function to display the roulette wheel generated to complete the task
void displayRoulette(const std::vector<int>& roulette, int highlightIndex) {
    for (size_t i = 0; i < roulette.size(); ++i) {
        if ((int)i == highlightIndex) {
            std::cout << "[" << roulette[i] << "] ";
        } else {
            std::cout << roulette[i] << " ";
        }
    }
    std::cout << std::endl;
}

int WheelGame::playGame() const {

    std::vector<int> roulette = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, (int)roulette.size() - 1);
    int position = dist(gen);
    int spins = 5;
    for (int i = 0; i < spins; ++i) {
        displayRoulette(roulette, position);
        position = (position + 1) % (int)roulette.size();
        delay(100);
    }

    displayRoulette(roulette, position);
    std::cout << "The ball landed on " << roulette[position] << "!" << std::endl;

    return roulette[position];
}

std::unique_ptr<LuckyGame> WheelGame::clone() const {

    return std::make_unique<WheelGame>(*this);
}

std::string WheelGame::getName() const {
    return name;
}

