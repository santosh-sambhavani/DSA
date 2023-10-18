#include <bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int start, int end) {
    int mid = start + ((end - start) / 2);
    // cout << "\n s: " << start << " e: " << end << " mid: " << mid << " size: " << size;

    if (end == mid && start == end) {
        return arr[mid];
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
    int ans = findPivot(arr, 0, n-1);
    cout << "\nPivot element is: " << ans;
}

/*
6
12 15 43 50 1 10 



*/



