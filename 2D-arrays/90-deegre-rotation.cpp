class Solution {
public:
    void rotateClockWise(vector<vector<int>>& matrix) {
        int firstRow = 0, 
            firstCol = 0,
            lastRow = matrix.size() - 1,
            lastCol = matrix.size() - 1;
        
        while(firstCol < lastCol) {
            int shift = 0;
            for(int col = firstCol; col < lastCol; col++) {
                // Right shift
                int temp1 = matrix[firstRow + shift][lastCol];
                matrix[firstRow + shift][lastCol] = 
                    matrix[firstRow][firstCol + shift];
                
                // Down shift
                int temp2 = matrix[lastRow][lastCol-shift];
                matrix[lastRow][lastCol-shift] = temp1;
                
                // Left shift
                temp1 = matrix[lastRow-shift][firstCol];
                matrix[lastRow-shift][firstCol] = temp2;
                
                // Up shift
                matrix[firstRow][firstCol+shift] = temp1;
                
                shift++;
            }
            firstRow++;
            firstCol++;
            lastRow--;
            lastCol--;
        }
    }
};
