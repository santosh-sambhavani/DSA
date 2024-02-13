//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
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

int main() {
      string s; 
     getline(cin, s);
     Node* root = buildTree(s);
  
    // getline(cin, s);
     
      cout << findMedian(root) << endl;
  
    // cout<<"~"<<endl;
  
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

float findMedian(struct Node *root)
{
    int n = 0;
    queue<struct Node*> q;
    
    q.push(root);
    while(!q.empty()) {
        struct Node* curr = q.front();
        n++;
        if (curr->left) {
            q.push(curr->left);
        } 
        
        if (curr->right) {
            q.push(curr->right);
        }
        q.pop();
    }
    
    int index = 0;
    struct Node* curr = root;
    struct Node* prev = NULL;
    while(curr) {
        if (!curr->left) {
            index++;
            if (index == n/2+1) {
                break;
            }
            prev = curr;
            curr = curr->right;
        } else {
            struct Node* pred = curr->left;
            while(pred->right && pred->right != curr) {
                pred = pred->right;
            }
            if (pred->right) {
                pred->right = NULL;
                index++;
                if (index == n/2+1) {
                    break;
                }
                prev = curr;
                curr = curr->right;
            } else {
                pred->right = curr;
                curr = curr->left;
            }
        }
    }
    
    double median = 0;
    if (n&1) {
        median = curr->data;
    } else {
        median = (1.0*curr->data + 1.0*prev->data)/ 2;
    }
    
    return median;
}
/*
13 10 18 3 11 15 20 1 6 N 12

13 10 18 3 11 15 20 1 6

Here used morris traversal for SC O(1)
*/

