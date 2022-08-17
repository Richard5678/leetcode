// This solution sorts the vector and scan through from both ends
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num = nums;
        std::sort(nums.begin(), nums.end());
        vector<int> twoNums;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                auto it1 = std::find(num.begin(), num.end(), nums[left]);
                auto it2 = std::find(num.begin(), num.end(), nums[right]);
                int leftIdx = it1 - num.begin();
                int rightIdx = it2 - num.begin();
                if (leftIdx == rightIdx) {
                    it2 = std::find(it2 + 1, num.end(), nums[right]);
                    rightIdx = it2 - num.begin();
                }
                twoNums = { leftIdx, rightIdx };
                return twoNums;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return twoNums;
    }
};