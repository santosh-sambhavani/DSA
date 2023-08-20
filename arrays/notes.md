## Problem: Find duplicates in array
- using index marking method 
  - mark element on index as current element (i.e. if current element is 2 than element on arr[2]) doing * (-1)
  - than if we find any element for current element as index negative than current element is one of the duplicates
  - we can use this logic to find single duplicate pair as well

## Problem Find triplates matching sum value x in an array
- First sort the whole array & then 
	- use two pointers with binary serach logic 
		- Loop over 1 to n to fix one element 
		- then use pointers from it's next element to last element 
			- now if the sum of this threes are greater than wanted value than decreament pointer 2 
			- if less than desired value than increament pointer 1
			- and if matches than add to ans
