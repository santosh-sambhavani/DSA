#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
class Solution{
    private:
    Node* insertAtTail(Node* &tail, Node* head, int data) {
        Node* temp = new Node(data);
        if(head == NULL) {
            head = temp;
            tail = head;
            return head;
        }
        tail->next = temp;
        tail = temp;
        return head;
    }

    Node* merge(Node* root1, Node* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        Node* merged = NULL;
        Node* tail = NULL;
        while(root1 && root2) {
            if(root1->data < root2->data) {
                merged = insertAtTail(tail, merged, root1->data);
                root1 = root1->next;
            } else {
                merged = insertAtTail(tail, merged, root2->data);
                root2 = root2->next;
            }
        }
        
        while(root1) {
            merged = insertAtTail(tail, merged, root1->data);
            root1 = root1->next;
        }
        
        while(root2) {
            merged = insertAtTail(tail, merged, root2->data);
            root2 = root2->next;
        }
        
        return merged;    
    }
    
    Node* getMid(Node* head) {
        if(head == NULL) {
            return head;
        }
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        return slow;
    }
    
    public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // cout << "\n=========> " << head->data;
        Node* mid = getMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        // cout << "\n left: ";
        // printList(left);
        // cout << "right: ";
        // printList(right);
        
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* merged = merge(left, right);
        // cout << "\n merged: ";
        // printList(merged);
        return merged;
    }
};


//{ Driver Code Starts.



void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
    return 0;
}
