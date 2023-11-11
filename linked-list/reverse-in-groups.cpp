//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL || head -> next == NULL || k == 1) {
            return head;
        } 
        struct node* prev = NULL;
        struct node* forward = head->next;
        struct node* current = head;
        struct node* prevLast = current;
        bool isFirstIteration = true;
        
        while(current != NULL) {
            int cnt = 1;
            struct node* currLast = current;
            while (cnt <= k && current != NULL) {
                current->next = prev;
                prev = current;
                current = forward;
                forward = forward ? forward->next : NULL;
                cnt++;
            }
            // for first k groups
            if(isFirstIteration) {
                head = prev;
                isFirstIteration = false;
            }
            if(prevLast != currLast) {
                prevLast->next = prev;
                prevLast = currLast;
            }
            prev = NULL;
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    struct node* head = NULL;
    struct node* temp = NULL;
    int n;
    cin >> n;
     
    for(int i=0 ; i<n ; i++)
    {
        int value;
        cin >> value;
        if(i == 0)
        {
            head = new node(value);
            temp = head;
        }
        else
        {
            temp->next = new node(value);
            temp = temp->next;
        }
    }
    
    int k;
    cin>>k;
    
    Solution ob;
    head = ob.reverse(head, k);
    printList(head);
    return(0);
}

/*
10
1 6 10 3 5 8 9 3 6 1
4
*/
// } Driver Code Ends
