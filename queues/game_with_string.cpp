//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void printPQ (priority_queue<int> pq) {
        priority_queue<int> pq1 = pq;
        cout << "\n =======> Priority queue: ";
        while(!pq.empty()) {
            int top = pq.top();
            cout << " " << top;
            pq.pop();
        }
        cout << "\n";
    }
    int minValue(string s, int k){
        
        sort(s.begin(), s.end());
        priority_queue<int> pq;
        
        string tmp = s;
        int count = 0;
        for(int i = 0; i < tmp.size(); i++) {
            if(i != 0 && tmp[i-1] != tmp[i]) {
                pq.push(count);
                count = 0;
            }
            count++;
        }
        pq.push(count);
        
        while(k > 0) {
            int x = pq.top();
            x--;
            pq.pop();
            pq.push(x);
            k--;
        }
        
        printPQ(pq);
        int ans = 0;
        while(!pq.empty()) {
            int top = pq.top();
            ans += pow(top, 2);
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    string s;
    int k;
    cin>>s>>k;
    
    Solution ob;
    cout<<"\n============> ans is: " <<ob.minValue(s, k)<<"\n";
    return 0;
}
// } Driver Code Ends

/*
aabcbcbcabcc
3

abccc
1
*/
