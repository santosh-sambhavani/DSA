// https://www.geeksforgeeks.org/quick-sort/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high) {
            int partitionIndex = partition(arr, low, high);
            
            quickSort(arr, low, partitionIndex - 1);
            
            quickSort(arr, partitionIndex + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot = high, left = low, currIndex = low; 
       
        while(currIndex < high) {
            if(arr[currIndex] <= arr[pivot]) {
                swap(arr[currIndex], arr[left]);
                left++;
            }
            currIndex++;
        }
        swap(arr[left], arr[pivot]);
        
        return left;
    }
};


//{ Driver Code Starts.
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
// } Driver Code Ends
