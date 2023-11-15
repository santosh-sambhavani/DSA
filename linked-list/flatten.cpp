//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* insertAtTail(Node* &tail, Node* head, int data) {
    Node* temp = new Node(data);
    if(head == NULL) {
        head = temp;
        tail = head;
        return head;
    }
    tail->bottom = temp;
    tail = temp;
    return head;
}
    
Node* merge(Node* root1, Node* root2) {
    if(!root1) return root2;
    if(!root2) return root1;
    Node* merged = NULL;
    Node* tail = NULL;
    while(root1 && root2) {
        if(root1->data < root2->data) {
            merged = insertAtTail(tail, merged, root1->data);
            root1 = root1->bottom;
        } else {
            merged = insertAtTail(tail, merged, root2->data);
            root2 = root2->bottom;
        }
    }
    
    while(root1) {
        merged = insertAtTail(tail, merged, root1->data);
        root1 = root1->bottom;
    }
    
    while(root2) {
        merged = insertAtTail(tail, merged, root2->data);
        root2 = root2->bottom;
    }
    
    return merged;    
}

void print(Node* head) {
      Node* temp = head;
    while(temp) {
        cout << " " << temp->data;
        temp = temp -> next;
    }
}

Node *flatten(Node *root)
{
    if(root == NULL) return NULL;
    
    Node* left = root;
    Node* right = root->next ? flatten(root->next) : NULL;
    root->next = NULL;
  
    // cout << " \n left: ";
    // print(left);
    // cout << " \n right: ";
    // print(right);
  
    return merge(left, right);
}

/*
4 
4 1 3 1
5 7 8 30 10 19 22 50 28
*/
