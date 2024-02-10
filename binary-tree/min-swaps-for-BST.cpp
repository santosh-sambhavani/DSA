//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class element {
    public:
        int index;
        int value;
};
class Solution{
  private:
    void inorder(vector<int>& arr, vector<element>& in, int n, int index, int &curr) {
        if (index >= n) {
            return ;
        }
        
        inorder(arr, in, n, 2*index+1, curr);
        in.push_back({ curr, arr[index] });
        curr++;
        inorder(arr, in, n, 2*index+2, curr);
    }
    
    static bool compareInterval(element i1, element i2) 
    { 
        return (i1.value < i2.value); 
    }
    
    void print(vector<element> v) {
        
        for(auto it: v) {
            cout << "\n index: " << it.index 
                 << " val: " << it.value;
        }
        
    }
  public:
    int minSwaps(vector<int>&arr, int n){
        vector<element> in;
        int curr = 0;
        inorder(arr, in, n, 0, curr);
        
        cout << "\n ==> inorder before: ";
        print(in);
        
        vector<element> sorted = in;
        sort(sorted.begin(), sorted.end(), compareInterval);
        
        cout << "\n ==> inorder after: ";
        print(in);
        cout << "\n ==> sorted after: ";
        print(sorted);
        
        int count = 0, currIndex = 0;
        while(currIndex < n) {
            cout << "\n curr: " << currIndex 
                 << " original: " << sorted[currIndex].index
                 << " val" << sorted[currIndex].value;
            if (currIndex != sorted[currIndex].index) {
                swap(sorted[currIndex], sorted[sorted[currIndex].index]);
                count++;
                continue;
            } else {
                currIndex++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int n;
    cin >> n;
    vector<int>A(n);
    for(int i = 0 ; i < n; i++){
        cin >> A[i];
    }
    Solution ob;
    int ans = ob.minSwaps(A, n);
    cout << "\n ==> ans: " << ans<<endl;
    
	return 0;
}

/*
This is the problem to solve min swaps needed to sort any array

7
5 6 7 8 9 10 11
*/
