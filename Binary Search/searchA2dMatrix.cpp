/*
    Leetcode: 74. Search a 2D Matrix
    https://leetcode.com/problems/search-a-2d-matrix/description/
    Time: O(log(m*n))
    Space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lowRow = 0, highRow = m - 1;

        while(lowRow < highRow){
            int mid = ( lowRow + highRow ) / 2;
            if(matrix[mid][0] == target || matrix[mid][n-1] == target) return true;
            if(matrix[mid][0] < target && target < matrix[mid][n-1]){
                lowRow = mid;
                break;
            }
            if(matrix[mid][0] > target) highRow = mid - 1;
            else lowRow = mid + 1;
        }

        int lowCol = 0, highCol = n - 1;
        while(lowCol <= highCol){
            int mid = (lowCol + highCol) / 2;
            if(matrix[lowRow][mid] == target) return true;
            if(matrix[lowRow][mid] > target) highCol = mid - 1;
            else lowCol = mid + 1;
        }
        return false;

    }
};
