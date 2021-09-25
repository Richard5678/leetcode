class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        int limit = nums.size();
        if (limit < 3) {
            return answer;
        }
        sort(nums.begin(), nums.end());
        
        
        for (int i = 0; i < limit - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int j = i + 1;
            int k = limit - 1;
            while (j < k) {
                if ((k < limit - 1 && nums[k] == nums[k + 1]) || nums[j] + nums[k] > target) {
                    k--;
                } else if (nums[j] + nums[k] == target) {
                    vector<int> ints = {nums[i], nums[j], nums[k]};

                    answer.push_back(ints);
                    j++;
                    k--;
                } else {
                    j++;
                }
            }
        }

        return answer;
    }
};