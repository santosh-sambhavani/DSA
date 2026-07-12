```
# Leetcode 92. Reverse Linked List II
# Input: head = [1,2,3,4,5], left = 2, right = 4
# Output: [1,4,3,2,5]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:

        if not head or left == right:
            return head

        dummy = ListNode(0, head)
        prev = dummy
        leftPrev = None
        for _ in range(left):
            leftPrev = prev
            prev = prev.next
        
        leftNode = prev
        curr = prev.next

        for _ in range(right - left):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        leftNode.next = curr
        leftPrev.next = prev

        return dummy.next
```
------------------------------------------------------------------------------------------------------------------------------------
<img width="1457" height="716" alt="Screenshot 2026-07-12 at 7 14 20 PM" src="https://github.com/user-attachments/assets/e8177398-e783-4234-8c42-ec4a9ae28e93" />

```

# Leetcode 24. Swap Nodes in Pairs
# Input: head = [1,2,3,4]
# Output: [2,1,4,3]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        curr = head
        next = curr.next
        head = curr.next
        prev = None
        while curr != None and curr.next != None:
            curr.next = next.next
            next.next = curr
            if prev:
                prev.next = next
            
            prev = curr
            curr = curr.next
            if curr != None:
                next = curr.next

        return head
```
