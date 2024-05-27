
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


Game::Game(const Word& word, Players players) : word(word), players(std::move(players)) {}


void Game::winner() {

    try {
        std::cout << "Congratulations! Player " << players.getCurrentPlayer().getName() << " won! The word was: " << word.getSecretWord() << std::endl;

        WinnerManager<Player>& winnerManager = WinnerManager<Player>::getInstance();
        winnerManager.manageWinner(players.getCurrentPlayer(), word.getSecretWord());
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

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

                std::vector<std::unique_ptr<LuckyGame>> games;
                games.push_back(std::make_unique<WheelGame>());
                games.push_back(std::make_unique<RouletteGame>());
                games.push_back(std::make_unique<GuessGame>());

                int gameIndex = 0;
                std::cout << "Welcome to the Lucky Game Collection!" << std::endl;
                int tries = 1;
                while (tries) {
                    tries=0;
                    std::cout << "Choose a game to play (0 - Wheel, 1 - Roulette, 2 - Guess, 3 - Skip(win nothing)): ";
                    if (!(std::cin >> gameIndex) || gameIndex < 0 || gameIndex > 3) {
                        std::cout << "Invalid input! Please enter a valid number between 0 and 3." << std::endl;
                        tries=1;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;

                    }

                    if (gameIndex == 3) {
                        break;
                    }
                    std::unique_ptr<LuckyGame> game = games[gameIndex]->clone();
                    int wonPoints = game->playGame();
                    std::cout << "You won " << wonPoints << " points!" << std::endl;
                    currentPlayer.setPoints(currentPlayer.getPoints() + wonPoints);
                    std::cout << "Total points: " << currentPlayer.getPoints() << std::endl;

                }
                currentPlayer.setTotalCorrectLetters(currentPlayer.getTotalCorrectLetters() + 1);
            }
        }
    }

    if (won) {
        winner();
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



