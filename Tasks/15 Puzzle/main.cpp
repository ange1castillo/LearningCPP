#include "Board.h"
#include "Direction.h"
#include "Point.h"
#include "Random.h"
#include "Tile.h"
#include "UserInput.h"

#include <iostream>

int main() {
    Board randomizedBoard {};
    randomizedBoard.randomize();
    std::cout << randomizedBoard << "\n\n";

    std::cout << "Enter a command: ";

    while(true) {
        char character { UserInput::getCommandFromUser() };

        if(character == 'q'){
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        Direction direction { UserInput::charToCommand(character) };

        std::cout << "You entered: " << direction << "\n\n";

        if(randomizedBoard.moveTile(direction)){
            std::cout << randomizedBoard;
        }

        if(randomizedBoard.playerWon()){
            std::cout << "You win!" << '\n';
            return 0;
        }
    }

    return 0;
}
