class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        std::sort(nums1.begin(), nums1.end(), std::less());

        int size { static_cast<int>(nums1.size()) };

        if(size % 2 == 0) {
            double x { static_cast<double>(nums1[size / 2]) };
            double y { static_cast<double>(nums1[(size / 2) - 1]) };
            return (x + y) / 2 ;
        }

        return nums1[size / 2];

        return 0;
    }
};