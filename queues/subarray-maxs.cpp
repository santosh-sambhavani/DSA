//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> dq;
        int start = 0, end = k-1;
        vector<int> ans;
        
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
                
        while(end < n) {
            
            if(start != 0) {
                // remove first ele of dq if it is not in current window
                if(!dq.empty() && dq.front() < start) {
                    dq.pop_front();
                }
                
                // remove elements smaller than newly added element
                while(!dq.empty() && arr[dq.back()] < arr[end]) {
                    dq.pop_back();
                }
                
                dq.push_back(end);
            }
            ans.push_back(arr[dq.front()]);
            
            start++; end++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {


        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;

    return 0;
}
// } Driver Code Ends
