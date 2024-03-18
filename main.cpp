#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include "player.h"
class Word {
    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    bool operator==(const Word &rhs) const {
        return secretWord == rhs.secretWord && guessedLetters == rhs.guessedLetters;
    }

    bool operator!=(const Word &rhs) const {
        return !(rhs == *this);
    }

    explicit Word(std::string word) : secretWord(std::move(word)) {}

    [[nodiscard]] const std::string& getSecretWord() const {
        return secretWord;
    }

    [[nodiscard]] const std::vector<char>& getGuessedLetters() const {
        return guessedLetters;
    }

    void setGuessedLetters(const std::vector<char>& guessed) {
        guessedLetters = guessed;
    }


    friend std::ostream& operator<<(std::ostream& os, const Word& word) {
        os << "Secret word: " << word.secretWord << std::endl;
        os << "Guessed letters: ";
        for (char letter : word.guessedLetters) {
            os << letter << " ";
        }
        os << std::endl;
        return os;
    }
};

class Game {
    Word word;
    Players players;

private:
    void displayGameState(const Player& currentPlayer) {
        std::cout << "Current player: " << currentPlayer.getName() << std::endl;
        std::cout << "Attempts left: " << currentPlayer.getAttemptsLeft() << std::endl;
        std::cout << "Guessed letters: ";
        for (char letter : word.getGuessedLetters()) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
        std::cout << "Word: ";
        for (char letter : word.getSecretWord()) {
            if (std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), letter) != word.getGuessedLetters().end()) {
                std::cout << letter << " ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }

    std::string getValidGuess() {
        std::string guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;
        while (guess.length() != 1 || !isalpha(guess[0]) || std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), guess[0]) != word.getGuessedLetters().end()) {
            std::cout << "Invalid guess! Enter a new letter: ";
            std::cin >> guess;
        }
        return guess;
    }

    void updateGameState(const std::string& guess, Player& currentPlayer) {
        std::vector<char> guessed = word.getGuessedLetters();
        guessed.push_back(guess[0]);
        word.setGuessedLetters(guessed);
        if (word.getSecretWord().find(guess) == std::string::npos) {
            currentPlayer.setAttemptsLeft(currentPlayer.getAttemptsLeft() - 1);
        }
    }

    bool isLetterGuessed(char letter) {
        std::cout << "Letter: " << letter << std::endl;
        return std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), letter) != word.getGuessedLetters().end();

    }

    bool isWordGuessed() {
        for (char letter : word.getSecretWord()) { // NOLINT(*-use-anyofallof)
            if (std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), letter) == word.getGuessedLetters().end()) {
                return false;
            }
        }
        return true;
    }

public:

    Game(Word  word, Players  players) : word(std::move(word)), players(std::move(players)) {
    }

    void play() {
        bool won = false;
        while (!won && !players.allPlayersAttempted()) {
            Player& currentPlayer = players.getCurrentPlayer();
            displayGameState(currentPlayer);

            std::string guess = getValidGuess();
            bool alpha = isLetterGuessed(guess[0]);

            updateGameState(guess, currentPlayer);
            won = isWordGuessed();
            if (!won) {
                if (!alpha) {
                    std::cout << "NEEEEEEXT" << std::endl;
                    players.nextPlayer();
                }

            }
        }

        if (won) {
            std::cout << "Congratulations! Player " << players.getCurrentPlayer().getName() << " won! The word was: " << word.getSecretWord() << std::endl;
        } else {
            std::cout << "Sorry, all players are out of attempts. The word was: " << word.getSecretWord() << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Game& game) {
        os << "Word: " << game.word << std::endl;
        os << "Players: " << std::endl;
        const std::vector<Player> gamers = game.players.getPlayers();
        for (const auto& player : gamers) {
            os << player << std::endl;
        }
        return os;
    }


};

class GameInitializer {
public:
    static std::string getRandomWord(const std::vector<std::string>& words) {
        return words[std::rand() % words.size()]; // NOLINT(*-msc50-cpp)
    }
};

int main() {
    std::vector<std::string> words = {"apple", "banana", "orange", "grape", "kiwi", "peach", "mango"};
    std::string secretWord = GameInitializer::getRandomWord(words);

    Word word(secretWord);

    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

    std::vector<std::string> playerNames;
    for (int i = 1; i <= numPlayers; ++i) {
        std::string playerName;
        std::cout << "Enter name for Player " << i << ": ";
        std::cin >> playerName;
        playerNames.push_back(playerName);
    }

    Players players(playerNames, 6);
    Game game(word, players);
    game.play();

    return 0;
}
