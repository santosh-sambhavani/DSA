#include <bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int start, int end, int size) {
    int mid = start + ((end - start) / 2);
    // cout << "\n s: " << start << " e: " << end << " mid: " << mid << " size: " << size;
    
    // cout << "\n consitions: " << (mid == size - 1 && start == mid) 
    // << (mid == 0 && end == mid) 
    // << (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]);
    if ((mid == size - 1 && start == mid) 
        || (mid == 0 && end == mid) 
        || (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
    ) {
        return arr[mid];
    }
    
    // mid is on left slop 
    if (arr[mid] >= arr[mid-1] && arr[mid] < arr[mid+1]) 
        return findPeak(arr, mid + 1, end, size);
    
    // mid is on right slop
    if (arr[mid] < arr[mid-1] && arr[mid] >= arr[mid+1])
        return findPeak(arr, start, mid - 1, size);
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int ans = findPeak(arr, 0, n-1, n);
    cout << "\nPeak element is: " << ans;
}

/*
cases:
6
1 10 11 15 7 5

3 
1 1 11

3 
11 1 1

5 
1 2 3 4 5

5 
5 4 3 2 1
*/
