//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    vector<long long> findNextSmallerIndexes(long long arr[], int n) {
        vector<long long> ans(n);
        stack<long long> s;
        
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    vector<long long> findPrevSmallerIndexes(long long arr[], int n) {
        vector<long long> ans(n);
        stack<long long> s;
        
        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> nextSmaller = findNextSmallerIndexes(arr, n);
        vector<long long> prevSmaller = findPrevSmallerIndexes(arr, n);
        
        long long maxArea = -1;
        for(int i = 0; i < n; i++) {
            long long area = (nextSmaller[i] - prevSmaller[i] - 1) * arr[i];
            if (area > maxArea) maxArea = area;
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
{
  int n;
  cin>>n;
  
  long long arr[n];
  for(int i=0;i<n;i++)
      cin>>arr[i];
  Solution ob;
  cout<<ob.getMaxArea(arr, n)<<endl;
	return 0;
}
/*
8
7 2 8 9 1 3 6 5
*/
// } Driver Code Ends
