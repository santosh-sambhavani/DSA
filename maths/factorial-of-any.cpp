//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


long long factorial(long long n) {
    if(n == 0 || n == 1) return 1;
    long long mod = pow(10, 9) + 7, response = 1;
    for(long long i = 1; i <= n; i++) {
        response = (response * (i % mod)) % mod;
    }
    return response;
}
//{ Driver Code Starts.

int main() {
    int n, i;
    cin >> n;
    cout << factorial(n);
    /*
    // for testing if answer is write
        const int MOD = 1e9 + 7;
        long long result = 1;
        
        for (int i = 1; i <= 212; i++) {
            result = (result * i) % MOD;
        }
        cout << "\n sndjns: " <<  result;
    */
}

// } Driver Code Ends
