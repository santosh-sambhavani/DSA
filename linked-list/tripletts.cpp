//{ https://practice.geeksforgeeks.org/problems/count-triplets--141631/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int n , x ,i , num;
    struct Node *head = NULL;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        cin>>num;
        push(&head,num);
    }
 
    /* Check the count function */
    cout << countTriplets(head, x)<< endl;
    return 0;
}
// } Driver Code Ends

void printList(struct Node* head) {
    while(head) {
        cout << " " << head->data;
        head = head->next;
    }
}

//User function Template for C++
struct Node* reverse(struct Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* forward = head->next;
    
    while(curr != NULL) {
        // cout << "\n in " << curr->data;
        curr->next = prev;
        
        prev = curr;
        curr = forward;
        forward = forward ? forward->next : NULL;
    }
    // cout << "\nout";
    return prev;
}

struct Node* copyLL(struct Node* head) {
    struct Node* newNode = new Node(head->data);
    struct Node* head1 = newNode;
    struct Node* temp = head->next;
    struct Node* temp1 = head1;
    while(temp) {
        newNode = new Node(temp->data);
        temp1->next = newNode;
        temp = temp->next;
        temp1 = temp1->next;
    }
    
    return head1;
}

int countTriplets(struct Node* head, int x) 
{ 
    if(!head || !head->next || !head->next->next) {
        return 0;
    }
    // cout << "\n original: ";
    // printList(head);
    int result = 0;
    struct Node* head1 = copyLL(head);
    // cout << "\n copied: ";
    // printList(head1);
    struct Node* reversed = reverse(head1);
    struct Node* curr = head;
    // cout << "\n76: reversed: ";
    cout << "\n ";
    printList(head);
    while(curr->next->next != NULL) {
        struct Node* left = curr->next;
        struct Node* right = reversed;
        while(left->data < right->data) {
            cout << "\n===> 109 curr: " << curr->data 
                 << " || " << left->data 
                 << " || " << right->data;
            int sum = curr->data + left->data + right->data;
            if(sum == x) {
                result++;
                left = left->next;
                right = right->next;
            } else if (sum < x) {
                left = left->next;
            } else {
                right = right->next;
            }
        }
        curr = curr->next;
    }
    
    cout << "\n ans: ";
    return result;
} 
