// This solution uses unordered_map 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoNums;
        unordered_map<int, int> intIndexMap;
        for (int i = 0; i < nums.size(); i++) {
            auto it = intIndexMap.find(target - nums[i]);
            if (it != intIndexMap.end()) {
                twoNums = { it->second, i };
                return twoNums;
            }
            intIndexMap[nums[i]] = i;
        }
        
        return twoNums;
    }
};