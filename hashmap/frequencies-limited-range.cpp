//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        for (int i = 0; i < N; i++) {
            arr[i] = arr[i] - 1;
        }
        
        for (int i = 0; i < N; i++) {
            arr[arr[i] % P] = arr[arr[i] % P] + P;
        }
        
        for (int i = 0; i < N; i++) {
            arr[i] = arr[i]/P;
        }
    }
}; 

// 2 3 2 3 5

// 3 -1 2 3 5

// 0 0 -1 3 5


//{ Driver Code Starts.

int main() 
{ 

	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	return 0; 
}


// 5 
// 2 3 2 3 5
// 5

// 4
// 3 3 3 3
// 3


// } Driver Code Ends
