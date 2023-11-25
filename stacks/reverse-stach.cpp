//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void insertAtBottom(stack<int> &St, int x) {
        if(St.empty()) {
            St.push(x);
            return ;
        }
        
        int tmp = St.top();
        St.pop();
        
        insertAtBottom(St, x);
        
        St.push(tmp);
    }
    
public:
    void Reverse(stack<int> &St){
        if(St.empty()) {
            return ;
        }
        
        int tmp = St.top();
        St.pop();
        
        Reverse(St);
        
        insertAtBottom(St, tmp);
    }
};


/*
3 = 6
2   7
1   1
7   2
6   3
*/

//{ Driver Code Starts.


int main(){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
}
// } Driver Code Ends
/*
3
4 5 7
*/
