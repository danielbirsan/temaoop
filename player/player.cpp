
#include "player.h"
#include <utility>


Player::Player() : name("Marcel"), attemptsLeft(3), totalWrongLetters(0), totalCorrectLetters(0), points(0) {}

Player::Player(std::string  nname, int aattemptsLeft, int ttotalWrongletters, int ttotalCorrectLetters, int ppoints)
        : name(std::move(nname)), attemptsLeft(aattemptsLeft), totalWrongLetters(ttotalWrongletters), totalCorrectLetters(ttotalCorrectLetters), points(ppoints) {}

Player::~Player() {}

Player& Player::operator=(const Player& pplayer) {
    if (this != &pplayer) {
        name = pplayer.name;
        attemptsLeft = pplayer.attemptsLeft;
        totalWrongLetters = pplayer.totalWrongLetters;
        totalCorrectLetters = pplayer.totalCorrectLetters;
        points = pplayer.points;
    }
    return *this;
}

Player::Player(const Player& gamer)
        : name(gamer.name), attemptsLeft(gamer.attemptsLeft), totalWrongLetters(gamer.totalWrongLetters), totalCorrectLetters(gamer.totalCorrectLetters), points(gamer.points) {}




const std::string& Player::getName() const {
    return name;
}

int Player::getAttemptsLeft() const {
    return attemptsLeft;
}

void Player::decreaseAttemptsLeft() {
    attemptsLeft--;
}

int Player::getTotalWrongLetters() const {
    return totalWrongLetters;
}

int Player::getTotalCorrectLetters() const {
    return totalCorrectLetters;
}

void Player::increaseTotalWrongletters() {
    totalWrongLetters++;
}

void Player::increaseTotalCorrectLetters() {
    totalCorrectLetters++;
}

int Player::getPoints() const {
    return points;
}
void Player::earnPoints(int ppoints) {
    points = ppoints;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.name << std::endl;
    os << "Attempts left: " << player.attemptsLeft << std::endl;
    return os;
}

EasyPlayer::EasyPlayer(const std::string& nname) : Player(nname, 6, 0, 0) {}

MediumPlayer::MediumPlayer(const std::string& nname) : Player(nname, 4, 0, 0) {}

HardPlayer::HardPlayer(const std::string& nname) : Player(nname, 2, 0, 0) {}

Players::Players() : players(), currentPlayerIndex(0) {}

Players::Players(const std::vector<std::string>& playerNames, const std::vector<int>& difficulties)
        : currentPlayerIndex(0) {
    if (playerNames.size() != difficulties.size()) {
        std::cerr << "Error: Number of names must match number of difficulties." << std::endl;
        return;
    }

    for (size_t i = 0; i < playerNames.size(); ++i) {
        if (difficulties[i] == 0) {
            players.emplace_back(EasyPlayer(playerNames[i]));
        } else if (difficulties[i] == 1) {
            players.emplace_back(MediumPlayer(playerNames[i]));
        } else if (difficulties[i] == 2) {
            players.emplace_back(HardPlayer(playerNames[i]));
        } else {
            std::cerr << "Error: Invalid difficulty level for player " << playerNames[i] << std::endl;
        }
    }
}

Player& Players::getCurrentPlayer() {
    return players[currentPlayerIndex];
}

bool Players::allPlayersAttempted() const {
    for (const auto& player : players) {
        if (player.getAttemptsLeft() > 0) {
            return false;
        }
    }
    return true;
}

void Players::nextPlayer() {
    if (!allPlayersAttempted()) {
        std::cout << "WRONG LETTER" << std::endl;
        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
        while (players[currentPlayerIndex].getAttemptsLeft() < 1) {
            currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
        }
    }
}

const std::vector<Player>& Players::getPlayers() const {
    return players;
}

std::ostream& operator<<(std::ostream& os, const Players& pplayers) {
    os << "Players: " << std::endl;
    for (const auto& player : pplayers.players) {
        os << player << std::endl;
    }
    return os;
}
