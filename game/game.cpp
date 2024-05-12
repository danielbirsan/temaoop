
#include "game.h"


void Game::displayGameState(const Player &currentPlayer) {
    std::cout << "Current player: " << currentPlayer.getName() << std::endl;
    std::cout << "Attempts left: " << currentPlayer.getAttemptsLeft() - 1 << std::endl;
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

void Game::displayAllStatistics() {
    std::ofstream fout("log.txt");
    for (const auto &currentPlayer : players.getPlayers()) {
        fout << "Player: " << currentPlayer.getName() << std::endl;
        fout << "Correct letters: " << currentPlayer.getTotalCorrectLetters() << std::endl;
        fout << "Wrong letters: " << currentPlayer.getTotalWrongLetters() << std::endl;
        int totalLetters = currentPlayer.getTotalCorrectLetters() + currentPlayer.getTotalWrongLetters();
        fout << "Total letters: " << totalLetters << std::endl;
        fout << "Percentage of correct letters: " << (currentPlayer.getTotalCorrectLetters() / static_cast<double>(totalLetters)) * 100 << "%" << std::endl;
        fout << std::endl;
    }
    fout.close();
}

std::string Game::getValidGuess() {
    std::string guess;
    std::cout << "Guess a letter: ";
    std::cin >> guess;

    std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

    while (guess.length() != 1 || !isalpha(guess[0]) || std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), guess[0]) != word.getGuessedLetters().end()) {
        std::cout << "Invalid guess! Enter a proper letter: ";
        std::cin >> guess;
    }

    return guess;
}

void Game::updateGameState(const std::string &guess, Player &currentPlayer) {
    std::vector<char> guessed = word.getGuessedLetters();
    guessed.push_back(guess[0]);
    word.setGuessedLetters(guessed);
    if (word.getSecretWord().find(guess) == std::string::npos) {
        currentPlayer.setAttemptsLeft(currentPlayer.getAttemptsLeft() - 1);
    }
}

bool Game::isWordGuessed() {
    for (char letter : word.getSecretWord()) {
        if (std::find(word.getGuessedLetters().begin(), word.getGuessedLetters().end(), letter) == word.getGuessedLetters().end()) {
            return false;
        }
    }
    return true;
}

Game::Game(Word word, Players players) : word(std::move(word)), players(std::move(players)) {}

void Game::play() {
    bool won = false;
    while (!won && !players.allPlayersAttempted()) {
        Player &currentPlayer = players.getCurrentPlayer();
        displayGameState(currentPlayer);
        std::string guess = getValidGuess();
        updateGameState(guess, currentPlayer);

        won = isWordGuessed();
        if (!won) {
            if (word.getSecretWord().find(guess) == std::string::npos) {

                players.nextPlayer();
                currentPlayer.setTotalWrongletters(currentPlayer.getTotalWrongLetters() + 1);
            } else {
                currentPlayer.setTotalCorrectLetters(currentPlayer.getTotalCorrectLetters() + 1);
            }
        }
    }

    if (won) {
        std::cout << "Congratulations! Player " << players.getCurrentPlayer().getName() << " won! The word was: " << word.getSecretWord() << std::endl;
    } else {
        std::cout << "Sorry, all players are out of attempts. The word was: " << word.getSecretWord() << std::endl;
    }
    displayAllStatistics();
}

std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << "Word: " << game.word << std::endl;
    os << "Players: " << std::endl;
    const std::vector<Player> gamers = game.players.getPlayers();
    for (const auto &player : gamers) {
        os << player << std::endl;
    }
    return os;
}



