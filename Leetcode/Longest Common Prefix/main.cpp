#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int length { static_cast<int>(strs.size()) };
        if(length == 1) {
            return strs[0];
        }
        
        sort(strs.begin(), strs.end());
        int col { 0 };
        std::string answer {}; 
        while(col < strs[0].length()) {
            if(strs[0][col] != strs[length - 1][col]) {
                break;
            }

            answer += strs[0][col];
            ++col;
        }

        return answer;
    }
};

int main() {
    auto solve { std::make_unique<Solution>() };
    std::vector<std::string> input { "","" };

    std::string answer { solve->longestCommonPrefix(input) };

    return 0;
}