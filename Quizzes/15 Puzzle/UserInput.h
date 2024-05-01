#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "Direction.h"

namespace UserInput {
    char getCharacter() {
        char command {};
        std::cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return command;
    }

    bool isValidCommand(char command) {
        switch(command) {
            case 'w':
            case 'a':
            case 's':
            case 'd':
            case 'q':
                return true;
            default:
                return false;
        }
    } 

    char getCommandFromUser() {
        char command {};
        while(!isValidCommand(command)){
            command = getCharacter();
        }

        return command;
    }  

    Direction::Type charToCommand(char command) {
        switch(command){
            case 'w': return Direction::up;
            case 'a': return Direction::left;
            case 's': return Direction::down;
            case 'd': return Direction::right;
        }

        return Direction::up;
    }
}

#endif
