#include <iostream>
#include <vector>
#include <algorithm>


class Player {
    std::string name;
    int attemptsLeft;

public:
    Player(const std::string& playerName, int attempts) : name(playerName), attemptsLeft(attempts) {}

    const std::string& getName() const {
        return name;
    }

    int getAttemptsLeft() const {
        return attemptsLeft;
    }

    void setAttemptsLeft(int attempts) {
        attemptsLeft = attempts;
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Player: " << player.name << std::endl;
        os << "Attempts left: " << player.attemptsLeft << std::endl;
        return os;
    }
};

class Players {
    std::vector<Player> players;
    int currentPlayerIndex;

public:


    Players(const std::vector<std::string>& playerNames, int attempts) : currentPlayerIndex(0) {
        for (const auto& name : playerNames) {
            players.emplace_back(name, attempts);
        }
    }

    Player& getCurrentPlayer() {
        return players[currentPlayerIndex];
    }

    void nextPlayer() {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    bool allPlayersAttempted() const {
        for (const auto& player : players) {
            if (player.getAttemptsLeft() > 0) {
                return false;
            }
        }
        return true;
    }

    const std::vector<Player> &getPlayers() const {
        return players;
    }



};
