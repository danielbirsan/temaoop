#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
class Player {

private:
    std::string name;
    int attemptsLeft;

public:
    Player() : name("Marcel"), attemptsLeft(0) {}

    Player(std::string  playerName, int attempts) : name(std::move(playerName)), attemptsLeft(attempts) {}

    [[nodiscard]] const std::string& getName() const {
        return name;
    }

    Player& operator=(const Player& _player)= default;

    Player(const Player& player) = default;

    ~Player() = default;

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
    Players() :players(), currentPlayerIndex(0) {}
    void setPlayers(const std::vector<Player> &gamers) {
        Players::players = gamers;
    }
    Player& getCurrentPlayer() {
        return players[currentPlayerIndex];
    }



    Players(const std::vector<std::string>& playerNames, int attempts) : currentPlayerIndex(0) {
        for (const auto& name : playerNames) {
            players.emplace_back(name, attempts);
        }
    }





    [[nodiscard]] bool allPlayersAttempted() const {
        for (const auto& player : players) { // NOLINT(*-use-anyofallof)
            if (player.getAttemptsLeft() > 0) {
                return false;
            }
        }
        return true;
    }

    void nextPlayer() {
        if (!allPlayersAttempted()) {


            std::cout << "WRONG LETTER" << std::endl;

        while (players[currentPlayerIndex].getAttemptsLeft() == 0) {
            currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }}

    [[nodiscard]] const std::vector<Player> &getPlayers() const {
        return players;
    }



};
