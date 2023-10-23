### Problem: merge sort
- Divide the array till it breaks to one element then merge considering it as a sorted array
- Merge all sorted arrays

### Problem: Inversion count
- The number of pairs (i, j) such that A[i] < A[j] and i > j is our inversion count
- For sorted array, it is 0 & for reverse sorted it's maximum
- We can solve it in N^2 complexity using a naive approach
- But using merge sort we can solve it in nLogn TC
- Changing conditions of the merge function
  - if nums[i] <= nums[j] (first array value is lesser or equal to second array value)
    - temp[k++] = nums[i++] add value to sorted array & increment only first Index
    - Here we did not increase second-index for cases like this 5 8 10 | 5 8 10
    - in the above example assume i on the first 5 & j on the second 5 if we increment both i & j on nums[i] == nums[j]
    - then we will miss inversion count pairs (8, 5) & (10, 5) that's why we only increment the first index & keep the second index in the same position
  - else nums[j] < nums[i] (second array value is lesser than first array value e.g. 8 8 9 10 | 5 5 15 assume i on 8 & j on 5)
    - temp[k++] = nums[j++]
    - inversion_count += (mid - i) because 5 is lesser than all the values on the left of mid so pairs will be (8,5) (8,5) (9,5) (10,5) that's why (mid - i)
- With the above changes, we can count inversions of the array

### Problem: Quick sort
- QS:
  - Return if s >= e
  - Partition using first index
  - Sort left 
  - Sort right

- Partition:
  - Check right place for first value
    - Pivot = arr[0];
    - Pivot index = 0 + count_of_small_elements_than_pivot;
    - Swap arr[0] & arr[pivot index]
  - Confirm all left values are smaller than pivot & right values are greater than pivot
    - i = start; j = end;
    - While ( i <pivot index && j > pivot index)
      - While (arr[i] <= pivot ) i++;
      - While (arr[j] >= pivot ) j++;
      - If(i < pivot index && j > pivot index )
        - Swap arr[i] & arr[j]

### Problem: Find Subsets of array
- Subsets means set of all subset
- Number of possible subsets is 2^n
- Subset problems iterate over index using recursion and add that index character to output string & ignore for other variation
  ![image](https://github.com/Santosh-745/DSA/assets/80413971/24f83406-6f0d-4285-88d9-3cad61ec2c5d)
