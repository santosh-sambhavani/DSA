//{ Driver Code Starts
// driver code

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

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

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

*/

class Solution
{
    private:
    /*
    * this is floydd's cycle detetction algo code which is actually to check if loop exists
    * here we use it to find node where slow & fast meets to confirm cycle's existance
    */
    Node* getIntersectionNode(Node* head)
    {
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

    /*
    * After getting the intersection point we can find last node of loop or first node of loop
    * we can start traversing from head of LL & intersection point And at some point both meets at some node
    * because distance of head w.r.t loop's first node  = (distance of intersection node w.r.t loop's first node + 1)
    * https://www.youtube.com/watch?v=VxOFflTXlXo&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=52&t=1715s    
    */
    Node* findLastNode(Node* head)
    {
        Node* intersectionNode = getIntersectionNode(head);
        if(!intersectionNode) {
            return NULL;
        }
        Node* temp = head;
        while(temp != intersectionNode->next) {
            temp = temp->next;
            intersectionNode = intersectionNode->next;
        }
        /*
        * and now
        * temp = first node of cycle
        * intersectionNode = last node of cycle
        */
        return intersectionNode; 
    }
    
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* lastNode = findLastNode(head);
        if(!lastNode) return;
        lastNode->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
      unordered_map<Node *, int>myMap;
      
      int n, num;
      cin>>n;
      
      Node *head, *tail;
      cin>> num;
      head = tail = new Node(num);
      
      myMap[head]=num;
      
      for(int i=0 ; i<n-1 ; i++)
      {
          cin>> num;
          tail->next = new Node(num);
          tail = tail->next;
          myMap[tail]=num;
      }
      
      int pos;
      cin>> pos;
      loopHere(head,tail,pos);
      
      Solution ob;
      ob.removeLoop(head);
      
      if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
          cout<<"0\n";
      else
          cout<<"1\n";
}

// } Driver Code Ends
