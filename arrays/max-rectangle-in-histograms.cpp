//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
        vector<long long> findNextSmallerIndexes(long long arr[], int n) {
            vector<long long> ans(n, n);
            stack<long long> s;
            int i = 0;
            
            while(i < n) {
                if(s.empty() || arr[i] >= arr[s.top()]) {
                    s.push(i++);
                } else {
                    int index = s.top();
                    s.pop();
                    ans[index] = i;
                }
            }
            return ans;
        }
        
        vector<long long> findPrevSmallerIndexes(long long arr[], int n) {
            vector<long long> ans(n, -1);
            stack<long long> s;
            int i = n-1;
            
            while(i >= 0) {
                if(s.empty() || arr[i] >= arr[s.top()]) {
                    s.push(i--);
                } else {
                    int index = s.top();
                    s.pop();
                    ans[index] = i;
                }
            }
            return ans;
        }
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long ans = -1;
        vector<long long> nextSmallerIndexes = findNextSmallerIndexes(arr, n);
        vector<long long> prevSmallerIndexes = findPrevSmallerIndexes(arr, n);
        
        for(int i = 0; i < n; i++) {
            long long current_bars_area = arr[i] * (nextSmallerIndexes[i] - prevSmallerIndexes[i] - 1);
            if (ans < current_bars_area) ans = current_bars_area;
        }
        
        return ans;
    }
};


/*{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

 } Driver Code Ends */
