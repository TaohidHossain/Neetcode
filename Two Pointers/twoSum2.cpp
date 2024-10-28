/*
    Leetcode: 167. Two Sum II - Input Array Is Sorted
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum < target){
                i++;
            }
            else if(sum > target){
                j--;
            }
            else if (sum == target){
                return { i+1, j+1 };
            }
        }
        return {};
    }
};
