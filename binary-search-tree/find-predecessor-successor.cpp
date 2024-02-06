//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(!root) {
            return ;
        }
        
        findPreSuc(root->left, pre, suc, key);
        
        if (suc) {
            return ;
        }
        if (root->key < key) {
            pre = root;
        } else if (root->key > key) {
            suc = root;
            return ;
        }
        
        findPreSuc(root->right, pre, suc, key);
    }
};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    Node *pre=NULL,*succ=NULL;
    Solution ob;
    ob.findPreSuc(root,pre,succ,k);
    (pre!=NULL)?cout<<pre->key:cout<<-1;
    cout<<" ";
    (succ!=NULL)?cout<<succ->key:cout<<-1;
    cout<<endl;
    // inOrderTraversal(root);
   return 0;
}
/*
10 2 11 1 5 N N N N 3 6 N 4
8

Logic is simply do inoreder traversal when ever we get greater value than key till that point of time
if we have predecessor we would got that & successor would be the greater value we visited if exists
Using same logic we can find only predecessor or successor
*/
// } Driver Code Ends
