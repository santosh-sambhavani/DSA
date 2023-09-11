// problem link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
/*
  Given a boolean 2D array of n x m dimensions where each row is sorted. 
  Find the 0-based index of the first row that has the maximum number of 1's.
*/
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row = 0, col = m - 1, maxRow = -1;
	    while(row < n && col >= 0) {
	        if(arr[row][col] == 1) {
	            maxRow = row;
	            col--;
	        } else {
	            row++;
	        }
	    }
	    return maxRow;
	}
};
