//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
        queue<int> q;
    
    public: 
        void print() {
            queue<int> q1 = q;
            cout << "\n stack: ";
            while(!q1.empty()) {
                cout << " " << q1.front();
                q1.pop();
            }
        }
        
        void push(int x) {
            q.push(x);
            
            for(int i = 0; i < q.size() - 1; i++) {
                int val = q.front();
                q.pop();
                q.push(val);
            }
        }
        
        int pop() {
            if(q.empty()) {
                return -1;
            } 
            int val = q.front();
            q.pop();
            return val;
        }
        
        int top() {
            if(q.empty())
                return -1;
            return q.front();
        }
};

// Driver program to test above functions
int main() {
    
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    s.print();
    cout << "\n top_initially: " << s.top();
    cout << " poped: " << s.pop();
    
    s.print();
    
    cout << " top_after: " << s.top();
    
    return 0;
}



