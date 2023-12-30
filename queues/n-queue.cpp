#include <bits/stdc++.h> 
class NQueue{
public:
    int freespot;
    int *arr;
    int *front;
    int *rear;
    int *next;
    NQueue(int n, int s){
        arr = new int[s];
        next = new int[s];
        front = new int[n];
        rear = new int[n];
        freespot = 0;

        // initialize front 
        for (int i = 0; i < n; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // initialize next
        for (int i = 0; i < s; i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if (freespot == -1)
            return false;
        // decide where to place value
        int index = freespot;

        // add value
        arr[index] = x;

        // update freespot
        freespot = next[index];
        
        // update front if it's first element
        if (front[m-1] == -1) {
            front[m-1] = index;
        } else {
            // else link last element with current index
            next[rear[m-1]] = index;
        }

        // update next of current index to -1 because after poping from 
        // here the queue wil be empty
        next[index] = -1;

        // update rear
        rear[m-1] = index;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    // same as pop from n stacks problem just replace front with top
    int dequeue(int m){
        if(front[m-1] == -1) {
            return -1;
        }
        // decide index to remove value from
        int index = front[m-1];

        // update front array
        front[m-1] = next[index];

        // update next array
        next[index] = freespot;

        // update freespot
        freespot = index;

        // return value;
        return arr[index];
    }
};
