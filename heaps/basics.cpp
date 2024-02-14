#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void insert(vector<int> &heap, int data) {
    heap.push_back(data);
    
    int index = heap.size() - 1;
    int parentIndex = index / 2;
    while(heap[index] > heap[parentIndex] && index > 1) {
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = index / 2;
    }
}

void deleteFromHeap(vector<int> &heap) {
    int last = heap.size() - 1;
    heap[1] = heap[last];
    
    heap.pop_back();
    int index = 1;
    int leftChild = index * 2;
    int rightChild = (index * 2) + 1;
    while(
        (leftChild <= last && heap[index] < heap[leftChild]) || 
        (rightChild <= last && heap[index] < heap[rightChild])
    ) {
        int maxChild = heap[leftChild] >= heap[rightChild] ? leftChild : rightChild;
        swap(heap[index], heap[maxChild]);
        index = maxChild;
        leftChild = index * 2;
        rightChild = (index * 2) + 1;
    }
}

void print(vector<int> heap) {
    for(auto i: heap) {
        cout << i << " ";
    }
}

int main() {
    
    vector<int> heap = {-1};
    
    insert(heap, 60);
    insert(heap, 50);
    insert(heap, 40);
    insert(heap, 30);
    insert(heap, 20);
    insert(heap, 55);
    insert(heap, 70);
    
    cout << "\n Heap: ";
    print(heap);
    
    heap = {55, 54, 53, 50, 52};
    
    deleteFromHeap(heap);
    
    cout << "\n Heap: ";
    print(heap);
}


