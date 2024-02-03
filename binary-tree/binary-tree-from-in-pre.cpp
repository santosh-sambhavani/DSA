/*
https://www.geeksforgeeks.org/problems/construct-tree-1/1

6
3 1 4 0 5 2
0 1 3 4 2 5

Simple logic was to find element of pre order traversal in inOrder
& solve it recursively by taking left part in inorder 
  for the same element as left child & right part of inOrder as right child
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
        Node* solve (int *in, int *pre, int start, int end, int &index) {
            if(start > end) {
                return NULL;
            }
            int element = pre[index++];
            Node* root = new Node(element);
            int pos = start;
            while(pos <= end) {
                if (element == in[pos])
                    break;
                pos++;
            }
            
            root->left = solve(in, pre, start, pos-1, index);
            root->right = solve(in, pre, pos+1, end, index);
            
            return root;
        }
        
    public:
        Node* buildTree(int in[],int pre[], int n) {
            int index = 0;
            return solve(in,pre,0, n-1, index);
        }
};

//{ Driver Code Starts.
int main()
{
  int n;
  cin>>n;
  
  int inorder[n], preorder[n];
  for(int i=0; i<n; i++)
    cin>> inorder[i];
  for(int i=0; i<n; i++)
    cin>> preorder[i];
  Solution obj;
  Node *root = obj.buildTree(inorder, preorder, n);
  printPostOrder(root);
  cout<< endl;
}

// } Driver Code Ends
