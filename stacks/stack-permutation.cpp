//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        int i = 0, j = 0;
        
        while(i < N && j < N) {
            s.push(A[i]);
            while(!s.empty() && s.top() == B[j]) {
                s.pop();
                j++;
            }
            i++;
        }
        return s.empty();
    }
};

//{ Driver Code Starts.

int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    Solution ob;
    cout<<ob.isStackPermutation(n,a,b)<<endl;

    return 0;
}
/*
4
2 4 3 1
3 4 1 2

6
4 3 1 7 5 3
3 4 3 1 5 7

*/
// } Driver Code Ends
