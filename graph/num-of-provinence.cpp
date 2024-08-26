// https://www.geeksforgeeks.org/problems/number-of-provinces/1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> adj_mat_to_list(vector<vector<int>> adj, int n) {
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adj[i][j]) {
                    ans[i].push_back(j);
                }
            }   
        }
        return ans;
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int count = 0;
        vector<int> visited(V, 0);
        stack<int> s;
        vector<vector<int>> adj_list = adj_mat_to_list(adj, V);
        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;
            count++;
            s.push(i);
            while(!s.empty()) {
                int top = s.top();
                s.pop();
                if (visited[top]) continue;                
                for (int j = 0; j < adj_list[top].size(); j++) {
                    if (!visited[adj_list[top][j]]) {
                        s.push(adj_list[top][j]);
                    }
                }
                visited[top] = 1;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;

}
// } Driver Code Ends

/*
3
1 0 1
0 1 0
1 0 1
*/
