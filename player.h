#ifndef HANGMAN_PLAYER_H
#define HANGMAN_PLAYER_H
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

class Player
{

private:
    std::string name;
    int attemptsLeft;
    int totalWrongletters;
    int totalCorrectLetters;

public:
    Player() : name("Marcel"), attemptsLeft(3), totalWrongletters(0), totalCorrectLetters(0) {}

    Player(std::string nname, int aattemptsLeft, int ttotalWrongletters, int ttotalCorrectLetters) : name(std::move(nname)),
                                                                                                        attemptsLeft(
                                                                                                                aattemptsLeft),
                                                                                                        totalWrongletters(
                                                                                                                ttotalWrongletters),
                                                                                                        totalCorrectLetters(
                                                                                                                ttotalCorrectLetters) {}

    [[nodiscard]] const std::string &getName() const
    {
        return name;
    }


     ~Player() {
        //destructor


    }

    Player &operator=(const Player &pplayer)
    {
        if (this != &pplayer)
        {
            name = pplayer.name;
            attemptsLeft = pplayer.attemptsLeft;
            totalWrongletters = pplayer.totalWrongletters;
            totalCorrectLetters = pplayer.totalCorrectLetters;
        }
        return *this;
    }

    Player(const Player &gamer) : name(gamer.name), attemptsLeft(gamer.attemptsLeft), totalWrongletters(gamer.totalWrongletters), totalCorrectLetters(gamer.totalCorrectLetters) {}

    [[nodiscard]] int getAttemptsLeft() const
    {
        return attemptsLeft;
    }

    void setAttemptsLeft(int attempts)
    {
        attemptsLeft = attempts;
    }
    [[nodiscard]] int getTotalWrongLetters() const
    {
        return totalWrongletters;
    }
    [[nodiscard]] int getTotalCorrectLetters() const
    {
        return totalCorrectLetters;
    }

    void setTotalWrongletters(int Wrongletters) {
        Player::totalWrongletters = Wrongletters;
    }

    void setTotalCorrectLetters(int CorrectLetters) {
        Player::totalCorrectLetters = CorrectLetters;
    }

    friend std::ostream &operator<<(std::ostream &os, const Player &player)
    {
        os << "Player: " << player.name << std::endl;
        os << "Attempts left: " << player.attemptsLeft << std::endl;
        return os;
    }
};

class Players
{

private:
    std::vector<Player> players;
    int currentPlayerIndex;

public:
    Players() : players(), currentPlayerIndex(0) {}

    [[maybe_unused]] void setPlayers(const std::vector<Player> &gamers)
    {
        Players::players = gamers;
    }
    Player &getCurrentPlayer()
    {
        return players[currentPlayerIndex];
    }

    Players(const std::vector<std::string> &playerNames, int attempts) : currentPlayerIndex(0)
    {
        for (const auto &name : playerNames)
        {
            players.emplace_back(name, attempts, 0, 0);
        }
    }

    [[nodiscard]] bool allPlayersAttempted() const
    {
        for (const auto &player : players)
        {
            if (player.getAttemptsLeft() > 0)
            {
                return false;
            }
        }
        return true;
    }



    void nextPlayer()
    {
        if (!allPlayersAttempted())
        {

            std::cout << "WRONG LETTER" << std::endl;
            currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());

            while (players[currentPlayerIndex].getAttemptsLeft() < 1)
            {
                currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
            }


        }
    }

    [[nodiscard]] const std::vector<Player> &getPlayers() const
    {
        return players;
    }
};

#endif //HANGMAN_PLAYER_H