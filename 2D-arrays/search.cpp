// problem 240 leetocde 
/*
  Integers in each row are sorted in ascending from left to right.
  Integers in each column are sorted in ascending from top to bottom.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIndex = 0, colIndex = matrix[0].size() - 1;
        while(rowIndex < matrix.size() && colIndex >= 0) {
            if(matrix[rowIndex][colIndex] == target)
                return true;
            else if(matrix[rowIndex][colIndex] > target)
                colIndex--;
            else
                rowIndex++;
        }
        return false;
    }
};
