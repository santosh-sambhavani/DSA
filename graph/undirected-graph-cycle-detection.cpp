//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        stack<int> s;

        for (int index = 0; index < V; index++) {
            // int ele = (*adj)[index];
            if (!visited[index]) {
                s.push(index);
            }
            
            while(!s.empty()) {
                int top = s.top();
                s.pop();
                visited[top] = 1;
                
                // iterate over all adjecent nodes of top
                bool key = 0;
                int k = adj[top].size();
                for (int j = 0; j < k; j++) {
                    int adjNode = adj[top][j];
                    if (visited[adjNode]) continue;
                    
                    s.push(adjNode);
                    visited[adjNode] = 1;
                    key = true;
                }
                if (k >= 2 && !key) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {

    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
// } Driver Code Ends

/*
5 5
0 4
1 2
1 4
2 3
3 4
*/
