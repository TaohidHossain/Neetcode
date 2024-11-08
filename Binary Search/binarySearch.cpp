/*
    Leetcode: 704. Binary Search
    https://leetcode.com/problems/binary-search/description/
    Time: O(log(n))
    Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return -1;
    }
};
