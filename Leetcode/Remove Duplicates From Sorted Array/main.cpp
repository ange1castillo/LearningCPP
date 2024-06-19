class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int> answer { nums[0] };

        int size { static_cast<int>(nums.size()) };
        int current { nums[0] };
        for(int index { 1 }; index < size; ++index) {
            if(nums[index] != current) {
                answer.emplace_back(nums[index]);
                current = nums[index];
            }
        }

        nums = answer;

        return static_cast<int>(answer.size());
    }
};