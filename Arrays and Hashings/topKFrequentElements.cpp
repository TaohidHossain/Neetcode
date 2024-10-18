/*
Leetcode: 347. Top K Frequent Elements
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency
        int n = nums.size();
        unordered_map<int, int> mp; // {number, count}
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        // Step 2: Bucket Sort Logic
        unordered_map<int, vector<int>> bucket;
        for(auto it = mp.begin(); it != mp.end(); it++){
            bucket[it->second].push_back(it->first);
        }
        // Step 3: find result
        vector<int> result;
        for(int i=n; i>=0; i--){
            if(!bucket[i].empty()){
                result.insert(result.end(), bucket[i].begin(), bucket[i].end());
            }
            if(result.size() >= k)
                break;
        }
        return result;
    }
};
