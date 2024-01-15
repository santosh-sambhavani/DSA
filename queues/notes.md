- below are the different patterns that can be identified as queue problems
- stack using queues & queue using stacks
  - https://github.com/Santosh-745/DSA/blob/main/queues/queue-using-stack.md
  - https://github.com/Santosh-745/DSA/blob/main/queues/stack-using-queue.md
- next smaller / bigger element in right / left of the every number. from this 4 type of questions can be asked. 
  even max or min in all sub arrays of size k of array is similar type of problem.
- problems with bfs patterns rotten oranges, knight walk, nearest 1 in matrix etc.
  - we can solve this problem by level wise approach
- use priority_queue whenever you need to manage descendingly sorted array or ascendingly sorted array.
    priority_queue will always give higher or smaller number when you need.
    - a priority queue is implemented as max heap by default in C++ but,
      it also provides us an option to change it to min heap by passing another parameter while creating a priority queue.
      
      ```
        int arr[6] = { 10, 2, 4, 8, 6, 9 };
        priority_queue<int, vector<int>, greater<int> > gquiz(arr, arr + 6);
      ```
    - game with strings is problem related to priority_queue
    
