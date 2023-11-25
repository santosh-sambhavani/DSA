//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void solve(stack<int>& s,int x) {
        if(s.empty()) {
            s.push(x);
            return ;
        }
        
        int tmp = s.top();
        s.pop();
        
        solve(s, x);
        
        s.push(tmp);
    }
    
    public:
    stack<int> insertAtBottom(stack<int> St,int X){
        solve(St, X);
        return St;
    }
};

//{ Driver Code Starts.

int main(){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
    return 0;
}
// } Driver Code Ends


/*
3 4
2 1 5
*/
