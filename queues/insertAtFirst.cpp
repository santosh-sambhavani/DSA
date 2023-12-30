#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q) {
    queue<int> g = q;
    cout << "Queue is: ";
    while (!g.empty()) {
        cout << ' ' << g.front();
        g.pop();
    }
    cout << '\n';
}

void reverse(queue<int> &q) {
    if (q.empty()) {
        return ;
    }
    
    int temp = q.front();
    q.pop();
    reverse(q);
    
    q.push(temp);
}

void insertAtFirst(queue<int> &q, int x) {
    q.push(x);
    
    int cnt = 0, n = q.size();
    while(cnt != n-1) {
        q.push(q.front());
        q.pop();
        cnt++;
    }
}

int main() {
    
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    printQueue(q);
    
    // reverse(q);
    
    printQueue(q);
    
    insertAtFirst(q, 5);
    
    printQueue(q);
        
    return 0;
}
