//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Queue {
    public:
        stack<int> s;
    
    private:
        void insertAtBottom(stack<int> &s, int x) {
            if(s.empty()) {
                s.push(x);
                return;
            }
            
            int temp = s.top();
            s.pop();
            
            insertAtBottom(s, x);
            
            s.push(temp);
        }
    
    public: 
        void print() {
            stack<int> s1 = s;
            cout << "\n queue: ";
            while(!s1.empty()) {
                cout << " " << s1.top();
                s1.pop();
            }
        }
        
        void push(int x) {
            stack<int> s1 = s;
            insertAtBottom(s1, x);
            s = s1;
        }
        
        int pop() {
            if(s.empty()) {
                return -1;
            } 
            int val = s.top();
            s.pop();
            return val;
        }
        
        int front() {
            return s.empty() ? -1 : s.top();
        }
};

// Driver program to test above functions
int main() {
    
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    q.print();
    cout << "\n front_initially: " << q.front();
    cout << " poped: " << q.pop();
    
    q.print();
    
    cout << " front_after: " << q.front();
    
    return 0;
}



