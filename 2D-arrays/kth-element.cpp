/*
The main idea is to check for every possible ans the count of smaller elements than the possible sol
if the count we get is less than move loew to mid else high to mid
*/


//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
      int n;
      cin>>n;
  
      for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              cin>>mat[i][j];
      int r;
      cin>>r;
      cout<<kthSmallest(mat,n,r)<<endl;
}

// } Driver Code Ends

int upper_bound(int row[MAX], int mid, int n) {
    for(int i = 0; i < n; i++) {
        if(row[i] > mid) return i;
    }
    return n;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = 0, high = 10000;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += upper_bound(mat[i], mid, n);
        }
        if (count <= k-1) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return low;
}
