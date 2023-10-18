#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int k) {
    if (start > end)
        return -1;
    
    int mid = start + ((end - start) / 2);
    
    if (arr[mid] == k) 
        return mid;
    
    if (arr[mid] < k)
        return binarySearch(arr, mid + 1, end, k);
        
    if (arr[mid] > k)
        return binarySearch(arr, start, mid - 1, k);
}

int findPivot(int arr[], int start, int end) {
    int mid = start + ((end - start) / 2);
    // cout << "\n s: " << start << " e: " << end << " mid: " << mid << " size: " << size;

    if (end == mid && start == end) {
        return mid;
    }
    
    // mid is on left slop
    if (arr[mid] > arr[0]) 
        return findPivot(arr, mid + 1, end);
    
    // mid is on right slop
    if (arr[mid] < arr[0])
        return findPivot(arr, start, mid);
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int k, ans;
    cin >> k;
    
    int pivotIndex = findPivot(arr, 0, n-1);
    if (k == arr[0])
        ans = 0;
    else if (k > arr[0]) 
        ans = binarySearch(arr, 0, pivotIndex-1, k);
    else
        ans = binarySearch(arr, pivotIndex, n-1, k);
    
    cout << "\Element is on index: " << ans;
}

/*
6
12 15 43 50 1 10 
12
*/


