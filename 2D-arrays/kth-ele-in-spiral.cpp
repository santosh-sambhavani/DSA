class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        int firstRow = 0, 
            firstCol = 0,
            lastRow = n - 1,
            lastCol = m - 1,
            count = 0,
            ans = -1;
        
        // cout << lastCol << " " << lastRow;
        while(1) {
            // add firstRow;
            for(int col = firstCol; col <= lastCol; col++) {
                // cout << "\n count" << count;
                if(++count == k) {
                    ans = matrix[firstRow][col];
                    break;
                }
            }
            if(ans != -1) return ans;
            firstRow++;
            
            // add lastCol
            for(int row = firstRow; row <= lastRow; row++) {
                // cout << "count" << count;
                if(++count == k) {
                    ans = matrix[row][lastCol];
                    break;
                }
            }
            if(ans != -1) return ans;
            lastCol--;
            
            // add lastRow
            for(int col = lastCol; col >= firstCol; col--) {
                // cout << "count" << count;
                if(++count == k) {
                    ans = matrix[lastRow][col];
                    break;
                }
            }
            if(ans != -1) return ans;
            lastRow--;
            
            //add firstCol
            for(int row = lastRow; row >= firstRow; row--) {
                // cout << "count" << count;
                if(++count == k) {
                    ans = matrix[row][firstCol];
                    break;
                }
            }
            if(ans != -1) return ans;
            firstCol++;
        }
    }

};
