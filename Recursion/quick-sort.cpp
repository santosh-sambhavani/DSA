#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v) {
    for(auto it: v) {
        cout << " " << it;
    }
}

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start];
    
    // count number of elements smaller than pivot
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(nums[i] < pivot) count++;
    }
    
    // find right place for pivot
    int pivotIndex = start + count;
    
    swap(nums[start], nums[pivotIndex]);
    
    // get smaller elements in left & higher in right w.r.t pivot
    int left = start, right = end;
    while (left < pivotIndex && right > pivotIndex) {
        while (nums[left] < pivot) {
            left++;
        } 
        
        while (nums[right] >= pivot) {
            right--;
        }
        
        if (left < pivotIndex && right > pivotIndex) {
            swap(nums[left++], nums[right--]);
        }
    }
    
    return pivotIndex;
}

void quickSort(vector<int>& nums, int start, int end) {
    // cout << "\ns: " << start << " e: " << end;
    if(start >= end) {
        return ;
    }
    
    // Find right place for pivot (first element)
    int pivotIndex = partition(nums, start, end);
    // cout << " pivotIndex: " << pivotIndex;
    
    // Sort left elements of pivot
    quickSort(nums, start, pivotIndex-1);
    
    // Sort right elements of pivot
    quickSort(nums, pivotIndex+1, end);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    quickSort(nums, 0, nums.size() - 1);
    cout << "\nSorted array is: ";
    printVector(nums);
}

/*
7
9 9 9 8 2 3 1

6
10 5 8 1 12 7


15
3 7 0 1 5 8 3 2 34 66 87 23 12 12 12

42
468 335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323
*/




