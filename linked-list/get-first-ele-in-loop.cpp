//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{   
    private:
    Node* getIntersectionNode(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast)
                return slow;
        }
        return NULL;
    }
    
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        Node* intersectionNode = getIntersectionNode(head);
        if(!intersectionNode) {
            return -1;
        }
        Node* temp = head;
        while(temp != intersectionNode->next) {
            temp = temp->next;
            intersectionNode = intersectionNode->next;
        }
        return temp->data;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, num;
    cin>>n;
    
    Node *head, *tail;
    cin>> num;
    head = tail = new Node(num);
    
    for(int i=0 ; i<n-1 ; i++)
    {
        cin>> num;
        tail->next = new Node(num);
        tail = tail->next;
    }
    
    int pos;
    cin>> pos;
    loopHere(head,tail,pos);
    
    Solution ob;
    int ans = ob.findFirstNode(head);
    cout<<ans<<"\n";
	  return 0;
}
// } Driver Code Ends
