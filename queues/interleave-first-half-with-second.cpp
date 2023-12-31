#include <bits/stdc++.h>
using namespace std;

void print(queue<int> q) {
    queue<int> q1 = q;
    cout << "\nqueue: ";
    while(!q1.empty()) {
        cout << " " << q1.front();
        q1.pop();
    }
}

void rearrange(queue<int> &q) {
    queue<int> temp;
    int n = q.size();
    
    for (int i=0; i<n/2; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty()) {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    print(q);
    
    rearrange(q);
    
    print(q);
    
    return 0;
}



