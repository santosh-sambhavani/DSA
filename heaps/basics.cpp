#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<int> heap) {
    for(auto i: heap) {
        cout << i << " ";
    }
}

void heapifyBottopToUp(vector<int> &heap, int index) {
    if (index == 0) {
        return ;
    }
    
    int parent = (index - 1) / 2;
    if (heap[index] > heap[parent]) {        
        swap(heap[index], heap[parent]);
        heapifyBottopToUp(heap, parent);
    }
}

void insert(vector<int> &heap, int data) {
    heap.push_back(data);
    
    heapifyBottopToUp(heap, heap.size()-1);
}

void heapify(vector<int> &heap, int index, int n) {
    int largest = index;
    
    int left = (2 * index) + 1;
    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    
    int right = (2 * index) + 2;
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }
    
    if (index != largest) {
        swap(heap[index], heap[largest]);
        heapify(heap, largest, n);
    }
    
}

void deleteFromHeap(vector<int> &heap) {
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    heapify(heap, 0, heap.size());
}

void heapifyArray(vector<int> &arr) {
    int n = arr.size();
    
    for (int index = n/2; index >= 0; index--) {
        heapify(arr, index, n);
    }
}

vector<int> heapSort(vector<int> arr) {
    heapifyArray(arr);
    
    for (int i = arr.size()-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
    
    return arr;
}

int main() {
    vector<int> heap;
    
    /* operation 1 */
    // insert(heap, 43);
    // insert(heap, 100);
    // insert(heap, 10);
    // insert(heap, 15);
    // insert(heap, 45);
    // insert(heap, 55);
    
    /* operation 2 */
    // deleteFromHeap(heap);
    
    // cout << "\n ==> Heap: ";
    // print(heap);
    
    /* operation 3 */
    // vector<int> arr = {1,2,3,4,5,6,7};
    
    // heapifyArray(arr);
    
    // cout << "\n ==> Heap: ";
    // print(arr);
    
    /* operation 4 */
    
    // vector<int> arr = {10, 23, 5, 32, 7};
    // vector<int> arr = {1,2,3,4,5,6,7};
    vector<int> arr = {7, 6, 5, 4, 3, 2, 1};
    vector<int> sorted = heapSort(arr);
    
    cout << "\n ==> original: ";
    print(arr);
    
    cout << "\n ==> Sorted: ";
    print(sorted);
}


