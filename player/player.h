

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Player {
protected:
    std::string name;
    int attemptsLeft;
    int totalWrongLetters;
    int totalCorrectLetters;

public:
    Player();
    Player(std::string  nname, int aattemptsLeft, int ttotalWrongletters, int ttotalCorrectLetters);
    virtual ~Player();

    Player& operator=(const Player& pplayer);
    Player(const Player& gamer);

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getAttemptsLeft() const;
    void setAttemptsLeft(int attempts);
    [[nodiscard]] int getTotalWrongLetters() const;
    [[nodiscard]] int getTotalCorrectLetters() const;
    void setTotalWrongletters(int wrongLetters);
    void setTotalCorrectLetters(int correctLetters);

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

class EasyPlayer : public Player {
public:
    explicit EasyPlayer(const std::string& nname);
};

class MediumPlayer : public Player {
public:
    explicit MediumPlayer(const std::string& nname);
};

class HardPlayer : public Player {
public:
    explicit HardPlayer(const std::string& nname);
};

class Players {
private:
    std::vector<Player> players;
    int currentPlayerIndex;

public:
    Players();
    Players(const std::vector<std::string>& playerNames, const std::vector<int>& difficulties);

    Player& getCurrentPlayer();
    [[nodiscard]] bool allPlayersAttempted() const;
    void nextPlayer();
    const std::vector<Player>& getPlayers() const;

    friend std::ostream& operator<<(std::ostream& os, const Players& pplayers);
};

#endif //OOP_PLAYER_H
