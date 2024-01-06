//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
    
    bool isValid(vector<int> pos, int N) {
        int x = pos[0], y = pos[1];
        return (x >= 0 && x < N) && (y >= 0 && y < N);
    }
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<vector<int>> q;
	    vector<vector<int>> visited(N, vector<int> (N, 0));
	    vector<int> source = { N - KnightPos[1], KnightPos[0] - 1 };
	    vector<int> target = { N - TargetPos[1], TargetPos[0] - 1 };
	    int steps = 0;
	    int dx[8] = {1,1,-1,-1,2,2,-2,-2};
        int dy[8] = {2,-2,2,-2,1,-1,1,-1};
	    
	    q.push(source);
	    visited[source[0]][source[1]] = 1;
	    while(!q.empty()) {
	        int size = q.size();
	        for(int i = 0; i < size; i++) {
	            vector<int> front = q.front();
	            if(front == target) {
	                return steps;
	            } else {
	                // note all possibilities
	                for(int i = 0; i < 8; i++) {
	                    int x1 = front[0] + dx[i];
	                    int y1 = front[1] + dy[i];
	                    if(((x1 >= 0 && x1 < N) && (y1 >= 0 && y1 < N) && visited[x1][y1] == 0)) {
	                        q.push({x1, y1});
	                        visited[front[0]][front[1]] = 1;
	                    }
	                }
	            }
	            q.pop();
	        }
	        steps++;
	    }
	    
	    return steps;
	}
};

//{ Driver Code Starts.
int main(){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
}
// } Driver Code Ends

/*
8
7 7
1 5
*/
