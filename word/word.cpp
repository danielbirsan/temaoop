
#include "word.h"

Word::Word() : secretWord("default"), guessedLetters() {}

Word::Word(std::string word) : secretWord(std::move(word)) {}

bool Word::operator==(const Word& rhs) const {
    return secretWord == rhs.secretWord && guessedLetters == rhs.guessedLetters;
}

bool Word::operator!=(const Word& rhs) const {
    return !(*this == rhs);
}

const std::string& Word::getSecretWord() const {
    return secretWord;
}

const std::vector<char>& Word::getGuessedLetters() const {
    return guessedLetters;
}

void Word::setGuessedLetters(const std::vector<char>& guessed) {
    guessedLetters = guessed;
}



std::ostream& operator<<(std::ostream& os, const Word& word) {
    os << "Secret word: " << word.secretWord << std::endl;
    os << "Guessed letters: ";
    for (char letter : word.guessedLetters) {
        os << letter << " ";
    }
    os << std::endl;
    return os;
}
