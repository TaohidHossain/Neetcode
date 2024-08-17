/*
Leetcode: 217. Contains Duplicate
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s; // searching in unordered_set is O(1) is average case but O(log n) in set
        for(auto& x: nums){
            if(s.find(x) != s.end())
                return true;
            s.insert(x);
        }
        return false;
    }
};
