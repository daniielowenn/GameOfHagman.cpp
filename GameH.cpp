#include <iostream>
#include <string>
#include <vector>

class Hangman {
  public:
    // Function to start a new game of hangman
    void start(std::string word) {
      this->word = word;
      wrongGuesses = 0;
      correctGuesses = 0;
      for (int i = 0; i < word.length(); i++) {
        hiddenWord += "_";
      }
    }

    // Function to guess a letter
    void guess(char letter) {
      if (word.find(letter) != std::string::npos) {
        for (int i = 0; i < word.length(); i++) {
          if (word[i] == letter) {
            hiddenWord[i] = letter;
            correctGuesses++;
          }
        }
      } else {
        wrongGuesses++;
      }
    }

    // Function to check if the game is over
    bool isOver() {
      return wrongGuesses == MAX_WRONG_GUESSES || correctGuesses == word.length();
    }

    // Function to get the current state of the hidden word
    std::string getHiddenWord() {
      return hiddenWord;
    }

    // Function to get the number of wrong guesses
    int getWrongGuesses() {
      return wrongGuesses;
    }

  private:
    // Maximum number of wrong guesses allowed
    const int MAX_WRONG_GUESSES = 6;

    // The word to guess
    std::string word;

    // The current state of the hidden word
    std::string hiddenWord;

    // The number of wrong guesses made
    int wrongGuesses;

    // The number of correct guesses made
    int correctGuesses;
};

int main() {
    Hangman game;
    std::string word;
    std::cout << "Enter the word for the hangman game: ";
    std::cin >> word;
    game.start(word);
    while (!game.isOver()) {
      std::cout << "Word: " << game.getHiddenWord() << std::endl;
      std::cout << "Wrong guesses: " << game.getWrongGuesses() << std::endl;
      std::cout << "Guess a letter: ";
      char letter;
      std::cin >> letter;
      game.guess(letter);
    }
    if (game.getWrongGuesses() == Hangman::MAX_WRONG_GUESSES) {
      std::cout << "You lose! The word was " << game.getHiddenWord() << std::endl;
    } else {
      std::cout << "You win! The word was " << game.getHiddenWord() << std::
