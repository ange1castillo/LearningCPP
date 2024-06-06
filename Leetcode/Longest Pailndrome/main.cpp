#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string_view s) {
        int size { static_cast<int>(s.length()) - 1 };
        int min { 0 };
        int max { 0 };
        int begin { 0 };

        bool found { false };
        int leftOff { size };

        while(begin < size) {
            if(found || (leftOff == 0)) {
                ++begin;
                found = false;
                leftOff = size;
            }

            int index { begin };
            int last { 0 };
            bool firstIteration { true };

            for(int y { leftOff }; y > 0; --y) {

                if (s[index] == s[y]) {
                    if(firstIteration) {
                        last = y;
                        firstIteration = false;
                    }

                    if((index == y) || (index + 1 == y)) {
                        if((last - begin) > (max - min)) {
                            min = begin;
                            max = last;
                        }

                        found = true;
                        break;
                    }

                    ++index;
                }

                else {
                    leftOff -= 1;
                    break;
                }
            }
        }

        return static_cast<std::string>(s.substr(min, (max - min) + 1));
    }
};

int main() {

    Solution solve {};

    std::string input { "xaabacxcabaaxcabaax" };

    std::string answer { solve.longestPalindrome(input) };
  
}