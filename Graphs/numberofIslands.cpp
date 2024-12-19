/*
    Leetcode: 200. Number of Islands
    https://leetcode.com/problems/number-of-islands/description/
    Time: O(rows x cols)
    Space: O(1)
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        int islands = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    bfs(grid, i, j, rows, cols);
                }
            }
        }
        return islands;
    }
private:
    void bfs(vector<vector<char>>& grid, int i, int j, int row, int col){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') return;
        grid[i][j] = '0';
        bfs(grid, i - 1, j, row, col);
        bfs(grid, i + 1, j, row, col);
        bfs(grid, i, j - 1, row, col);
        bfs(grid, i, j + 1, row, col);
    }
};
