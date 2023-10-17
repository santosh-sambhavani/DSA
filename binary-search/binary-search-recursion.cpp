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

int main() {
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = binarySearch(arr, 0, n-1, k);
    cout << "Ans is: " << ans;
}
