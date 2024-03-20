#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


class Player {
    std::string name;
    int attemptsLeft;

public:
    Player(std::string  playerName, int attempts) : name(std::move(playerName)), attemptsLeft(attempts) {}

      Player&  operator=(const Player &rhs) {
        name = rhs.name;
        attemptsLeft = rhs.attemptsLeft;
        return *this;
    }



    virtual ~Player() = default;

    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    [[nodiscard]] int getAttemptsLeft() const {
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

private:
    std::vector<Player> players;
    int currentPlayerIndex;

public:
    void setPlayers(const std::vector<Player> &gamers) {
        Players::players = gamers;
    }



    Players(const std::vector<std::string>& playerNames, int attempts) : currentPlayerIndex(0) {
        for (const auto& name : playerNames) {
            players.emplace_back(name, attempts);
        }
    }

    Player& getCurrentPlayer() {
        return players[currentPlayerIndex];
    }



    [[nodiscard]] bool allPlayersAttempted() const {
        for (const auto& player : players) {
            if (player.getAttemptsLeft() > 0) {
                return false;
            }
        }
        return true;
    }

    void nextPlayer() {
        if (!allPlayersAttempted()) {
            std::cout << "NEXT" << std::endl;




        while (players[currentPlayerIndex].getAttemptsLeft() == 0) {
            currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }}

    [[nodiscard]] const std::vector<Player> &getPlayers() const {
        return players;
    }



};
