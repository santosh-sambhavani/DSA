#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v) {
    for(auto it: v) {
        cout << " " << it;
    }
}


vector<int> selectionSort(vector<int>& nums, int i) {
    if (i == nums.size()) return nums;
    
    for (int j = i; j < nums.size(); j++) {
        if (nums[i] > nums[j]) {
            swap(nums[i], nums[j]);
        }
    }
    
    return selectionSort(nums, ++i);
}

vector<int> bubbleSort(vector<int>& nums, int i) {
    if (i == nums.size()) return nums;
    
    for (int j = 0; j < (nums.size() - i - 1); j++) {
        if (nums[j] > nums[j+1]) {
            swap(nums[j], nums[j+1]);
        }
    }
    
    return bubbleSort(nums, ++i);
}

vector<int> insertionSort(vector<int>& nums, int i) {
    if (i == nums.size()) return nums;
    int temp = nums[i], j = i - 1;
    while (j >= 0) {
        if (nums[j] > temp) {
            nums[j+1] = nums[j];
        } else if (nums[j] <= temp) {
            break;
        }
        j--;
    }
    nums[j+1] = temp;
    return insertionSort(nums, ++i);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    // vector<int> sorted = selectionSort(nums, 0);
    // vector<int> sorted = bubbleSort(nums, 0);
    vector<int> sorted = insertionSort(nums, 1);
    cout << "\nSorted array is: ";
    printVector(sorted);
}

/*
5
10 5 8 1 13

5
5 4 3 2 1

7
10 5 8 13 13 7 12

*/




