#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long n) {
   if (n == 1) return x;
   long long mod = pow(10, 9) + 7;
   long long temp = (power(x, n >> 1) % mod);
   if (n & 1) {
       return x *  temp * temp;
   } else {
       return temp * temp;
   }
}

int main() {
    long long x, n;
    cin >> x >> n;

    long long ans = power(x, n);
    
    cout << "\n" << x << " raised to " << n << " is : " << ans;
}

/*

2 5

5 5

10 3

*/




