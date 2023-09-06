### Problem: Find index of first and last occurences of element in sorted array
- Use binary search algorithm for both first & las occurence saperately
  - when finding first occurence move end towards mid even if you find value
  - for last occurence move start pointer towards mid

### Problem: Find peek element: [exa: 1, 2, 3, 2, 1]
- Use binary search
  - if element is greater than it's next & previous element that's your ans
  - if element is on left slop move start pointer to mid
  - if element is in right slop move end pointer to mid

### Problem: Find pivot element in sorted rotated array  [exa: 3, 4, 5, 1, 2]
- For sorted rotated array the key position is first element of array as we can identify the position of any element by comparing that element with first element
- let say if any element in array is greater than first element then it will be on left slop
- And if the element is less than first element than it will be on right slop
- Using this we can narrow down our serch space towards pivot element

## Book allocation problem:
- The logic is if we can allocate the books successfully with reference of any number then by the referring all the numbers greater than that we can allocate books surely.
- And same if we can't allocate books by any number then by refering all the numbers less than that we can't allocate books as well
- By using this logic we can narrow down our search space
- In this type of problem we can decide that binary search going to be applied by checking the logic of test case with it's answers
  - we can check if all values greater than or less than answer is definitely the answer if this type of case occurs than their we can use binary search algorithm
  - the template for this type of problems would be same like book allocation just the logic of isPossible would be change based on the question
  - refer book allocation problem

### Problem: Find pivot element (element which has equal sum in it's right & left)
- Use three pointer
  - put 2 pointers at first index and one at last index
  - find sum of elements from index 1 to n-1 which is right sum & initalize left sum as 0
  - interate for next steps
    - if left sum === right sum return index
    - else move one pointer at first index to next elment & add to left sum & substract from right sum
  
