#include <iostream>
#include <vector>

class Solution {
public:
    std::string convert(std::string& s, int numRows) {
        int stringLength { static_cast<int>(s.length()) };

        if(stringLength <= numRows - 1 || numRows == 1) {
            return s;
        }

        int arrayLength { (stringLength / 2) + 1};

        std::vector<std::vector<char>> vec( numRows , std::vector<char> (arrayLength));

        int current { 0 };
        int jump { 0 };
        while(current < stringLength) {
            int row { 0 };
            while(row < numRows - 1 && current < stringLength) {
                vec[row][jump] = s[current];
                ++current;
                if(current + numRows - 2 < stringLength) {
                    vec[numRows - row - 1][jump + row] = s[current + numRows - 2];
                }
                ++row;
            }

            current += numRows - 1;
            jump += numRows - 1;
        }
        
        std::string answer {};

        for(const auto& row : vec) {
            for(const auto& e : row) {
                if(e != '\0')
                answer += e;
            }
        }

        return answer;
    }
};

int main() {

    Solution solve {};

    std::string input { "PAYPALISHIRING" };

    std::string answer { solve.convert(input, 4) };
  
}