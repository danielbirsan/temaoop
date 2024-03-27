#include <iostream>
#include <vector>
#include <algorithm>
#include "player.h"
#include "word.h"

class Game
{
public:
    virtual ~Game()
    {
        std::cout << std::endl;
    }

private:
    Word word;
    Players players;
    void displayGameState(const Player &currentPlayer)
    {
        std::cout << "Current player: " << currentPlayer.getName() << std::endl;
        std::cout << "Attempts left: " << currentPlayer.getAttemptsLeft() - 1 << std::endl;
        std::cout << "Guessed letters: ";
        for (char letter : word.getGuessedLetters())
        {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
        std::cout << "Word: ";
        for (char letter : word.getSecretWord())
        {
            if (std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), letter) != word.getGuessedLetters().end())
            {
                std::cout << letter << " ";
            }
            else
            {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }

    std::string getValidGuess()
    {

        std::string guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        // lowercase the letter
        std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        while (guess.length() != 1 || !isalpha(guess[0]) || std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), guess[0]) != word.getGuessedLetters().end())
        {
            std::cout << "Invalid guess! Enter a proper letter: ";

            std::cin >> guess;
        }

        return guess;
    }

    void updateGameState(const std::string &guess, Player &currentPlayer)
    {

        std::vector<char> guessed = word.getGuessedLetters();
        guessed.push_back(guess[0]);
        word.setGuessedLetters(guessed);
        if (word.getSecretWord().find(guess) == std::string::npos)
        {
            currentPlayer.setAttemptsLeft(currentPlayer.getAttemptsLeft() - 1);
        }
    }

    void deletePlayer()
    {
        std::vector<Player> gamers = players.getPlayers();
        for (auto it = gamers.begin(); it != gamers.end();)
        {
            if (it->getAttemptsLeft() == 0)
            {
                it = gamers.erase(it);
            }
            else
            {
                ++it;
            }
        }
        players.setPlayers(gamers);
    }

    bool isWordGuessed()
    {
        for (char letter : word.getSecretWord())
        { // NOLINT(*-use-anyofallof)
            if (std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), letter) == word.getGuessedLetters().end())
            {
                return false;
            }
        }
        return true;
    }

public:
    Game(Word word, Players players) : word(std::move(word)), players(std::move(players))
    {
    }

    void play()
    {
        bool won = false;
        while (!won && !players.allPlayersAttempted())
        {

            Player &currentPlayer = players.getCurrentPlayer();
            displayGameState(currentPlayer);
            std::string guess = getValidGuess();
            updateGameState(guess, currentPlayer);
            won = isWordGuessed();
            deletePlayer();
            if (!won)
            {
                if (word.getSecretWord().find(guess) == std::string::npos)
                {
                    players.nextPlayer();
                }
            }
        }

        if (won)
        {
            std::cout << "Congratulations! Player " << players.getCurrentPlayer().getName() << " won! The word was: " << word.getSecretWord() << std::endl;
        }
        else
        {
            std::cout << "Sorry, all players are out of attempts. The word was: " << word.getSecretWord() << std::endl;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        os << "Word: " << game.word << std::endl;
        os << "Players: " << std::endl;
        const std::vector<Player> gamers = game.players.getPlayers();
        for (const auto &player : gamers)
        {
            os << player << std::endl;
        }
        return os;
    }
};
