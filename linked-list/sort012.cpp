/*
* This problem has two approach:
* App 1: First one is to count all 0s 1s & 2s And add into new list as per the count
* App 2: And second approach is to create three separate lists for each 0s 1s & 2s
*   Then merge all 3 lists. this approach is useful when interviewer asks for sorting w/o data replacement
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    private:
    void insertAtTail(Node* &tail, Node* &head, int data) {
        if(head == NULL) {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
            return;
        } 
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
    
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head->next == NULL) 
            return head;
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        Node* current = head;
        
        while(current != NULL) {
            if(current->data == 0) {
                insertAtTail(zeroTail, zeroHead, current->data);
            } else if(current->data == 1) {
                insertAtTail(oneTail, oneHead, current->data);
            } else if(current->data == 2) {
                insertAtTail(twoTail, twoHead, current->data);
            }
            current = current -> next;
        }
        
        if(oneHead->next == NULL) {
            zeroTail->next = twoHead->next;    
        } else {
            zeroTail->next = oneHead->next;
            oneTail->next = twoHead->next;
        }
        Node* returnHead = zeroHead->next;
        
        zeroHead->next = NULL;
        oneHead->next = NULL;
        twoHead->next = NULL;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return returnHead;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    insert(n);
    Solution ob;
    struct Node *newHead = ob.segregate(start);
    printList(newHead);
  
    return 0;
}
// } Driver Code Ends
