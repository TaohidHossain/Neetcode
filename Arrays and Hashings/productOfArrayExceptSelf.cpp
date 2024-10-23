/*
    Leetcode: 238. Product of Array Except self
    https://leetcode.com/problems/product-of-array-except-self/description/
    Time: O(n)
    Space: O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();
        vector<int> prefix(size+1), postfix(size), result(size);
        prefix[0] = 1;
        postfix[size-1] = 1;
        for(int i=1; i<size+1; i++)
            prefix[i] = prefix[i-1] * nums[i-1];

        for(int i=size-2; i>-1; i--)
            postfix[i] = postfix[i+1] * nums[i+1];

        for(int i=0; i<size; i++){
            result[i] = prefix[i] * postfix[i];
        }
        return result;
    }
};
