#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int hey { 0 };
        int size { static_cast<int>(nums.size()) };

        for(int index { 0 }; index < size; ++index) {
            if(nums[index] != val) {
                nums[hey] = nums[index];
                ++hey;
            }
        }

        return hey;
    }
};

int main() {
    Solution solve {};
    std::vector<int> input { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val { 2 };
    int answer { solve.removeElement(input, val) };

    return 0;
}