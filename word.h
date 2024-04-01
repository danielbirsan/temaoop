#ifndef HANGMAN_WORD_H
#define HANGMAN_WORD_H
#include <iostream>
#include <vector>
#include <algorithm>

class Word {
    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    Word(): secretWord("default"), guessedLetters() {}

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

#endif //HANGMAN_WORD_H