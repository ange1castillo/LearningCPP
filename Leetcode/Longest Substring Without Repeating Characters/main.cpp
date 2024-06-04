class Solution {
public:
    int lengthOfLongestSubstring(std::string& s) {
        if(s == "") {
            return 0;
        }
        
        int ans { 0 };
        int length { static_cast<int>(s.length()) };
        std::size_t found {};

        for(int x { 0 }; x < length; ++x) {
            int sum { 0 };
            for(int y { x + 1 }; y < length; ++y) {
                found = { s.substr(x, sum + 1).find(s[y]) };
                if(found == std::string::npos) {
                    ++sum;
                }

                else {
                    break;
                }
            }

            ans = max(ans, sum);
        }

        return ans + 1;
    }
};