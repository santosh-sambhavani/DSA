//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/
class Solution {
  public:
  
    // Function to detect cycle in an undirected graph.
    // using concept to traverse node with tracking adjacents could be traversed already
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

// using parent node concept
bool isCycle(int V, vector<int> adj[]) {
         vector<int> visited(V, 0);
        vector<int> parent(V, -1); // Track parent of each node
        stack<int> s;
        
        for (int index = 0; index < V; index++) {
            if (!visited[index]) {
                s.push(index);
                visited[index] = 1;
                
                while(!s.empty()) {
                    int top = s.top();
                    s.pop();
                    
                    // iterate over all adjacent nodes of top
                    for (int j = 0; j < adj[top].size(); j++) {
                        int adjNode = adj[top][j];
                        if (!visited[adjNode]) {
                            s.push(adjNode);
                            visited[adjNode] = 1;
                            parent[adjNode] = top; // Set parent of adjNode as top
                        } else if (parent[top] != adjNode) {
                            return true; // A cycle is detected
                        }
                    }
                }
            }
        }
        
        return false;
    }

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
