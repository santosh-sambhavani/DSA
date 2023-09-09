class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int firstRow = 0, 
            firstCol = 0,
            lastRow = matrix.size() - 1,
            lastCol = matrix[0].size() - 1,
            count = 0,
            n = matrix.size() * matrix[0].size();
        
        vector<int> ans;
        
        while(count < n) {
            // add firstRow;
            for(int col = firstCol; count < n && col <= lastCol; col++) {
                ans.push_back(matrix[firstRow][col]);
                count++;
            }
            firstRow++;
            
            // add lastCol
            for(int row = firstRow; count < n && row <= lastRow; row++) {
                ans.push_back(matrix[row][lastCol]);
                count++;
            }
            lastCol--;
            
            // add lastRow
            for(int col = lastCol; count < n && col >= firstCol; col--) {
                ans.push_back(matrix[lastRow][col]);
                count++;
            }
            lastRow--;
            
            //add firstCol
            for(int row = lastRow; count < n && row >= firstRow; row--) {
                ans.push_back(matrix[row][firstCol]);
                count++;
            }
            firstCol++;
        }     
        
        return ans;
    }
};
