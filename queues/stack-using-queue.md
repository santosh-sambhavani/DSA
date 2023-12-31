https://www.geeksforgeeks.org/implement-stack-using-queue/
### A Stack can be implemented using two queues.
  1. making push operation costly
    - Follow the below steps to implement the push(s, x) operation: 
      - Enqueue x to q2.
      - One by one dequeue everything from q1 and enqueue to q2.
      - Swap the queues of q1 and q2.
    - Follow the below steps to implement the pop(s) operation: 
      - Dequeue an item from q1 and return it.
  2. making pop operation costly
    - Follow the below steps to implement the push(s, x) operation: 
      - Enqueue x to q1 (assuming the size of q1 is unlimited).
    - Follow the below steps to implement the pop(s) operation: 
      - One by one dequeue everything except the last element from q1 and enqueue to q2.
      - Dequeue the last item of q1, the dequeued item is the result, store it.
      - Swap the names of q1 and q2
      - Return the item stored in step 2
### stack implementation using one queue
- The idea behind this approach is to make one queue and push the first element in it. 
- After the first element, we push the next element and then push the first element again and finally pop the first element. 
- So, according to the FIFO rule of the queue, the second element that was inserted will be at the front
  and then the first element as it was pushed again later and its first copy was popped out. 
- So, this acts as a Stack and we do this at every step i.e. from the initial element to the second last element,
  and the last element will be the one that we are inserting and since we will be pushing the initial elements after
  pushing the last element, our last element becomes the first element.
