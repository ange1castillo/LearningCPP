class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size { static_cast<int>(nums.size()) };
        if(size > 2){
            for(int index { 0 }; index < size; ++index) {
                int numFind { target - nums[index] };
                for(int x { index + 1 }; x < size; ++x) {
                    if(nums[x] == numFind) {
                        return { index, x };
                    }
                }
            }
        }

        return {0, 1};
    }
};