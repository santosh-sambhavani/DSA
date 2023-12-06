//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
    vector<int> findNextSmallerIndexes(int arr[], int n) {
        vector<int> ans(n);
        stack<int> s;
        
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> findPrevSmallerIndexes(int arr[], int n) {
        vector<int> ans(n);
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    int getMaxArea(int arr[], int n)
    {
        vector<int> nextSmaller = findNextSmallerIndexes(arr, n);
        vector<int> prevSmaller = findPrevSmallerIndexes(arr, n);
        
        int maxArea = -1;
        for(int i = 0; i < n; i++) {
            int area = (nextSmaller[i] - prevSmaller[i] - 1) * arr[i];
            if (area > maxArea) maxArea = area;
        }
        
        return maxArea;
    }
    
  public:
    int maxArea(int mat[MAX][MAX], int n, int m) {
        int currRow[MAX];
        for(int i = 0; i < m; i++) currRow[i] = mat[0][i];
        int maxArea = getMaxArea(currRow, m);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    currRow[j] += 1;
                } else currRow[j] = 0;
            }
            int area = getMaxArea(currRow, m);
            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
