#include <iostream>

class Solution {
public:
    int romanToInt(std::string& s) {
        int total { 0 };
        int length { static_cast<int>(s.length()) };

        for(int index { 0 }; index < length; ++index) {

            switch(s[index]) {
                case 'I' :
                    if(s[index + 1] == 'V' || s[index + 1] == 'X') {
                        total -= 1;
                    }

                    else {
                        total += 1;
                    }

                    break;
                case 'V' :
                    total += 5;
                    break;
                case 'X' :
                    if(s[index + 1] == 'L' || s[index + 1] == 'C') {
                        total -= 10;
                    }

                    else {
                        total += 10;
                    }

                    break;
                case 'L' : 
                    total += 50;
                    break;
                case 'C' :
                    if(s[index + 1] == 'D' || s[index + 1] == 'M') {
                        total -= 100;
                    }

                    else {
                        total += 100;
                    }

                    break;
                case 'D' : 
                    total +=  500;
                    break;
                case 'M' : 
                    total += 1000;
                    break;
            }
        }

        return total;
    }
};

int main() {
    auto solve { std::make_unique<Solution>() };
    std::string input { "IXX" };

    int answer { solve->romanToInt(input) };

    return 0;
}