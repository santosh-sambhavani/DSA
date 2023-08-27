#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

bool isPossible(vector<int> &ranks, int n, int k, int sol) {
    int dishes = 0;
    for(int i = 0; i < n; i++) {
        int N = 1, R = ranks[i], minsTaken = 0;
        while(minsTaken + (N * R) <= sol) {
            minsTaken += (N * R);
            dishes++;
            // cout << "\n N : " << N << " R: " << R << " minsTaken: " << minsTaken;
            if(dishes == k) {
                return true;
            }
            N++;
        }
    }
    return false;
}

int minCookTime(vector<int> &ranks, int k)
{
    int n = ranks.size(), start = INT_MAX, ans;
    for(int i = 0; i < n; i++) {
        start = min(start, ranks[i]);
    }
    int end = start * ((k * (k + 1)) / 2);
    while(start <= end) {
        int mid = start + (end- start) / 2;
        // cout << "\n start " << start << " end:  " << end << " mid: " << mid;
        if(isPossible(ranks, n, k, mid)) {
            cout << " isPossible";
            end = mid - 1;
            ans = mid;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}



int main() {
	
	int k, n;
		
	cin >>n>>k;
// 	cout << "\n n: " << n << " m: " << m << "\n";
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	cout << minCookTime(arr, k) << endl;
	return 0;
}



