/*
https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

Input: mat[][] =
[[1, 0, 0, 1, 0],
[0, 0, 1, 0, 1],
[0, 0, 0, 1, 0], 
[1, 0, 1, 0, 1]] 
Output: true
Explanation: Valid corners are at index (1,2), (1,4), (3,2), (3,4) 
*/

class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int totalRows = mat.size();
        int totalCols = mat[0].size();
        
        for (int row = 0; row < totalRows; row++) {
            vector<int> colMarker;
            for (int col = 0; col < totalCols; col++) {
                if (mat[row][col] == 1) {
                    colMarker.push_back(col);
                }
            }
            
            for (int tempRowCursor = row + 1; tempRowCursor < totalRows; tempRowCursor++) {
                int count = 0;
                for (auto marked : colMarker) {
                    if (mat[tempRowCursor][marked] == 1) {
                        count++;
                    }
                }
                
                if (count > 1)
                    return true;
            }
        }
        
        return false;
    }
};
