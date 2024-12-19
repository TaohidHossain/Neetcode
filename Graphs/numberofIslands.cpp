/*
    695. Max Area of Island
    https://leetcode.com/problems/max-area-of-island/description/
    Time: O(rows x cols)
    Space: O(rows x cols)
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        int maxArea = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j, rows, cols));
                }
            }
        }
        return maxArea;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int r, int c){
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        return 1 + dfs(grid, i - 1, j, r, c) + dfs(grid, i + 1, j, r, c) +
        dfs(grid, i, j - 1, r, c) + dfs(grid, i, j + 1, r, c);
    }
};
