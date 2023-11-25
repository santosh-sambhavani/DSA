//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> Stack;
        for(auto& ch: s) {
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                Stack.push(ch);
            } else if(ch == ')') {
                if(Stack.top() == '(') {
                    return 1;
                } else {
                    while(Stack.top() != '(') {
                        Stack.pop();
                    }
                    Stack.pop();
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){

    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
}
/*
(a+b+((c*d)))
((a+b))
(a+b)
*/
// } Driver Code Ends
