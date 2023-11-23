// C++ implementation to reverse a doubly linked list
// in groups of given size
#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
	// allocate space
	Node* new_node = (Node*)malloc(sizeof(Node));

	// put in the data
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list of the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

Node* revListInGroupOfGivenSize(Node* head, int k)
{
    if(head == NULL || head->next == NULL || k == 1) {
        return head;
    }
    
    Node* curr = head;
    Node* backward = NULL;
    Node* forward = head->next;
    
    int count = 1;
    while(curr != NULL && count <= k) {
        curr->next = backward;
        curr->prev = forward;
        
        backward = curr;
        curr = forward;
        forward = forward != NULL ? forward->next : NULL;
        count++;
    }
    
    // cout << "\nback: " << backward->data 
    //      << " curr: " << curr->data
    //      << " forward: " << (forward ? forward->data : NULL);
    
    Node* head1 = revListInGroupOfGivenSize(curr, k);
    head->next = head1;
    if(head1) {
        head1->prev = head;
    }
    
    return backward;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2 
	push(&head, getNode(2));
	push(&head, getNode(4));
	push(&head, getNode(8));
	push(&head, getNode(10));
	push(&head, getNode(20));
	push(&head, getNode(50));
	push(&head, getNode(1));
	push(&head, getNode(45));
	
	int k = 3;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of 
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);

	return 0;
}
