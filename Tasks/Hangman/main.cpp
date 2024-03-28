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
        std::string_view m_word {WordList::getRandomWord()};
        std::vector<bool> m_lettersGuessed {std::vector<bool>(26)}; 
        std::size_t toIndex(char guess) const {return static_cast<std::size_t>((guess % 32) - 1);}  

    public:
        std::string_view getWord() const {return m_word;}
        bool isLetterGuessed(char guess) const {return m_lettersGuessed[toIndex(guess)];}
        void setLetterGuessed(char guess){ m_lettersGuessed[toIndex(guess)] = true;}
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
    std::cout << std::endl;
}

char getGuess(){
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

        return guess;
    }            
}

void playGame(Session& game){
    int guesses {6};

    while(--guesses){
        displayWord(game);

        char guess {getGuess()};

        std::cout << "You entered: " << guess << std::endl;

        game.setLetterGuessed(guess);
    }
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
