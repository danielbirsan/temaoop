
#include "word.h"

Word::Word() : secretWord("default"), guessedLetters() {}
Word::Word(std::string word) : secretWord(std::move(word)) {}

bool Word::operator==(const Word& rhs) const {
    return secretWord == rhs.secretWord && guessedLetters == rhs.guessedLetters;
}

bool Word::operator!=(const Word& rhs) const {
    return !(*this == rhs);
}

Word& Word::operator=(const Word& word) {
    if (this != &word) {
        secretWord = word.secretWord;
        guessedLetters = word.guessedLetters;
    }
    return *this;
}

Word::Word(const Word& word) : secretWord(word.secretWord), guessedLetters(word.guessedLetters) {}
const std::string& Word::getSecretWord() const {
    return secretWord;
}

const std::vector<char>& Word::getGuessedLetters() const {
    return guessedLetters;
}

void Word::setGuessedLetters(const char& guessed) {
    guessedLetters.push_back(guessed);
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
