
#ifndef HANGMAN_WORD_H
#define HANGMAN_WORD_H

#include <iostream>
#include <vector>
#include <string>

class Word {
private:
    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    Word();

    explicit Word(std::string word);

    bool operator==(const Word& rhs) const;
    bool operator!=(const Word& rhs) const;

    [[nodiscard]] const std::string& getSecretWord() const;
    [[nodiscard]] const std::vector<char>& getGuessedLetters() const;
    void setGuessedLetters(const std::vector<char>& guessed);


    friend std::ostream& operator<<(std::ostream& os, const Word& word);
};

#endif // HANGMAN_WORD_H