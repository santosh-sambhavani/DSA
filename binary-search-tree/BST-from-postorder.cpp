/*
22
134 37 369 334 304 249 499 190 530 568 747 649 755 754 809 529 891 959 909 873 869 843

the logic is simple if current data is in given range than return node by creating node from it.
other wise return null;
just start from right, in preorder problem we use left first to check compare both problem for more understanding
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
  scanf("%d",&n);
  int post[n];
  for(int i=0;i<n;i++)
  scanf("%d",&post[i]);

  Node* root = constructTree(post, n);

  printInorder(root);
  printf("\n");
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
Node* solve(int post[], int &index, int min, int max) {
    if (index < 0) {
        return NULL;
    }
    
    int data = post[index];
    if (data < min || data > max) {
        return NULL;
    }
    
    Node* root = new Node(data);
    index--;
    root->right = solve(post, index, data, max);
    root->left = solve(post, index, min, data);
    
    return root;
}

Node *constructTree (int post[], int size)
{
    int index = size-1;
    return solve(post, index, INT_MIN, INT_MAX);
}
