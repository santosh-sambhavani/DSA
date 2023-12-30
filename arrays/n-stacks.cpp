#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int freespot;
    int *top;
    int *next;
    NStack(int N, int S)
    {
        arr = new int[S];
        freespot = 0;
        top = new int[N];
        next = new int[S];

        // top initialize 
        for(int i = 0; i < N; i++) {
            top[i] = -1;
        }

        // initialize next
        for(int i = 0; i < S; i++) {
            next[i] = i+1;
        }
        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1) {
            return false;
        }

        // find index where to push 
        int index = freespot;

        // assign value
        arr[index] = x;

        // update the freespot
        freespot = next[index]; // 3

        // update next array
        next[index] = top[m-1]; // -1

        // update top for that stack
        top[m-1] = index;  // 2

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1) {
            return -1;
        }
        // noting index to return value;
        int index = top[m-1];

        // top--
        top[m-1] = next[index];

        // update next array
        next[index] = freespot;

        // update freespot to current index
        freespot = index;

        // return value
        return arr[index];
    }
};
