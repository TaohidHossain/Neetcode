/*
    Leetcode: 36. Valid Sudoku
    https://leetcode.com/problems/valid-sudoku/
    Top 1% solution: https://leetcode.com/problems/valid-sudoku/submissions/1431166513
    Time: O(size^2)
    Space: O(size^2)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9;
        bool rows[size][size] = {false};
        bool cols[size][size] = {false};
        bool squares[size][size] = {false};
        for(int r=0;r<size;r++){
            for(int c=0;c<size;c++){
                if(board[r][c] == '.')
                    continue;
                int index = board[r][c] - '0' - 1; // char to number-1 eg. '5' -> 4
                int area = (r/3) * 3 + (c/3);

                if(rows[r][index] || cols[c][index] || squares[area][index])
                    return false;
                rows[r][index] = true;
                cols[c][index] = true;
                squares[area][index] = true;
            }
        }
        return true;
    }
};
