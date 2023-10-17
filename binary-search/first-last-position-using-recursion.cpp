#include <bits/stdc++.h>
using namespace std;

int findFirstOccurence(int arr[], int start, int end, int k, int ans) {
    if (start > end)
        return ans;
        
    int mid = start + ((end - start) / 2);
    
    if (arr[mid] < k)
        return findFirstOccurence(arr, mid + 1, end, k, ans);
        
    if (arr[mid] >= k) {
        if (arr[mid] == k) ans = mid; // for false cases
        return findFirstOccurence(arr, start, mid - 1, k, ans);
    }
}

int findLastOccurence(int arr[], int start, int end, int k, int ans) {
    if (start > end)
        return ans;
        
    int mid = start + ((end - start) / 2);
    
    if (arr[mid] <= k) {
        if (arr[mid] == k) ans = mid;  // for false cases
        return findLastOccurence(arr, mid + 1, end, k, ans);
    }
        
    if (arr[mid] > k)
        return findLastOccurence(arr, start, mid - 1, k, ans);
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
    int firstOccurence = findFirstOccurence(arr, 0, n-1, k, -1);
    int lastOccurence = findLastOccurence(arr, 0, n-1, k, -1);
    cout << "First Occurence is: " << firstOccurence;
    cout << "\nLast Occurence is: " << lastOccurence;
}

/*
12
1 2 2 2 2 3 4 4 4 7 8 8
7
*/
