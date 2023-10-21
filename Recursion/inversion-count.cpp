//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  private: 
    long long int merge(long long nums[], long long start, long long end) {
        long long i, j, mid, k=0, invCount = 0;
        mid = start + (end - start) / 2;
        i = start;
        j = mid+1;
        
        vector<long long> temp(end-start+1);
        while (i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else if(nums[j] < nums[i]) {
                temp[k++] = nums[j++];
                invCount += mid - i + 1;
            }
        }
        
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= end) temp[k++] = nums[j++];
        
        for(int x = start, index = 0; x <= end; x++, index++) {
            nums[x] = temp[index];
        }
        
        return invCount;
    }
    
    long long int mergeSort(long long nums[], long long start, long long end) {
        if(start >= end) {
            return 0;
        }
        
        long long mid = start + (end - start) / 2;

        long long leftInvCount = mergeSort(nums, start, mid);
        
        long long rightInvCount = mergeSort(nums, mid+1, end);
        
        return leftInvCount + rightInvCount + merge(nums, start, end);
    }
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N-1);         
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
