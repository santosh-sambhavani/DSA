//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
        long long m = pow(10, 9) + 7, max = *max_element(a.begin(), a.end());
        vector<long long> response;
        vector<long long> factMap(max + 1);
        factMap[0] = 1;
        factMap[1] = 1;
        for(long long i = 2; i <= max; i++) {
            factMap[i] = (factMap[i-1] * i) % m;
        }
        for(auto &it: a) {
            response.push_back(factMap[it]);
        }
        return response;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
