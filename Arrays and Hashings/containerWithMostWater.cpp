/*
    Leetcode: 11. Container With Most Water
    https://leetcode.com/problems/container-with-most-water/description/
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
    int i = 0, j = height.size() - 1;
    int area;
    while(i<j){
        area = (j-i) * min(height[i], height[j]);
        maxArea = max(maxArea, area);
        height[i] < height[j] ? i++ : j--;
    }

    return maxArea;
    }
};
