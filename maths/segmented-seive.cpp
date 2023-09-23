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

vector<int> segementedSeive (int left, int right, vector<int> primesTillRootN, vector<int> primes) {
    
    // cout << "\n " << left << " || " << right;
    
    vector<bool> isPrimes(right - left + 1, true);
    for (int prime: primesTillRootN) {
        // to find nearest multiple of prime w.r.t left
        int start = (left / prime) * prime; 
        
        // and if that multiple is less than left than get next multiple
        if(start < left) start += prime;
        
        // to not mark the prime as
        if(start == prime) start += prime;
        
        // cout << " >> start: " << start;
        
        // loop over every multiple of prime in the range & amrk it false
        for(int i = start; i <= right; i += prime) {
            isPrimes[i - left] = false;    
        }
    }
    // get all primes in range
    for(int i = 0; i <= right - left; i++) {
        if(isPrimes[i]) primes.push_back(i + left);
    }
    return primes;
}

int main() {
    int n;
    cin >> n;
    // why only primes & why till root n 
    /* 
        any number have the factors of multiple only till root n 
        after that the factors repeat with alternative positions that's why only till root n 
        and root n of n will be sufficient to 
        find for all numbers less than n that the number less than n is prime or not
    */ 
    
    /*
        why we have choosen only primes because the numbers that are multiple of 
        non prime number will be also multiple of prime number till root number
        so no need to consider non prime numbers to find multiples
    */
    vector<int> primesTillRootN = seive((int)sqrt(n));
    
    vector<int> primes;
    int interval = (int)sqrt(n);
    for(int left = 2; left <= n; left += interval) {
        int right = min(left + interval - 1, n);
        primes = segementedSeive(left, right, primesTillRootN, primes);
    }
    printVector(primes);
}

