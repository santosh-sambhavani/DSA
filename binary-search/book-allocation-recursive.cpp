//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int arr[], int N, int M, int sol) {
    int sum = 0, students = 1;
    for(int i = 0; i < N; i++) {
        if(arr[i] > sol) return false;
        if(sum + arr[i] <= sol) {
            sum += arr[i];
        } else {
            students++;
            if(students > M) {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

//Function to find minimum number of pages.
int findPages(int arr[], int start, int end, int n, int m, int ans) 
{
    if (start > end) return ans;
    int mid = start + (end - start) / 2;
    // cout << "\n " << start << " || " << end << " || " << ans << " mid: " << mid;
    
    
    // cout << "\nisPossibleSolution: " << isPossibleSolution(arr, n, m, mid);
    if(isPossibleSolution(arr, n, m, mid)) 
        ans = findPages(arr, start, mid - 1, n, m, mid);
    else 
        ans = findPages(arr, mid + 1, end, n, m, ans);
    
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[100];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    if(n < m) return -1;
    int start = INT_MIN, end = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        start = max(start, arr[i]);
        end += arr[i];
    }
    ans = findPages(arr, start, end, n, m, ans);
    cout << "Ans is: " << ans;
}

// } Driver Code Ends
