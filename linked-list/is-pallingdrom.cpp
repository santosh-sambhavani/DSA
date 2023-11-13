/*
* Approach here is to reverse linked list from mid & 
* check from head & mid after that if any node is mismatched or not
*/

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    private: 
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    
    Node* reverse(Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = head->next;
        
        while(curr != NULL) {
            curr->next = prev;
            
            prev = curr;
            curr = forward;
            forward = forward ? forward->next : NULL;
        }
        
        return prev;
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL) {
            return true;
        }
        Node* mid = getMid(head);
        mid->next = reverse(mid->next);
        
        Node* p1 = head;
        Node* p2 = mid->next;
        
        while(p1 != mid->next && p2 != NULL) {
            if(p1->data != p2->data) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};


//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T,i,n,l,firstdata;   
    struct Node *head = NULL,  *tail = NULL;
    cin>>n;
    // taking first data of LL
    cin>>firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for(i=1;i<n;i++)
    {
        cin>>l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    Solution obj;
    cout<<obj.isPalindrome(head)<<endl;
    return 0;
}


// } Driver Code Ends
