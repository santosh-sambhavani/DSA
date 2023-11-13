/*
* Approach 1: One approach is to use extra LL as we implement for array problem
* Approach 2: Another approach is to use same LLs and insert Nodes in between where 
*   data should ne for sorted
*/

//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int n,m;
    cin>>n>>m;

    int data;
    cin>>data;
    struct Node *head1 = new Node(data);
    struct Node *tail1 = head1;
    for (int i = 1; i < n; ++i)
    {
        cin>>data;
        tail1->next = new Node(data);
        tail1 = tail1->next;
    }

    cin>>data;
    struct Node *head2 = new Node(data);
    struct Node *tail2 = head2;
    for(int i=1; i<m; i++)
    {
        cin>>data;
        tail2->next = new Node(data);
        tail2 = tail2->next;
    }

    Node *head = sortedMerge(head1, head2);
    printList(head);
    
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.

Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == NULL) {
        return head2;
    } 
    if(head2 == NULL) {
        return head1;
    }
    
    Node* curr1;
    Node* curr2;
    Node* next1;
    Node* next2;
    if(head1->data <= head2->data) {
        curr1 = head1;
        next1 = head1->next;
        curr2 = head2;
    } else {
        curr1 = head2;
        next1 = head2->next;
        curr2 = head1;
    }
    while(curr1 != NULL && curr2 != NULL) {
        // cout << "\n curr1: " << curr1->data << " || curr2: " << curr2->data << " || ";
        if(next1 == NULL && curr2 != NULL) { 
            curr1 -> next = curr2;
            break;
        }
        if(curr2->data >= curr1->data && curr2->data <= next1->data) {
            next2 = curr2->next;
            
            curr2->next = NULL;
            curr1->next = curr2;
            curr2->next = next1;
            
            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = curr1->next;
            if(next1 != NULL)
                next1 = next1->next;
        }
        // printList(head2);
    }
    
    return head1->data <= head2->data ? head1 : head2;
}   
