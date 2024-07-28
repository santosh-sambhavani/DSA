// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v) {
    cout << "\nVector: ";
    for(int &it: v) {
        cout << " " << it;
    }
}

void simpleSieve(int n, vector<int> &primes) {
    vector<bool> isPrimes(n, true);
    for(int i = 2; i*i <= n; i++) {
        if (isPrimes[i]) {
            for(int j = i*i; j <= n; j += i) {
                isPrimes[j] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        if (isPrimes[i]) {
            primes.push_back(i);
        }
    }
}

void segmentedSieve(int n, vector<int> primes, vector<int> &ans) {
    int low = floor(sqrt(n));
    int high = 2 * low;
    
    // ** loop over the interval [low, high] till high is less than n
    while (high <= n) {
        vector<bool>isPrimes(low+1, true);
        // cout << "\n=====> low: " << low << " || high: " << high;
        /** loop over the primes to mark all it's multiple non-prime */
        for (int prime : primes) {
            /** calculate the first multiple of prime to start marking non prime*/
            int start = (low / prime) * prime;
            
            // cout << "\n===> start: " << start << " || prime: " <<prime;
            if (start < low) start += prime;
            
            // cout <<"\n==> start: "<<start<<" || high: "<<high;
            /** mark all multiples of prime in the interval [low, high] as non-prime*/
            for(int i = start; i <= high; i += prime) {
                isPrimes[i-low] = false;
                // cout << "\n not prime: " << i;
            }
        }

        /** add primes to the ans array after marking all multiples of prime as non-prime */
        for(int i = low; i <= high; i++) {
            if (isPrimes[i-low]) {
                ans.push_back(i);
            }
        }
        low = high;
        high += sqrt(n);
    }
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    // find all primes till sqrt(n)
    vector<int> primesTillRootN;
    simpleSieve(sqrt(n), primesTillRootN);
    
    // cout << "\n ==> primes till root n is: ";
    // printVector(primesTillRootN);
    
    vector<int> ans;
    segmentedSieve(n, primesTillRootN, ans);
    
    cout << "\n ==> primes till n is: ";
    printVector(primesTillRootN);
    printVector(ans);
    
    return 0;
}
