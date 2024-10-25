/*
    Leetcode: 42. Trapping Rain Water
    https://leetcode.com/problems/trapping-rain-water/description/
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int i = 0, j = height.size() - 1;
        int maxLeft = height[i], maxRight = height[j];

        while(i < j){
            if(maxLeft < maxRight){
                i++;
                maxLeft = max(maxLeft, height[i]);
                area += maxLeft - height[i];
            }
            else{
                j--;
                maxRight = max(maxRight, height[j]);
                area += maxRight - height[j];
            }
        }
        return area;
    }
};
