### Problem: Find index of first and last occurences of element in sorted array
- Use binary search algorithm for both first & las occurence saperately
  - when finding first occurence move end towards mid even if you find value
  - for last occurence move start pointer towards mid

### Problem: Find peek element
- Use binary search
  - if element is greater than it's next & previous element that's your ans
  - if element is on left slop move start pointer to mid
  - if element is in right slop move end pointer to mid

### Problem: Find pivot element
- Use three pointer
  - put 2 pointers at first index and one at last index
  - find sum of elements from index 1 to n-1 which is right sum & initalize left sum as 0
  - interate for next steps
    - if left sum === right sum return index
    - else move one pointer at first index to next elment & add to left sum & substract from right sum
  
