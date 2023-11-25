### Problem: Clone linked list contains ramdom pointer
- Approach 1:
  - Copy the original linked list & create cloned one
  - iterate over the original linked list & copy random pointers code block looks like this
    ```
    while(originalNode && clonedNode) {
      logic to iterate over the original linked list & cloned linked list
      orignalNode , temp = clonedNode;
      while(temp != originalNode.random) {
        clonedNode -> random = temp;
        temp = temp->next;
      }
      originalNode = originalNode->next;
      clonedNode = clonedNode->next;
    }
    ```
  - TC = O(N^2) SC = O(1)
 
- Approach 2:
  - We can use maps to store the mapping from originalToCloned list and copy the randoms as shown in picture
  - `clonedNode->random = mapper[originalNode->random]`
  
  ![image](https://github.com/Santosh-745/DSA/assets/80413971/88a04bd8-803b-4d73-95f6-9a58f7440a6e)
  - TC = O(N) SC = O(N)

- Approach 3:
  - Third approach is for optimize second by reducing SC to constant
  - for that we can move next pointers of each node & create links as shown below & random pointers in original list still remains same

   ![image](https://github.com/Santosh-745/DSA/assets/80413971/6acef230-5edf-40ce-bcf4-f5ab9c17b6fe)
  - After that we can copy random pointers by 
  ```
    temp->next->random = temp->random->next;
    // here temp is pointer points to node of original linked list
  ```
  ![image](https://github.com/Santosh-745/DSA/assets/80413971/2a25c40b-6a60-4e13-8d1d-30bea678a26b)
  - TC = O(N) SC = O(1)

### Problem: Remove duplicates from unsorted linked list
- One approach is naive one point to single node traverse all other nodes if gets duplicate remove it TC (N^2)
- Second one is first sort LL Then apply remove duplicates from sorted LL TC (NlogN)
- Third one is using map TC(N) SC(N)

### Problem: Merge k sorted linked lists 
- We can apply same login of merge 2 sorted linked list by merging 2 linked lists & merge resultant LL with next LL
- But even we can manage priority-queue & use min heap to use logic like pointer for every linked list
- We can get LL with node has min data & move it's pointer to next node ( same as merge 2 sorted LL )
