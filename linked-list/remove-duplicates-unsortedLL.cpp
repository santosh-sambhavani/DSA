//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

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
    public:
    //Function to remove duplicates from unsorted linked list.
    /*
    * Here approach using map implemented with TC=O(N) SC=O(N)
    * approach 2 = naive way fix pointer to one node check all other nodes in LL if matched remove that node TC=O(N^2) SC=O(1)
    * approach 3 = sort linked list & apply rmeove suplicates from sorted LL
    */
    Node * removeDuplicates( Node *head) 
    {
        map<int, bool> visited;
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL) {
            if(visited[temp->data]) {
                Node* nodeToDelete = temp;
                prev->next = nodeToDelete->next;
                temp = temp->next;
                delete nodeToDelete;
            } else {
                visited[temp->data] = true;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
	int K;
  cin>>K;
  struct Node *head = NULL;
      struct Node *temp = head;

  for(int i=0;i<K;i++){
  int data;
  cin>>data;
    if(head==NULL)
    head=temp=new Node(data);
    else
    {
      temp->next = new Node(data);
      temp=temp->next;
    }
  }
  
    Solution ob;
  Node *result  = ob.removeDuplicates(head);
  print(result);
  cout<<endl;
  
  return 0;
}
// } Driver Code Ends
