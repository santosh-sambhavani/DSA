//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int oldColor = image[sr][sc], m = image.size(), n = image[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = image[i][j];
            }
        }

        q.push({sr, sc});
        res[sr][sc] = newColor;
        if(image[sr][sc]==newColor)
            return image;
        while(!q.empty()) {
            pair<int, int> front = q.front();            
            vector<pair<int, int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
            for (auto &it: dir) {
                int newX = front.first+it.first;
                int newY = front.second+it.second;
                if (
                    newX >= 0 
                    && newX < m
                    && newY >= 0
                    && newY < n
                    && res[newX][newY] == oldColor
                ) {
                    q.push({newX, newY});
                    res[newX][newY] = newColor;
                }
            }
            q.pop();
        } 
        return res;
    }
};

//{ Driver Code Starts.
int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>>image(n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> image[i][j];
    }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
    for(auto i: ans){
        for(auto j: i)
            cout << j << " ";
        cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
/*
3 3
1 1 1
1 1 0
1 0 1
1 1 2
*/
