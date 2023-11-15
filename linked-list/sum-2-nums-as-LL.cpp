/*
* The catch of the problem is to reverse both linked lists to traverse it in to reverse order 
* as we can't move in reverse as arrays
*/
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

class Solution
{
    private:
    struct Node* reverse(struct Node* head) {
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* forward = head->next;
        
        while(curr!=NULL) {
            curr->next = prev;
            prev = curr;
            curr = forward;
            forward = forward ? forward->next : NULL;
        }
        
        return prev;
    }
    
    struct Node* insertAtTail(struct Node* &tail, struct Node* head, int data) {
        struct Node* temp = new Node(data);
        if(head == NULL) {
            head = temp;
            tail = temp;
            return head;
        }
        tail->next = temp;
        tail = temp;
        return head;
    }
    
    public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        
        struct Node* p1 = first;
        struct Node* p2 = second;
        struct Node* result = NULL;
        struct Node* resTail = NULL;
        
        int carry = 0;
        while(p1 != NULL || p2 != NULL || carry != 0) {
            int val1 = 0, val2 = 0, sum = 0;
            if(p1 != NULL)
                val1 = p1->data;
            if(p2 != NULL) 
                val2 = p2->data;
            
            sum = val1 + val2 + carry;
            carry = sum / 10;
            int ans = sum % 10;
            
            result = insertAtTail(resTail, result, ans);
            
            p1 = p1 ? p1->next : NULL;
            p2 = p2 ? p2->next : NULL;
        }
        
        return reverse(result);
    }
};

int main()
{
    int n, m;
    
    cin>>n;
    Node* first = buildList(n);
    
    cin>>m;
    Node* second = buildList(m);
    Solution ob;
    Node* res = ob.addTwoLists(first,second);
    printList(res);
    return 0;
}
