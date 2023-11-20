//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

struct node* reverse(struct node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct node* head1 = reverse(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return head1;
}

struct node* partition(struct node* head) {
    int pivotValue = head->data;
    
    // find count for pivot value    
    int count = 0;
    struct node* temp = head->next;
    while(temp != NULL) {
        cout << "\n condition: " << (temp != NULL);
        cout << " || temp: " << temp->data << " || " 
             << pivotValue << " || " 
             << count << " || ";
        if(temp->data < pivotValue) {
            count++;
        }
        temp = temp->next;
    }
    
    cout << "\n ===== 118 count: " << count;
    /* swap pivot node value with head value */
    struct node* pivotNode = head;
    while(count>0) {
        count--;
        pivotNode = pivotNode->next;
    }
    int tempInt = head->data;
    head->data = pivotNode->data;
    pivotNode->data = tempInt;
    
    
    /* take all smalller value to left & hifher to right of pivot node*/
    struct node* left = head;
    struct node* right = pivotNode->next;
    while(left != pivotNode->next && right != NULL) {
        right = reverse(right);
        
        while(left->data < pivotNode->data) {
            left = left->next;
        }
        
        while(right->data >= pivotNode->data) {
            right = right->next;
        }
        
        if(left != pivotNode->next && right != NULL) {
            int tempInt = left->data;
            left->data = right->data;
            right->data = tempInt;
        }
        
        pivotNode->next = reverse(pivotNode->next);
    }
    
    return pivotNode;
}

struct node* quickSortRecur(struct node* &head) {
    if(head == NULL || head->next == NULL) 
        return head;
    cout << "\n =======> 154: ";
    printList(head);
    struct node* partitionNode = partition(head);
    
    cout << "\n158: partitionNode: " << partitionNode->data;
    struct node* left = head;
    struct node* right = partitionNode->next;
    partitionNode->next = NULL;
    
    // left part 
    left = quickSortRecur(left);
    
    // right part
    right = quickSortRecur(right);
    
    partitionNode->next = right;
    
    return head;
}

void quickSort(struct node **headRef) {
    struct node* res = quickSortRecur(*headRef);
}

/*
2
6
97 50 64 79 11 58 
9
70 99 4 88 71 8 12 70 27
*/
