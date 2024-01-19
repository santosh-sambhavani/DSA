/*
	next smaller / bigger element in right / left of the every number. from this 4 type of questions can be asked. 
*/
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n);
        stack<long long> s;
        
        for(int i=n-1; i >= 0; i--) {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            
            ans[i] = s.empty() ? -1 : s.top();
            s.push(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{   
  int n;
  cin>>n;
  vector<long long> arr(n);
  for(int i=0;i<n;i++)
      cin>>arr[i];
  
  Solution ob;
  
  vector <long long> res = ob.nextLargerElement(arr, n);
  for (long long i : res) cout << i << " ";
  cout<<endl;
	return 0;
}

// } Driver Code Ends
