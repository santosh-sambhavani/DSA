//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
	    queue<pair<int, int>> q;
	    int dx[4] = {0,0,1,-1};
	    int dy[4] = {1,-1,0,0};
	    int m = grid.size(), n = grid[0].size();
	    
	    for(int i = 0; i < grid.size(); i++) {
	        for(int j = 0; j < grid[0].size(); j++) {
	            if (grid[i][j] == 1) {
	                q.push({i, j});
	                grid[i][j] = 0;
	                visited[i][j] = 1;
	            }
	        }
	    }
	    
	    while(!q.empty()) {
            pair<int, int> current = q.front();
            for(int j = 0; j < 4; j++) {
                int x = current.first + dx[j];
                int y = current.second + dy[j];
                if (
                    x >= 0 && x < m
                    && y >= 0 && y < n
                    && visited[x][y] != 1
                    && grid[x][y] == 0
                ) {
                    grid[x][y] = grid[current.first][current.second] + 1;
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
            q.pop();
	    }
	    
	    return grid;
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>>grid(n, vector<int>(m, -1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
	cout << "\n ===> ans: \n";
	for(auto i: ans){
		for(auto j: i){
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}
/*
3 4 
0 1 1 0 
1 1 0 0 
0 0 1 1


3 4
1 0 0 0
0 0 0 0
1 0 0 1
*/
// } Driver Code Ends
