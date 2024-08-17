/*
Leetcode: 1. Two Sum
Time: O(n log n)
Space: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // value -> index
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end())// O(log n)
                return {i, mp[complement]};
            mp[nums[i]] = i;
        }
        return {};
    }
};
