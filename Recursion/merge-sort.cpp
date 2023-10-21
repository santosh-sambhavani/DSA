#include <bits/stdc++.h>
using namespace std;

// https://github.com/loveBabbar/CodeHelp-DSA-Busted-Series/blob/main/Lecture035%20Recursion%20Day5/mergeSort.cpp

void printVector(vector<int> v) {
    for(auto it: v) {
        cout << " " << it;
    }
}

void merge(vector<int>& nums, int start, int end) {
    // cout << "\nMerge s: " << start << " e: " << end;
    int i, j, mid, k=0;
    mid = start + (end - start) / 2;
    i = start;
    j = mid+1;
    
    // cout << " mid: " << mid << " i: " << i << " j: " << j;
    
    vector<int> temp(end-start+1);
    while (i <= mid && j <= end) {
        if(nums[i] < nums[j]) {
            temp[k++] = nums[i++];
        } else if(nums[j] < nums[i]) {
            temp[k++] = nums[j++];
        } else if(nums[i] == nums[j]){
            temp[k++] = nums[i++];
            temp[k++] = nums[j++];
        }
    }
    
    while(i <= mid) temp[k++] = nums[i++];
    while(j <= end) temp[k++] = nums[j++];
    
    for(int x = start, index = 0; x <= end; x++, index++) {
        nums[x] = temp[index];
    }
    // cout << " || ";
    // printVector(temp);
}

void mergeSort(vector<int>& nums, int start, int end) {
    // cout << "\n====s: " << start << " e: " << end;
    if(start >= end) {
        return;
    }
    
    int mid = start + (end - start) / 2;
    // cout << " mid: " << mid;
    
    mergeSort(nums, start, mid);
    
    mergeSort(nums, mid+1, end);
    
    merge(nums, start, end);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    mergeSort(nums, 0, nums.size() - 1);
    cout << "\nSorted array is: ";
    printVector(nums);
}

/*

6
10 5 8 1 12 7


15
3 7 0 1 5 8 3 2 34 66 87 23 12 12 12

*/


