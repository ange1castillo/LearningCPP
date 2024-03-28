#include <iostream> 

#include "Random.h"

namespace WordList{
    std::vector<std::string> wordsList{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

    std::string_view getRandomWord(){
        return wordsList[Random::get<std::size_t>(0, std::size(wordsList) - 1)];
    }   
};

class Session{
    private:
        int m_guessesLeft {6};
        std::string_view m_word {WordList::getRandomWord()};
        std::vector<bool> m_lettersGuessed {std::vector<bool>(26)}; 
        std::size_t toIndex(char guess) const {return static_cast<std::size_t>((guess % 32) - 1);}  

    public:
        int getGuessesLeft() const {return m_guessesLeft;}
        void setGuessesLeft(int guesses) {m_guessesLeft -= guesses;}
        std::string_view getWord() const {return m_word;}
        std::vector<bool> getLettersGuessed() const {return m_lettersGuessed;}
        bool isLetterGuessed(char guess) const {return m_lettersGuessed[toIndex(guess)];}
        void setLetterGuessed(char guess){ m_lettersGuessed[toIndex(guess)] = true;}
        bool isLetterInWord(char guess) const {
            for(const auto& character: m_word){
                if(guess == character){
                    return true;
                }
            }
            return false;
        }

        bool isWon(){
            for(const auto& character: m_word){
                if(!isLetterGuessed(character)){
                    return false;
                }
            }

            return true;
        }
};

void displayWord(const Session& game){
    std::cout << "The word: ";
    for(auto character: game.getWord()){
        if(game.isLetterGuessed(character)){
            std::cout << character;
        }

        else{
            std::cout << '_'; 
        }
    }
}

void displayWrongGuesses(const Session& game){
    std::cout << " Wrong guesses: ";
    for(int guessesLeft {0}; guessesLeft <game.getGuessesLeft(); ++guessesLeft){
        std::cout << '+';
    }

    for(char c = 'a'; c <= 'z'; ++c){
        if(game.isLetterGuessed(c) && !game.isLetterInWord(c)){
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

char getGuess(const Session& game){
    while(true){
        std::cout << "Enter your next letter: ";
        char guess {};
        std::cin >> guess;

        if(!std::cin){
            std::cout << "That wasn't a valid input. Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(guess < 'a' || guess > 'z'){
            std::cout << "That wasn't a valid input. Try again" << std::endl;
            continue;
        }

        if(game.isLetterGuessed(guess)){
            std::cout << "You already guessed " << guess << ". Try again." << std::endl;
            continue;
        }

        return guess;
    }            
}

void endGame(const Session& game){
    displayWord(game);
    displayWrongGuesses(game);
    if(!game.getGuessesLeft()){
        std::cout << "You lost! The word was: " << game.getWord() << std::endl;
    }
    else{
        std::cout << "You won!" << std::endl;
    }
}

void check(Session& game, char guess){
    if(game.isLetterInWord(guess)){
        std::cout << "Yes! '" << guess << "' is in the word!" << std::endl << std::endl;
    }

    else{
        std::cout << "No, '" << guess << "' is not in the word!" << std::endl << std::endl;
        game.setGuessesLeft(1);
    }
}

void playGame(Session& game){
    int guesses {game.getGuessesLeft()};

    while(game.getGuessesLeft() && !game.isWon()){
        displayWord(game);
        displayWrongGuesses(game);

        char guess {getGuess(game)};

        game.setLetterGuessed(guess);

        check(game, guess);
    }
    endGame(game);
}

void start(){
    Session game {};
    std::cout << "Welcome to C++man (a variant of Hangman)" << std::endl <<
                "To win: guess the word.  To lose: run out of pluses." << std::endl << std::endl;

    playGame(game);
}

int main(){
    start();

    return 0;
}
