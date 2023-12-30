//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle = 1000;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           return s.empty() ? -1 : minEle;
       }
       
        /*returns poped element from stack*/
        int pop(){
            if (s.empty()) 
                return -1;
            int value = s.top();
            if (value < minEle) {
                int tmp = minEle;
                minEle = ((2 * minEle) - value);
                s.pop();
                value = tmp;
            } else {
                s.pop();
            }
            return value;
        }
       
        /*push element x into the stack*/
        void push(int x){
            if (x < minEle) {
                s.push((2 * x) - minEle);
                minEle = x;
            } else {    
                s.push(x);
            }
        }
};

//{ Driver Code Starts.

int main()
 {
    int q;
    cin>>q;
    Solution ob;
    while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
          //push
          int att;
          cin>>att;
          ob.push(att);
       }
       else if(qt==2)
       {
          //pop
          cout<<ob.pop()<<" ";
       }
       else if(qt==3)
       {
          //getMin
          cout<<ob.getMin()<<" ";
       }
    }
    return 0;
}

// } Driver Code Ends
