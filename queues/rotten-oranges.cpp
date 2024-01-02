/*
  Keep in mind while solving problems using queues 
  negative cases can be identified after all computations easily
  don't worry about all negative cases in begining 
  for example here we can find if any orange is fresh & doesn't have any possiblity at the end more easily
  if we try to verify for that before main logic than complex cases may arise like if rotten orange sorrounded by empty space
  fresh may sorrounded by othe fresh but how can we check for every fresh orange has atleast one possibility of getting rotten any how.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size(), m = grid[0].size(), time = 0;
        // Add all rotten oranges positions in queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        if(!q.size()) return -1;
        
        while (!q.empty()) {
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int dx[4] = {-1, 1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                
                int x = q.front()[0], y = q.front()[1];
                for (int j = 0; j < 4; j++) {
                    int x1 = x + dx[j], y1 = y + dy[j];
                    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1] == 1) {
                        grid[x1][y1] = 2;
                        q.push({x1, y1});
                        flag = 1;
                    }
                }
                q.pop();
            }
            if(flag) {
                time++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)  {
                    return -1;
                }
            }
        }
        
        return time;
    }
};

//{ Driver Code Starts.
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
	int ans = obj.orangesRotting(grid);
	cout << "\n ans: "<< ans << "\n";
	return 0;
}
// } Driver Code Ends

/*
3 3
0 1 2 
0 0 0 
2 1 1

3 3
0 1 2 
0 1 2 
2 1 1

*/
