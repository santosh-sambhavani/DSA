#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

bool isPossible(vector<int>& arr, int n, int k, int sol) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if((arr[i] - sol) > 0) {
            sum += (arr[i] - sol);
            if(sum >= k)
                return true;
        }
    }
    return false;
}

int maxHight(vector<int>& arr, int n, int k) {
    int start = 0; int end = INT_MIN, ans = -1;
    for(int i = 0; i < n; i++) {
        end = max(arr[i], end);
    }
    while(start <= end) {
        int mid = start + (end - start) / 2;
        // cout << "\n " <<start << " " << end << " " << mid;
        if(isPossible(arr, n, k, mid)) {
            // cout << " isPossible ";
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
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
	cout << maxHight(arr, n, k) << endl;
	return 0;
}
