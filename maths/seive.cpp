//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v) {
    cout << "\nVector: ";
    for(int &it: v) {
        cout << " " << it;
    }
}

vector<int> seive(int n) {
    vector<bool> primes(n, true);
    for (int i = 2; i * i <= n; i++) {
      // why i * i <= n ref: https://youtu.be/7VPA-HjjUmU?si=91VLk_do-qbx601Y
        if (primes[i]) {
            for(int j = 2; i * j <= n; j++) {
                primes[i * j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if(primes[i]) ans.push_back(i);
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> primes = seive(n);
    printVector(primes);
    cout << "============== ends ===================";
}

