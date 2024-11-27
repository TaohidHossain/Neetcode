/*
    Leetcode: 153. Find Minimum in Rotated Sorted Array
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        if(nums[i] < nums[j]) return nums[i];

        int min = nums[i];
        while(i <= j){
            int mid = (i + j) / 2;
            min = std::min(min, nums[mid]);
            if(nums[mid] < nums[j]) j = mid - 1;
            else i = mid + 1;
        }
        return min;
    }
};
