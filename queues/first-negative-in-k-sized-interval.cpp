//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int i;
    long long int n;
    cin >> n;
    long long int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int k;
    cin >> k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}

// } Driver Code Ends

void printQueue (queue<long long int> q) {
    queue <long long int> temp = q;
    cout << "\tqueue is: ";
    while(!temp.empty()) {
        cout << " " << temp.front();
        temp.pop();
    }
}


vector<long long> printFirstNegativeInteger(
    long long int a[],
    long long int n,
    long long int k
) {
    queue<long long int> q;
    vector<long long> ans;
   
    for (int i = 0; i < k; i++) {
        if(a[i] < 0) {
            q.push(i);
        }
    }
    
    int start = 0; int end = k-1;
    while(end < n) {
        cout << "\n stert: " << start 
             << " end: " << end;
        //      << " front: " << q.front() 
        //      << " cond: " << (q.front() < start;
        
        // check if q.front is in current frame
        if(!q.empty() && q.front() < start) {
            q.pop();
        }
        
        if(!q.empty()) {
            printQueue(q);
        }
        
        // add ans for current frame
        if (q.empty()) {
            ans.push_back(0);
        } else {
            // cout << " ans_index: " << q.front();
            ans.push_back(a[q.front()]);
        }
        
        // move to next frame
        start++; end++;
        
        // check if newly added number is negative
        if(a[end] < 0) {
            q.push(end);
        }
    }

    return ans;
}
    
    
