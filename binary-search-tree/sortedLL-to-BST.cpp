//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  private: 
    LNode* findMiddle(LNode* head) {
        LNode* fast = head->next; 
        LNode* slow = head;
        LNode* pre = NULL;
        
        while(fast) {
            pre = slow;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            slow = slow->next;
        }
        
        if (pre != NULL) {
            pre->next = NULL;
        }
        
        return slow;
    }
  public:
    TNode* sortedListToBST(LNode *head) {
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            TNode* root = new TNode(head->data);
            return root;
        }
        
        LNode* midNode = findMiddle(head);
        TNode* root = new TNode(midNode->data);
        
        root->left = sortedListToBST(head);
        
        root->right = sortedListToBST(midNode->next);
        
        return root;
    }
};



int main() 
{ 
      int n;
      cin>>n;

      int data;
      cin>>data;
      LNode *head = new LNode(data);
      LNode *tail = head;
      for (int i = 0; i < n-1; ++i)
      {
          cin>>data;
          tail->next = new LNode(data);
          tail = tail->next;
      }
      Solution ob;
      TNode* Thead = ob.sortedListToBST(head);
      preOrder(Thead);
      cout<<"\n";
      return 0;
}

/*
7
1 2 3 4 5 6 7

8
1 2 3 4 5 6 7 8

*/
