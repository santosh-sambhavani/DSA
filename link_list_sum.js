class Solution {
    //Function to add two numbers represented by linked list.
    addTwoLists(first, second)
    {
        let rev_1 = this.reverse(first);
        let rev_2 = this.reverse(second);
        let sum_head = null;
        let sum_tail = null;
        let carry = 0;
        let temp = 0;
        
        while(rev_1 || rev_2) {
            
            if(rev_1 && rev_2){
                temp = carry + rev_1.data + rev_2.data;
                rev_1 = rev_1.next;
                rev_2 = rev_2.next;
            }
            else if(rev_1){
                temp = carry + rev_1.data;
                rev_1 = rev_1.next;
            }
            else {
                temp = carry + rev_2.data;
                rev_2 = rev_2.next;
            }
            
            if(!sum_tail) {
                sum_head = new Node(temp % 10);
                sum_tail = sum_head;
            }
            else {
                sum_tail.next = new Node(temp % 10);
                sum_tail = sum_tail.next;
            }    
            
            carry = Math.floor(temp / 10);
        } 
        
        if(carry !== 0) {
            sum_tail.next = new Node(carry);
        }
        
        let ans = this.reverse(sum_head);
        
        return ans; 
    }
    
    reverse(head) {
        let curr = head;
        let pre = null;
        let post = curr;
        while(curr != null) {
            post = curr.next;
            curr.next = pre;
            pre = curr;
            curr = post;
        }
        head = pre;
        return head;
    }
}
