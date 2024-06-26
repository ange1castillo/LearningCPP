class Solution {
public:
    int strStr(std::string_view haystack, std::string_view needle) {

        int haystack_length { static_cast<int>(haystack.size()) };
        int needle_length { static_cast<int>(needle.size()) };

        for(int index { 0 }; index < haystack_length; ++index) {
            if(needle[0] == haystack[index]) {
                int x { 1 };
                while(true) {
                    if(x == needle_length) {
                        return index;
                    }

                    else if(needle[x] != haystack[index + x]) {
                        break;
                    }

                    ++x;
                }
            }
        }

        return -1;
    }
};