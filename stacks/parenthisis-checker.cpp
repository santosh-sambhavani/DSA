//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for (auto &ch: x) {
            if(ch == '{' || ch == '(' || ch == '[') {
                s.push(ch);
            } else {
                if(s.empty()) {
                    return false;
                }
                char top = s.top();
                if(
                    (ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    ch == '}' && top == '{'
                ) {
                    s.pop();
                } else {    
                    // for cases: extra closed brackets `())))))`
                    return false;
                }
            }
        }
        
        // s.empty() for cases extra opened brackets `((()`
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   string a;
   cin>>a;
   Solution obj;
   if(obj.ispar(a))
    cout<<"balanced"<<endl;
   else
    cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
