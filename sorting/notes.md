### Selection sort:
- iterate over n-1 rounds
- get min value at it's right place in every round
- Time compexity: N^2 in best & worst case
- Stable sorting: When two same data appear in the same order in sorted data without changing their position is called stable sort.
- this is the unstable algorithm (consider case {4, 2, 3, 5, 4, 1})

### Bubble sort:
- iterate over n-1 rounds
- compare near by values and swap if a[i] > a[i+1] else ignore 
- get max at n-ith position of 0 to n-i values of array in ith round
- Time complexity: Best case O(N) || Worst case O(N^2)
- Stable sorting algorith

### Insertion sort:
- Compare perticular element with all it's previous element and put element where we get smaller value than current
  - start from i = 1 consider i = 0th element as sorted
  - in every round compare ith position element with it's all previous element 
  - if ith element is less than compared value shift compared value to right
  - else break and put the element where we breaked the loop
- TC: best case: O(N) || worst case: O(N^2)
- stable slgorithm
- Adaptable algorithm
