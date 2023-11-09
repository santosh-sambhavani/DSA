//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private: 
        bool checkPoint (vector<vector<int>> m, int x, int y, int n, vector<vector<int>> visited) {
            return (x == -1 || x == n || y == -1 || y == n || m[x][y] == 0 || visited[x][y] == 1) ? false : true;
        }
    
    private: 
        void generatePaths(
            vector<vector<int>>& m, 
            int rawIndex,
            int colIndex,
            int n, 
            string output, 
            vector<string>& result,
            vector<vector<int>> &visited
        ) {
            // cout << "\n ===>" << rawIndex << " || " << colIndex;
            if (rawIndex == n-1 && colIndex == n-1) {
                result.push_back(output);
                return;
            } 
            
            // check down
            if (checkPoint(m, rawIndex + 1, colIndex, n, visited)) {
                // go down
                rawIndex += 1;
                visited[rawIndex][colIndex] = 1;
                output += 'D';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                rawIndex--;
                output = output.substr(0, output.size() - 1);
            }
            
            // check up
            if (checkPoint(m, rawIndex - 1, colIndex, n, visited)) {
                // go up
                rawIndex -= 1;
                visited[rawIndex][colIndex] = 1;
                output += 'U';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                rawIndex++;
                output = output.substr(0, output.size() - 1);
            }
            
            // check right 
            if (checkPoint(m, rawIndex, colIndex + 1, n, visited)) {
                // go right
                colIndex += 1;
                visited[rawIndex][colIndex] = 1;
                output += 'R';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                colIndex--;
                output = output.substr(0, output.size() - 1);
            }
            
            // check left
            if (checkPoint(m, rawIndex, colIndex - 1, n, visited)) {
                // go left
                colIndex -= 1;
                visited[rawIndex][colIndex] = 1;
                output += 'L';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                colIndex++;
                output = output.substr(0, output.size() - 1);
            }
        }
    public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> result;
        if (m[0][0] == 0 || m[n-1][n-1] == 0)
            return result;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        generatePaths(m, 0, 0, n, "", result, visited);
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
